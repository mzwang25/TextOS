; this defines a 32-bit global descriptor table
; Uses a simple flat model -> two overlapping code and data segments

; Base: 0x0
; Limit: 0xfffff
; Present: 1 -> in memory
; Privilige: 0 -> Highest 
; Descriptor Type: 1 -> Since 1 is for code/data segments
; Types: Code(1), Conforming(0 ... lower priv cannot call code in this segment)
;        Readable(1), Accessed(0 ... CPU sets this bit when segment is accessed)
; Flags: Granularity(1 ... multiplies limit by 4k), 32-bit default(1)

; Code segment's types does is not writable but data segment is writable

gdt_start:
    dd 0x0 ; 4 byte - need null bytes to make gdt valid
    dd 0x0 ; 4 byte

; Code Segment. Base = 0x0, length = 0xfffff
gdt_code:
    dw 0xffff ; segment length
    dw 0x0 ; segment base
    db 0x0 ; segment base
    db 10011010b ; flags
    db 11001111b ; flags + segment length
    db 0x0 ; segment base

; Data Segment. Same base and length as code 
gdt_data:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start ; address (32 bit)

; Memory addresses of GDT entries ... Segment registers will contain this after
; switching into 32 bit mode
CODE_SEG equ gdt_code - gdt_start 
DATA_SEG equ gdt_data - gdt_start


