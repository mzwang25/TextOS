os-image:
	cd boot; \
	  make -f boot.mk boot_sec.bin
	cd kernel; \
	  make -f kernel.mk kernel.bin
	cat boot/boot_sec.bin kernel/kernel.bin > os-image

emu:
	make os-image
	qemu-system-i386 -fda os-image

clean:
	cd boot; \
	  make -f boot.mk clean
	cd kernel; \
	  make -f kernel.mk clean
	rm os-image

