; Global Offset 0x7c00 (where boot sector starts)
;[org 0x7c00]

; This is a bootsector in assembly
; The bootsector is 512 bytes and must end with word 0xaa55
; Operates in 16-bit mode
mov ah, 0x0e

%include "segmentation.asm"
jmp $

%include "print.asm"

intro:
    db 'Hi, I am the MichaelOS Bootsector!', 0

; This tells the assembler to pad with 0s until 510's byte 
; $ is current position and $$ is beginning of section .. so ($-$$) is
; how far into current section. So padding with byte 0 510-($-$$) times
times 510-($-$$) db 0

; This fills the last two bytes with the magic word
dw 0xaa55
