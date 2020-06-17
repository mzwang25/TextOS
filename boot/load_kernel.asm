[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print_string 

    mov bx, KERNEL_OFFSET 
    mov dh, 20 ; 20 512-byte segments
    mov dl, [BOOT_DRIVE]
    call disk_load
    ret

MSG_LOAD_KERNEL:
    db 'Loading Kernel from disk', 0xa, 0xd, 0