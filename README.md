## OS
I'm going to try my best to do an OS <br/>
http://www.jamesmolloy.co.uk/tutorial_html/6.-Paging.html <br/>
https://wiki.osdev.org/Main_Page <br/>
https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf <br/>
https://www.cs.cmu.edu/~410-s07/p4/p4-boot.pdf <br/>
https://www.cs.cmu.edu/~410/ <br/>
https://stackoverflow.com/questions/1789594/how-do-i-write-the-cd-command-in-a-makefile
http://pages.cs.wisc.edu/~remzi/OSTEP/vm-segmentation.pdf

### Info
#### Booting
Boot/ contains most of the boot process. In 16-bit real 
mode, it sets the stack to 0x8000. Then it prints "Boot 
Sector Loaded!" and then attempts to load the kernel. Load
kernel loads X number of 512-byte segments into memory at 
KERNEL_OFFSET. Next it loads the gdt. The gdt contains two
segments (code and data). They both have base 0x0 and max 
segment length. There really isn't a use for segments yet.
After loading and changing the cr0 register, a far jump is 
taken to init_pm. Init_pm is in 32-bit protected mode. It 
then updates the segment registers for the entries in the
GDT. Next stack is updated to 0x90000 since we're in 
32 bit mode. Finally it calls BEGIN_PM. BEGIN_PM calls
KERNEL_OFFSET. <br/>

KERNEL_OFFSET is where the kernel code was loaded. This 
code is located in kernel/entry.asm. And all this does is it 
calls the main function. This is the entry point into
the kernel code

#### Kernel
Need to make sure entire kernel code is loaded into memory or weird stuff happens. To change
number of disk sectors to load, change line 7 of load_kernel. Each sector is 512 bytes and to 
check number of bytes of kernel, use <code> wc -c kernel/kernel.bin</code>.
Paging would be awesome once that's implemented.

#### Makefile
Pretty Bad I gotta fix it

#### Tools
sudo apt-get install qemu-kvm qemu virt-manager virt-viewer libvirt-bin <br/>
sudo apt install nasm
qemu-system-x86\_64 [file] <br/>
nasm -f [ams] -o [ofile] <br/>
xxd (examine bin files) <br/>
objdump -d or -D
ndisasm

#### Cross-Compiler
https://wiki.osdev.org/GCC_Cross-Compiler <br/>
sudo apt install libgmp3-dev libmpfr-dev libmpc-dev <br/>
Instructions in installcc.sh <br/>

##### Other
Registers cs, ds, ss, and es specifies the offset for accessing memory. They refer to 
code, data, stack, and user-defined. 

