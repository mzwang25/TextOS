#include "paging.h"
#include "types.h"

#define PAGE_SIZE 0x1000

/** Frameset Use/ Variable names
 * 
 *  frames = | <32 bits> | <32 bits> | <32 bits> | ...
 *  findex = |    0      |     1     |     2     | ...
 *  foffst = | 0123 ...  | 0123 ...  | 0123 ...  | ...
 *  frmnum = 123456789 ... 33 ... 234523452
 * 
 **/

/** GET_FRAME_INFO
 * This declares three vars
 *   - framenum
 *   - f_index 
 *   - f_offset
 **/

#define GET_FRAME_INFO(a)\
    uint32_t framenum = frame_addr / PAGE_SIZE; \
    uint32_t f_index = F_INDEX(framenum); \
    uint32_t f_offset = F_OFFSET(framenum);

// placement_address defined in kheap.c
// don't think it's the best idea to do this!
extern uint32_t placement_address;


uint32_t* frames;
uint32_t nframes;

#define F_INDEX(a) (a/(8*4))
#define F_OFFSET(a) (a%(8*4))

// set a bit in the frameset given the address of the frame
void set_frame(uint32_t frame_addr)
{
    GET_FRAME_INFO(frame_addr);
    frames[f_index] |= (0x1 << f_offset);
}

// clear a bit in the frames bitset
void clear_frame(uint32_t frame_addr)
{
    GET_FRAME_INFO(frame_addr);
}

// clear a bit in the frames bitset
void test_frame(uint32_t frame_addr)
{
    GET_FRAME_INFO(frame_addr);
}