

# for github actions and easier building i suppose
CXX = clang++
LINKER = ld.lld
FLAGS = --target=x86_64-unknown-none-elf -std=c++20 -O2 -ffreestanding -fno-exceptions -fno-rtti -fno-builtin -fno-stack-protector -fno-pic -mcmodel=kernel -mno-red-zone -mno-80387 -mno-mmx -mno-sse -mno-sse2
ifeq ($(OS),Windows_NT)
XORRISO = $(USERPROFILE)/scoop/apps/msys2/current/usr/bin/xorriso.exe 
LIMINE = limine-binary/limine-tool-windows-x86/limine.exe
COPY = copy /Y sleemos iso_root\boot
rm = del /Q
else
	COPY = cp sleemos iso_root/boot/
    XORRISO = xorriso
    LIMINE = ./limine-binary/limine
	rm = rm -f
endif

all: SleemOS.iso

strcmp.o: src/strcmp.cpp
	$(CXX) $(FLAGS) -c src/strcmp.cpp -o strcmp.o

shal.o: src/shal.cpp
	$(CXX) $(FLAGS) -c src/shal.cpp -o shal.o

kernel.o: src/kernel.cpp
	$(CXX) $(FLAGS) -c src/kernel.cpp -o kernel.o

sleemint.o: src/sleemint.cpp
	$(CXX) $(FLAGS) -c src/sleemint.cpp -o sleemint.o

sleemfs.o: src/sleemfs.cpp
	$(CXX) $(FLAGS) -c src/sleemfs.cpp -o sleemfs.o

badapple.o: src/badapple.cpp
	$(CXX) $(FLAGS) -c src/badapple.cpp -o badapple.o

sleemos: kernel.o strcmp.o sleemfs.o sleemint.o badapple.o shal.o linker.ld
	$(LINKER) kernel.o shal.o strcmp.o sleemfs.o sleemint.o badapple.o -o sleemos -static -nostdlib -z max-page-size=0x1000 -T linker.ld

SleemOS.iso: sleemos
	$(COPY)
	$(XORRISO) -as mkisofs -R -r -J -b boot/limine/limine-bios-cd.bin -no-emul-boot -boot-load-size 4 -boot-info-table -hfsplus -apm-block-size 2048 --efi-boot boot/limine/limine-uefi-cd.bin -efi-boot-part --efi-boot-image --protective-msdos-label iso_root -o SleemOS.iso
	$(LIMINE) bios-install SleemOS.iso
clean:
	$(rm) *.o sleemos *.iso *.d

-include *.d 