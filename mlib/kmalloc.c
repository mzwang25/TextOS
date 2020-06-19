#include "kmalloc.h"
#include "mem.h"

uint32_t placement_address = 0x10000;

void* kmalloc(uint32_t bytes)
{
    if(placement_address & 0x00000FFF)
    {
        placement_address &= 0xFFFFF000;
        placement_address += 0x1000;
    }

    uint32_t current_loc = placement_address;
    placement_address += bytes;

    bzero((void*) current_loc, bytes);
    return (void*) current_loc;
}