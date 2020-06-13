C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
OBJ = ${C_SOURCES:.c=.o}
CC = i386-elf-gcc
LD = i386-elf-ld
EMU = qemu-system-i386
ASM = nasm

os-image: boot/boot_sec.bin kernel/kernel.bin
	cat $^ > os-image

kernel/kernel.bin: kernel/entry.o ${OBJ}
	$(LD) -o $@ -Ttext 0x1000 $^ --oformat binary

%.o: %.c 
	$(CC) -ffreestanding -c $< -o $@

%.o: %.asm
	$(ASM) $< -f elf -o $@

%.bin: %.asm 
	$(ASM) $< -f bin -o $@;

emu: os-image
	$(EMU) -fda os-image

clean:
	rm -rf os-image 
	rm -rf boot/*.bin
	rm -rf kernel/*.o kernel/*.bin
	rm -rf drivers/*.o 