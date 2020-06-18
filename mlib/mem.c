#include "types.h"
#include "mem.h"
#include "print.h"

uint32_t placement_address = 0x10000;

uint32_t kmalloc_internal(uint32_t sz, int align, uint32_t* phys_address)
{
    if(align && (placement_address & 0x00000FFF)) //if not page-aligned
    {
        placement_address &= 0xFFFFF000;
        placement_address += 0x1000;
    }

    if(phys_address)
    {
        *phys_address = placement_address;
    }
    uint32_t tmp = placement_address;
    placement_address += sz;
    return tmp;
}


uint32_t kmalloc_a(uint32_t sz)  // page aligned.
{
    return kmalloc_internal(sz, 1, 0);
}

uint32_t kmalloc_p(uint32_t sz, uint32_t *phys) // returns a virtual address.
{
    return kmalloc_internal(sz, 0, phys);
}
uint32_t kmalloc_ap(uint32_t sz, uint32_t *phys) // page aligned and returns a virtual address.
{
    return kmalloc_internal(sz, 1, phys);
}

uint32_t kmalloc(uint32_t sz) // vanilla (normal).
{
    return kmalloc_internal(sz, 0, 0);
}


