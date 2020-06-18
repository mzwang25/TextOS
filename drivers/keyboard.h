// Keyboard for input. Works with interrupt from irq
#include "../cpu/isr.h"
void initialize_keyboard();
void keyboard_callback(registers_t r);