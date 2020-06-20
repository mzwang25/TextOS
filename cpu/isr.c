#include "isr.h"
#include "idt.h"
#include "../drivers/screen.h"
#include "../mlib/print.h"
#include "../mlib/mem.h"
#include "../drivers/ports.h"
#include "../drivers/keyboard.h"

void (*handlers[48])(registers_t);

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

    // Need to remap the PIC because PIC by default maps to already used vectors
    // absolutely no clue how this code works

    write_port_byte(MASTER_PIC_COMMAND, 0x11);
    write_port_byte(SLAVE_PIC_COMMAND, 0x11);

    write_port_byte(MASTER_PIC_DATA, 0x20);
    write_port_byte(SLAVE_PIC_DATA, 0x28);

    write_port_byte(MASTER_PIC_DATA, 0x04);
    write_port_byte(SLAVE_PIC_DATA, 0x02);
    
    write_port_byte(MASTER_PIC_DATA, 0x01);
    write_port_byte(SLAVE_PIC_DATA, 0x01);

    write_port_byte(MASTER_PIC_DATA, 0x0);
    write_port_byte(SLAVE_PIC_DATA, 0x0);

    // Now install the IRQs
    SET_IDT(32)
    SET_IDT(33)
    SET_IDT(34)
    SET_IDT(35)
    SET_IDT(36)
    SET_IDT(37)
    SET_IDT(38)
    SET_IDT(39)
    SET_IDT(40)
    SET_IDT(41)
    SET_IDT(42)
    SET_IDT(43)
    SET_IDT(44)
    SET_IDT(45)
    SET_IDT(46)
    SET_IDT(47)
    
    bzero(handlers, 48); 
    set_idt();
}

// isr_handler is called after an interrupt is detected ... r contains all registers
void isr_handler(registers_t r)
{
    handlers[r.int_no](r);
}

// set_irq_handler gives a handler for interrupt (intno)
void set_int_handler(uint8_t int_no, void (*func)(registers_t))
{
    handlers[int_no] = func;
}

// irq_handler called after irq is detected ... r contains all registers
void irq_handler(registers_t r)
{
    if(r.int_no >= 40)
        write_port_byte(MASTER_PIC_DATA, 0x20);

    write_port_byte(MASTER_PIC_COMMAND, 0x20);

    if((r.int_no) >= 0 && handlers[(r.int_no)] != 0)
        handlers[(r.int_no)](r);

}
