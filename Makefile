os-image: kernel/kernel.bin boot/boot_sec.bin
	cat boot/boot_sec.bin kernel/kernel.bin > os-image

kernel/kernel.bin: kernel/kernel.o kernel/entry.asm
	cd kernel; \
      nasm entry.asm -f elf -o entry.o; \
	  i386-elf-ld -Ttext 0x1000 entry.o kernel.o --oformat binary -o kernel.bin

kernel/kernel.o: kernel/kernel.c
	cd kernel; \
   	  i386-elf-gcc -ffreestanding -c kernel.c -o kernel.o


boot/boot_sec.bin: boot/boot_sec.asm boot/print.asm boot/read_disk.asm boot/32bit-print.asm boot/32bit-switch.asm boot/32bit-gdt.asm
	cd boot; \
	  nasm -f bin boot_sec.asm -o boot_sec.bin

emu: os-image
	qemu-system-i386 -fda os-image

clean:
	cd boot; \
	  make -f boot.mk clean
	cd kernel; \
	  make -f kernel.mk clean
	rm -rf os-image

