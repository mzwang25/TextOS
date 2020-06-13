#define VIDEO_MEMORY 0xb8000
#include "../drivers/ports.h"

void main()
{
    write_port_byte(0x3d4, 14);

    int position = read_port_byte(0x3d5);
    position = position << 8;

    write_port_byte(0x3d4, 15);
    position += read_port_byte(0x3d5);

    char* vga = (char*) VIDEO_MEMORY;
    vga[2 * position] = 'X';
    vga[2*position + 1] = 0x0f;

}
