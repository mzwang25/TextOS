; Global Offset 0x7c00 (where boot sector starts)
[org 0x7c00]

; The bootsector is 512 bytes and must end with word 0xaa55
; Operates in 16-bit mode


; Set the stack
mov bp, 0x8000
mov sp, bp

; Print Bootsector Msg
mov bx, intro
call print_string

; Print Boot address
mov dh, 0x0
mov bx, boot_drive_msg
call print_string
call print_hex
mov bx, nlcr
call print_string

; Read Disk: Move 5 sectors to 0(es):0x9000(bx)
mov bx, 0x9000 
mov dh, 5
call disk_load

; Whatever was read is now in bx
mov dx, bx ; Now it's in dx
mov bx, disk_read_success
call print_string
mov bx, dx
call print_string




; Hang
jmp $



%include "print.asm"
%include "read_disk.asm"

intro:
    db 'Bootsector Loaded!', 0xa, 0xd, 0 ; 0xa newline and 0xd cr

boot_drive_msg:
    db 'Boot Drive Address: ', 0 

nlcr:
    db 0xa, 0xd, 0

disk_read_success:
    db 'Disk Read Success!', 0xa, 0xd, 0

; This tells the assembler to pad with 0s until 510's byte 
; $ is current position and $$ is beginning of section .. so ($-$$) is
; how far into current section. So padding with byte 0 510-($-$$) times
times 510-($-$$) db 0

; This fills the last two bytes with the magic word
dw 0xaa55


times 512 db 0x32 ; sector 2
times 512 db 0x33 ; sector 3