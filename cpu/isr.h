#ifndef ISR_H
#define ISR_H

/*
 * Interrupt Service Routines: isrX called when interrupt detected
 */ 

#include "../mlib/types.h"
#define ISR_DEC(X) extern void isr##X();
#define SET_IDT(X) set_idt_gate(X, (uint32_t) isr##X);

// this struct combines all the registers
typedef struct 
{
    uint32_t ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, useresp, ss;
} registers_t;

void isr_install();
void isr_handler(registers_t r);

ISR_DEC(0)
ISR_DEC(1)
ISR_DEC(2)
ISR_DEC(3)
ISR_DEC(4)
ISR_DEC(5)
ISR_DEC(6)
ISR_DEC(7)
ISR_DEC(8)
ISR_DEC(9)
ISR_DEC(10)
ISR_DEC(11)
ISR_DEC(12)
ISR_DEC(13)
ISR_DEC(14)
ISR_DEC(15)
ISR_DEC(16)
ISR_DEC(17)
ISR_DEC(18)
ISR_DEC(19)
ISR_DEC(20)
ISR_DEC(21)
ISR_DEC(22)
ISR_DEC(23)
ISR_DEC(24)
ISR_DEC(25)
ISR_DEC(26)
ISR_DEC(27)
ISR_DEC(28)
ISR_DEC(29)
ISR_DEC(30)
ISR_DEC(31)

#endif
