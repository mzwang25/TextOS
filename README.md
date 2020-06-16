## OS
I'm going to try my best to do an OS <br/>
https://wiki.osdev.org/Main_Page <br/>
https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf <br/>
https://www.cs.cmu.edu/~410-s07/p4/p4-boot.pdf <br/>
https://www.cs.cmu.edu/~410/ <br/>
https://stackoverflow.com/questions/1789594/how-do-i-write-the-cd-command-in-a-makefile
http://pages.cs.wisc.edu/~remzi/OSTEP/vm-segmentation.pdf

### Info

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

