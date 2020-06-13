#ifndef SCREEN_H
#define SCREEN_H

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

#define WHITE_ON_BLACK 0x0f
#define BLACK_ON_WHITE 0xf0

#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

#define TEXT_OFFSET(X,Y) ((X * MAX_COLS + Y) * 2)
#define ATTR_OFFSET(X,Y) ((X * MAX_COLS + Y) * 2 + 1)

void clear_screen();
void set_cursor(int text_x, int text_y);

#endif