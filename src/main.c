#include "engine.h"

int main(int argc, char *argv[]){
  int quit_game = 0, current_char, start_game = 0;
  struct snake_obj snake;

  engine_start();
  initialize_snake(&snake);

  while(quit_game == 0){
    current_char = getch();

    switch(current_char){
      case QUIT_CHAR:
        quit_game = 1;
        break;
      case KEY_ENTER_RAW:
        if(start_game == 0){
          start_game = 1;
          draw_border();
        }
        break;
      case KEY_UP:
        set_direction(&snake, DIRECTION_UP);
        break;
      case KEY_DOWN:
        set_direction(&snake, DIRECTION_DOWN);
        break;
      case KEY_LEFT:
        set_direction(&snake, DIRECTION_LEFT);
        break;
      case KEY_RIGHT:
        set_direction(&snake, DIRECTION_RIGHT);
        break;
    }

    if(start_game){
      if(play_game(&snake) == 0){
        start_game = 0;
      }
    }

    refresh();
  }

  endwin();
  return 1;
}
