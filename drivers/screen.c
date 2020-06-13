#include "screen.h"
#include "ports.h"

// text location x,y corresponds to the ascii byte of row x column y
// attr location x,y corresponds to the attribute byte of row x column y

/* 
 * Sets the cursor to text location x, y
 */
void set_cursor(int text_x, int text_y)
{
    int text_offset = TEXT_OFFSET(text_x, text_y);

    write_port_byte(REG_SCREEN_CTRL, 14);
    write_port_byte(REG_SCREEN_DATA, text_offset >> 8);

    write_port_byte(REG_SCREEN_CTRL, 15);
    write_port_byte(REG_SCREEN_DATA, text_offset & 0xff);
}

/* Sets every character in frame buffer to a space with
 * white on black attribute. Also sets cursor to beginning
 */
void clear_screen()
{
    // Frame buffer starts at mem location VIDEO_ADDRESS
    char* VA = (char*) VIDEO_ADDRESS;

    int i, j;
    for(j = 0; j < MAX_COLS; j++)
    {
        for(i = 0; i < MAX_ROWS; i++)
        {
            *(VA + TEXT_OFFSET(i, j)) = ' ';
            *(VA + ATTR_OFFSET(i, j)) = WHITE_ON_BLACK;
        }
    }

    set_cursor(0, 0);
}
