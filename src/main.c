#include "engine.h"

int main(int argc, char *argv[]){
  int quit_game = 0, current_char, start_game = 0;
  struct snake_obj snake;

  initscr();
  start_color();

  nodelay(stdscr, true);
  noecho();
  nonl();
  curs_set(0);

  draw_border();
  print_welcome_message();
  initialize_snake(&snake);

  while(quit_game == 0){
    current_char = getch();

    if(start_game){
      if(play_game(current_char, &snake) == 0){
      }else{
        start_game = 0;
      }
    }

    switch(current_char){
      case QUIT_CHAR:
        quit_game = 1;
        break;
      case KEY_ENTER_RAW:
       start_game = 1;
       draw_border();
       break;
    }

    refresh();
  }

  endwin();
  return 1;
}
