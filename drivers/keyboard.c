#include "keyboard.h"
#include "ports.h"
#include "../mlib/types.h"
#include "../cpu/isr.h"

void print_letter(uint8_t scancode);

void keyboard_callback(registers_t r)
{
    uint8_t scancode = read_port_byte(0x60);
    print_letter(scancode);
}

void print_letter(uint8_t scancode) {
    // maybe an input buffer here?
    strprint("x");
}
