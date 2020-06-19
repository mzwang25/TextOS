#ifndef KMALLOC_H
#define KMALLOC_H

#include "types.h"

extern uint32_t placement_address;

/* This implementation auto zeros the requested size */ 
void* kmalloc(uint32_t bytes);

#endif