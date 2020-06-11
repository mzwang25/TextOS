## MichaelOS
I'm going to try my best to follow through this for an OS <br/>
https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf <br/>
https://www.cs.cmu.edu/~410-s07/p4/p4-boot.pdf <br/>
https://www.cs.cmu.edu/~410/
https://stackoverflow.com/questions/1789594/how-do-i-write-the-cd-command-in-a-makefile

### Info
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

