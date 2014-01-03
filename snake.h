#include <curses.h>
#include <string.h>

#define QUIT_CHAR 113 // this is "q"
#define WELCOME_MESSAGE "Welcome to snake, press enter to start."

struct snake{
  int length,
    position_x,
    position_y;
};

extern void draw_border(void);
extern void print_welcome_message(void);
