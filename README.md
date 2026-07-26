# nmgms.sys (Waytech / NMgaming mouse) - two kernel defects reachable by any user

`nmgms.sys` is the filter driver in Waytech's NMgaming mouse package. It creates a
control device that any logged-in account can open, and that device exposes two
distinct defects, both confirmed on a live Windows 11 machine by an unprivileged
account with no vendor hardware attached:

- **[CVE-01, kernel memory disclosure](CVE-01-kernel-memory-disclosure/README.md).**
  An IOCTL copies out of the driver's `.data` using a caller-supplied length,
  over-reading adjacent memory and returning kernel pointers, including the
  driver's own image base. Defeats KASLR for this module. No crash.
- **[CVE-02, kernel stack buffer overflow](CVE-02-kernel-stack-overflow/README.md).**
  An IOCTL copies the caller's input into a fixed 0x438-byte stack buffer using the
  caller's own length, with no bound and no `/GS` stack cookie, giving control of a
  kernel-mode return address. Confirmed by a bug check whose faulting instruction
  address was the value supplied by an unprivileged process.

| Field | Value |
|---|---|
| File name | `nmgms.sys` |
| Size | 14,592 bytes |
| SHA-256 | `47ec68ae534ccd5695ddd80e45866d0a207359db0098deeac6ae04ca7f8b34aa` |
| MD5 | `860101e48e9de6ffdd1f18c946a94e39` |
| Architecture | x64 (AMD64) |
| Image base | `0x10000` |
| Link timestamp | 2009-11-13 |
| Vendor / provider | Waytech (`%WAYTECH%` in the INF); NMgaming mouse, USB\VID_04D9&PID_A04A |
| Package | `nmgms.inf` with `nmgms64.cat`, catalog-signed (loads on Windows 11 under enforced code integrity) |

## Reachability

`DriverEntry` creates `\Device\nmgms` with `IoCreateDevice` (VA `0x130C7`) and **no
security descriptor**, so it receives the I/O manager default DACL and opens for any
account. Its `IRP_MJ_CREATE` handler returns `STATUS_SUCCESS`. Every affected
control code is `METHOD_BUFFERED`, `FILE_ANY_ACCESS`.

Its symbolic link `\DosDevices\nmgms` (which would give `\\.\nmgms`) is created
**only in `AddDevice`** (VA `0x1298A`), which runs only when the physical NMgaming
mouse is attached. With no hardware the link does not exist, but the control device
does, so it is opened through the object namespace at
**`\\?\GLOBALROOT\Device\nmgms`**. This is the detail the automated assessment got
wrong: it named `\\.\nmgms`, which fails on a machine without the mouse; the
`GLOBALROOT` form reaches the same device with no hardware.

## What was demonstrated on the VM

On Windows 11 Pro build 26100.8875, x64, code integrity enforced and test signing
off (both confirmed with `bcdedit`), the driver installed from its own catalog
package and loaded (`sc start` succeeded under enforced signing). Everything below
was then run from the standard account `dzuser` (group `Users` only, Medium
integrity):

- **CVE-01:** control code `0x00222554` returned kernel pointers to the caller,
  including `nmgms + 0x590` (the driver's image base plus a fixed offset) and a
  non-paged pool object pointer. Logged in
  [`logs/dzuser_leak_run.txt`](logs/dzuser_leak_run.txt). No effect on the machine.
- **CVE-02:** control code `0x00222550` with `0x440` input bytes carrying
  `0x00007FFF0000DEAD` at offset `0x438` produced `KMODE_EXCEPTION_NOT_HANDLED`
  with that exact value as the faulting instruction address and `AV.Type: Execute`.
  Dump in
  [`CVE-02-kernel-stack-overflow/evidence/dumps/nmgms_overflow.dmp`](CVE-02-kernel-stack-overflow/evidence/dumps/nmgms_overflow.dmp).

## Impact and the limit of what one driver gives

An unprivileged local user obtains, in one driver, both a defeat of this module's
KASLR and full control of a kernel-mode instruction pointer. That is a critical
local privilege escalation primitive.

Turning it into arbitrary code execution needs the base of `ntoskrnl.exe` for
gadgets and for `nt!ZwCreateFile`. This driver's disclosure returns its own image
base and a kernel pool object, not the kernel base, and it has no arbitrary-read
primitive and no outbound copy of its stack, so the kernel base cannot be recovered
from `nmgms.sys` alone. Reliable code execution therefore pairs CVE-02 with a
kernel-base disclosure from any driver that offers one. Both defects here are independently real and independently
confirmed; the pairing note concerns weaponisation, not whether the defects exist.

## Contents

```
README.md                                    this overview
METHODOLOGY.md                               how the finding was reached and verified
poc/nmgms_probe.rs                           combined proof of concept (--leak / --overflow)
CVE-01-kernel-memory-disclosure/             the disclosure, standalone
CVE-02-kernel-stack-overflow/                the overflow, standalone
evidence/nmgms.sys, nmgms.inf, nmgms64.cat   the affected binary and its package
evidence/decompiled/                         decompiled dispatch and entry
evidence/dumps/nmgms_overflow.dmp            the return-address overwrite
logs/dzuser_leak_run.txt                     the disclosure as an unprivileged user
```

## Prior art

Not in LOLDrivers (searched by SHA-256, MD5 and name). Not on the Microsoft
vulnerable driver blocklist by hash or name. No CVE found. Believed previously
unreported.
