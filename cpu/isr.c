#include "isr.h"
#include "idt.h"
#include "../drivers/screen.h"
#include "../mlib/print.h"

/* 
 * isr_install creates idt entries for each of these interrupts
 */
void isr_install()
{
    SET_IDT(0)
    SET_IDT(1)
    SET_IDT(2)
    SET_IDT(3)
    SET_IDT(4)
    SET_IDT(5)
    SET_IDT(6)
    SET_IDT(7)
    SET_IDT(8)
    SET_IDT(9)
    SET_IDT(10)
    SET_IDT(11)
    SET_IDT(12)
    SET_IDT(13)
    SET_IDT(14)
    SET_IDT(15)
    SET_IDT(16)
    SET_IDT(17)
    SET_IDT(18)
    SET_IDT(19)
    SET_IDT(20)
    SET_IDT(21)
    SET_IDT(22)
    SET_IDT(23)
    SET_IDT(24)
    SET_IDT(25)
    SET_IDT(26)
    SET_IDT(27)
    SET_IDT(28)
    SET_IDT(29)
    SET_IDT(30)
    SET_IDT(31)

    set_idt();
}

// isr_handler is called after an interrupt is detected ... r contains all registers
void isr_handler(registers_t r)
{
    strprint("\n*** Interrupt ");
    printint(r.int_no);
    strprint(" detected! ***\n");
}