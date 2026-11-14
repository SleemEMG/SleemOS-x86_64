<img width="300" alt="logo" src="https://github.com/user-attachments/assets/aeda8863-122e-4860-8861-c1745ba76f9a" />


# SleemOS x86_64
> SleemOS x86_64/AMD64 is an OS written in CPP, or rather a port of https://github.com/SleemEMG/SleemOS-STM to AMD64, albeit it'll become more independent as more features are added. Some features like SleemFS/SleemInt are missing and will be added accordingly.
<br>

> The reason I made this is because I wanted to experiment with GPUs and have a more... standardized platform than a random STMicroelectronics MCU.
## Support

x86_64 CPU, RA- ok basically an AMD64 computer OR qemu.


## Building

Install the following packages :-
* g++/llvm
* xorriso

Download :-
* limine binary (extract this into the repo as limine-binary)


And then run the following (for example, changes depending on your compiler choice etc.) :-
```POWERSHELL
git clone https://github.com/SleemEMG/SleemOS-x86_64
cd SleemOS-x86_64
clang++ --target=x86_64-unknown-none-elf -c src\kernel.cpp -o kernel.o -std=c++20 -O2 -ffreestanding -fno-exceptions -fno-rtti -fno-builtin -fno-stack-protector -fno-pic -mcmodel=kernel -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2
clang++ --target=x86_64-unknown-none-elf -c src\shal.cpp -o shal.o -std=c++20 -O2 -ffreestanding -fno-exceptions -fno-rtti -fno-builtin -fno-stack-protector -fno-pic -mcmodel=kernel -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2
clang++ --target=x86_64-unknown-none-elf -c src\strcmp.cpp -o strcmp.o -std=c++20 -O2 -ffreestanding -fno-exceptions -fno-rtti -fno-builtin -fno-stack-protector -fno-pic -mcmodel=kernel -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2
ld.lld kernel.o shal.o strcmp.o -o sleemos -static -nostdlib -z max-page-size=0x1000 -T linker.ld
```
> [!WARNING]
> These are clang only commands.
Copy limine-bios.sys, limine-bios-cd.bin and limine-uefi-cd.bin into iso_root/boot/limine/ and BOOTX64.EFI INTO iso_root/EFI/BOOT/.
```POWERSHELL
copy sleemos iso_root\boot\ -Force
xorriso -as mkisofs -R -r -J -b boot/limine/limine-bios-cd.bin -no-emul-boot -boot-load-size 4 -boot-info-table -hfsplus -apm-block-size 2048 --efi-boot boot/limine/limine-uefi-cd.bin -efi-boot-part --efi-boot-image --protective-msdos-label iso_root -o sleemos.iso
limine-binary\limine-tool-windows-x86\limine.exe bios-install sleemos.iso
qemu-system-x86_64 -cdrom sleemos.iso
```


> The above produces sleemos.iso which is the built ISO. (buttered butter)

## Testing locally

Install the following software :-
* qemu

Download sleemos.iso from Releases or compile (see above).
And then open your terminal and type in, for example:

```
qemu-system-x86_64 -cdrom sleemos.iso
```

You do not need to download any other files.

## Features
SleemOS has a shell, keyboard through IDT and commands like: `help, neofetch, clear, uptime, echo, write (SleemFS, TEMPORARILY NOT IN OS), touch (SleemFS, TEMPORARILY NOT IN OS), cat (SleemFS, TEMPORARILY NOT IN OS), ls (SleemFS, TEMPORARILY NOT IN OS), rm (SleemFS, TEMPORARILY NOT IN OS), edit (SleemFS, TEMPORARILY NOT IN OS), panik, reboot, run (SleemInt x86_64, TEMPORARILY NOT IN OS), hexdump (SleemFS, TEMPORARILY NOT IN OS), badapple (TEMPORARILY NOT IN OS)`


## Credits
* **Trao-X** - For improving the clarity of the README.
* **zalanwastaken** - For writing the README.

## Licenses used: 
* MIT (SleemOS x86_64, embedded artistry's strcmp, the font that I forgot the name of)
* BSD-2 (Limine)
* 0BSD (limine.h)
