#include "../mlib/types.h"

/* inline Assembly
 * "[asm] : [outputs] : [inputs]"
 * "=a" puts output register in some variable
 * "a" loads EAX with data
 * "d" loads EDX with data
 */

// reads a byte from an IO port
uint8_t read_port_byte(uint16_t port)
{
    uint8_t result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

// writes a byte to an IO port
void write_port_byte(uint16_t port, uint8_t data)
{
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

// reads a word from an IO port
uint16_t read_port_word(uint16_t port)
{
    uint8_t result;
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

// writes a word to an IO port
void write_port_byte(uint16_t port, uint16_t data)
{
    __asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}