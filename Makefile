C_SOURCES = $(wildcard kernel/*.c drivers/*.c mlib/*.c cpu/*.c)
OBJ = ${C_SOURCES:.c=.o}
CC = i386-elf-gcc
LD = i386-elf-ld
EMU = qemu-system-i386
ASM = nasm
GDB = i386-elf-gdb
CFLAGS = -g

os-image: boot/boot_sec.bin kernel/kernel.bin
	cat $^ > os-image

kernel/kernel.bin: kernel/entry.o ${OBJ}
	$(LD) -o $@ -Ttext 0x1000 $^ --oformat binary

kernel/kernel.elf: kernel/entry.o ${OBJ}
	$(LD) -o $@ -Ttext 0x1000 $^

%.o: %.c 
	$(CC) $(CFLAGS) -ffreestanding -c $< -o $@

%.o: %.asm
	$(ASM) $< -f elf -o $@

%.bin: %.asm 
	$(ASM) $< -f bin -o $@;

emu: os-image
	$(EMU) -fda os-image
	
debug: os-image kernel/kernel.elf
	qemu-system-i386 -s -S -fda os-image &
	$(GDB) -ex "target remote localhost:1234" -ex "symbol-file kernel/kernel.elf"

clean:
	rm -rf os-image
	rm -rf boot/*.bin
	rm -rf kernel/*.o kernel/*.bin
	rm -rf drivers/*.o 
