# How this finding was reached

`nmgms.sys` came out of the DeepZero run flagged as vulnerable, with the automated
assessment naming `\\.\nmgms` as the way in. Reading `DriverEntry` and `AddDevice`
showed that name is wrong: the control device `\Device\nmgms` is created in
`DriverEntry`, but its `\DosDevices\nmgms` symbolic link is created only in
`AddDevice`, which runs only when the NMgaming mouse is present. A proof of concept
using `\\.\nmgms` fails on a machine without the mouse. The device is instead opened
through the object namespace at `\\?\GLOBALROOT\Device\nmgms`, which reaches the
`DriverEntry`-created device with no hardware. Every conclusion below was then
verified on the VM.

1. **The two defects were separated by copy direction.** The dispatch has many
   `RtlCopyMemory` calls. Those with the fixed stack buffer `uStack_438` as the
   destination and `InputBufferLength` as the size are the overflow; the single
   call with `SystemBuffer` as the destination and `OutputBufferLength` as the size
   (control code `0x00222554`, source a one-byte `.data` global) is the disclosure.

2. **The overflow is not gated by the hardware flag.** The driver has a
   `DAT_000123e0` flag written only in its PnP handler (the same pattern that makes
   the ROCCAT `*Fltr` drivers reachable only with their hardware). Here it does not
   help the vendor: disassembly shows the `RtlCopyMemory` into the stack buffer runs
   **before** the flag is tested (copy at `nmgms+0x11588`, flag test at
   `nmgms+0x1158e`), and the disclosure handler tests no flag at all, so both
   defects are reachable with the flag clear.

3. **The frame geometry was read from the prologue.** Seven pushes (`0x38`) plus
   `sub rsp,0x430`, buffer at `rsp+0x30`, and no `/GS` cookie in the epilogue, so
   the saved return address is at input offset `0x438`.

4. **The disclosure was confirmed** by the unprivileged account `dzuser` reading
   `0x300` bytes from control code `0x00222554` and receiving kernel pointers,
   including the driver's image base (`nmgms + 0x590`) and a non-paged pool object,
   with no effect on the machine. Because the read starts at an unaligned address,
   the pointers appear at unaligned output offsets, which the proof of concept
   accounts for by scanning every byte position.

5. **The overflow was confirmed** by the same account sending `0x440` bytes to
   control code `0x00222550` with `0x00007FFF0000DEAD` at offset `0x438`, producing
   a bug check with that value as the faulting instruction address and
   `AV.Type: Execute`.

6. **Weaponisation was scoped honestly.** Unlike the Lycosa and Protype findings,
   this driver's disclosure returns its own image base and a pool object but not the
   base of `ntoskrnl.exe`, and it has no arbitrary-read primitive and no outbound
   copy of its stack, so the kernel base cannot be recovered from `nmgms.sys` alone
   and a self-contained `ZwCreateFile` chain was not built. The instruction-pointer
   control and the address disclosure are each real and each confirmed; combining
   them into code execution requires a kernel-base leak from another driver.

Testing was on Windows 11 build 26100.8875 with code integrity enforced and test
signing off, both confirmed with `bcdedit`. The driver was installed from its own
catalog-signed package (`nmgms.inf` with `nmgms64.cat`) and loaded under enforced
signing, and the account used (`dzuser`) is in the `Users` group only, at Medium
integrity.

## Prior art

Not in LOLDrivers (660 entries, by SHA-256, MD5 and name). Not on the Microsoft
vulnerable driver blocklist (by hash and name). No CVE found.

## What was not done

No privilege-granting payload was built; the overflow was demonstrated to the point
of instruction-pointer control only. Only this build was examined.
