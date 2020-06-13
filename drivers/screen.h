#ifndef SCREEN_H
#define SCREEN_H

/*
 * Char offsets is the number 2 byte units away from start
 * Text/Attr offsets is the number of 1 byte units away from start
 */

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

#define WHITE_ON_BLACK 0x0f
#define BLACK_ON_WHITE 0xf0

#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

#define TEXT_OFFSET(X,Y) ((X * MAX_COLS + Y) * 2)
#define ATTR_OFFSET(X,Y) ((X * MAX_COLS + Y) * 2 + 1)

// X_loc and Y_loc assumes X is a char offset
#define X_LOC(X) X / MAX_COLS
#define Y_LOC(X) X % MAX_ROWS

#define X2CHAR(X) X / 2
#define CHAR2TEXT(X) X * 2
#define CHAR2ATTR(X) X * 2 + 1

void clear_screen();
void set_cursor(int text_x, int text_y);
void print_char_at(char c, int x, int y);
void print_char(char c);
void print_string(char* str);

#endif