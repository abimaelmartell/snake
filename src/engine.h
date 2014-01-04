#include <curses.h>
#include <string.h>

#include "snake.h"

#define QUIT_CHAR 113 // this is "q"
#define KEY_ENTER_RAW 13 // we're using raw()
#define WELCOME_MESSAGE "Welcome to snake, press enter to start."

extern void draw_border(void);
extern void print_welcome_message(void);
extern int play_game(int character, struct snake_obj *snake);
