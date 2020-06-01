## MichaelOS
I'm going to try my best to follow through this for an OS <br/>
https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf

### Dev
##### Installation
sudo apt-get install qemu-kvm qemu virt-manager virt-viewer libvirt-bin <br/>
sudo apt install nasm
##### Usage
qemu-system-x86\_64 [file] <br/>
nasm -f [ams] -o [ofile] <br/>
xxd (examine bin files) <br/>

##### Other
Registers cs, ds, ss, and es specifies the offset for data. They refer to 
code, data, stack, and user-defined. 

