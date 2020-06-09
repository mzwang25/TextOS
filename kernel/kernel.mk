kernel.bin: kernel.o
	i386-elf-ld -Ttext 0x1000 $< --oformat binary -o $@

kernel.o: kernel.c
	i386-elf-gcc -ffreestanding -c $< -o $@

clean:
	rm kernel.bin kernel.o