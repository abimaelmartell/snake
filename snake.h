#include <curses.h>
#include <string.h>

#define QUIT_CHAR 113 // this is "q"
#define KEY_ENTER_RAW 13 // we're using raw()
#define WELCOME_MESSAGE "Welcome to snake, press enter to start."

// directions
#define DIRECTION_UP    1
#define DIRECTION_DOWN  2
#define DIRECTION_LEFT  3
#define DIRECTION_RIGHT 4

#define DEFAULT_LENGTH 20

struct snake_obj{
  int length,
    position_x,
    position_y,
    direction,
    is_playing;
};

extern void draw_border(void);
extern void print_welcome_message(void);
extern int play_game(int character, struct snake_obj *snake);
extern void draw_snake(struct snake_obj *snake);
extern void initialize_snake(struct snake_obj *snake);
