#include "screen.h"
#include "ports.h"

// Frame buffer starts at mem location VIDEO_ADDRESS
char* VA = (char*) VIDEO_ADDRESS;

//get current cursor location and returns the char offset of the cursor
int get_curser_loc()
{
    write_port_byte(REG_SCREEN_CTRL, 14);
    int offset = read_port_byte(REG_SCREEN_DATA) << 8;

    write_port_byte(REG_SCREEN_CTRL, 15);
    offset += read_port_byte(REG_SCREEN_DATA);

    return offset;
}

/* 
 * Sets the cursor to text location x, y
 */
void set_cursor(int text_x, int text_y)
{
    int text_offset = X2CHAR(TEXT_OFFSET(text_x, text_y));

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

void print_char_at(char c, int x, int y)
{
    *(VA + TEXT_OFFSET(x, y)) = c;
}

void print_char(char c)
{
    int char_offset = get_curser_loc();
    print_char_at(c, X_LOC(char_offset), Y_LOC(char_offset));
    set_cursor(X_LOC(char_offset), Y_LOC(char_offset) + 1);
}

void print_string(char* str)
{
    while(*str != 0)
    {
        print_char(*str);
        str++;
    }
}