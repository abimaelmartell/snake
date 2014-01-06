#include <ncurses.h>
#include <string.h>
#include <unistd.h>

#include "snake.h"

#define QUIT_CHAR 113 // this is "q"
#define KEY_ENTER_RAW 13 // we're using raw()
#define WELCOME_MESSAGE "Welcome to snake, press enter to start."

extern void draw_border(void);
extern void print_welcome_message(void);
extern int get_speed(void);
extern int play_game(struct snake_obj *snake);
extern void engine_start(void);
