#ifndef PORTS_H
#define PORTS_H

#include "../mlib/types.h"

// Functions do operations with IO ports
// IO port numbers are 2 bytes

uint8_t read_port_byte(uint16_t port);
void write_port_byte(uint16_t port, uint8_t data);

uint16_t read_port_word(uint16_t port);
void write_port_word(uint16_t port, uint16_t data);

#endif