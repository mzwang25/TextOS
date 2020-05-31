boot_sec.bin: boot_sec.asm
	nasm -f bin $< -o $@

test: boot_sec.bin 
	qemu-system-x86_64 $<