boot_sec.bin: boot_sec.asm print.asm read_disk.asm 32bit-print.asm 32bit-switch.asm 32bit-gdt.asm
	nasm -f bin $< -o $@

clean:
	rm -rf boot_sec.bin