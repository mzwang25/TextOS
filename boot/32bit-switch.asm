[bits 16]

switch_to_pm:
    cli ; disables interrupts bc 16/32 mode handles differently
    lgdt [gdt_descriptor] ; loads GDT
    ; set cr0 to 1 ... cr0 is a special register so once it's updated it's in 32 bit mode
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax

    jmp CODE_SEG:init_pm ; far jump (jmps to a particular address)
                         ; This flushes the pipeline so code won't get
                         ; executed in the wrong mode

[bits 32]
init_pm:
    ; update the segment registers: DATA segment and CODE segment the same
    mov ax, DATA_SEG 
    mov ds, ax 
    mov ss, ax 
    mov es, ax 
    mov fs, ax 
    mov gs, ax 

    mov ebp, 0x90000; update stack bc addressable memory is now bigger
    mov esp, ebp 

    call BEGIN_PM; entry point into kernel