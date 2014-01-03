#include "snake.h"

int main(int argc, char *argv[]){
  int quit_game = 0, current_char, start_game = 0;

  initscr();
  start_color();

  nodelay(stdscr, true);
  noecho();
  nonl();
  curs_set(0);

  draw_border();
  print_welcome_message();
  
  while(quit_game == 0){
    if(start_game){
    }
    current_char = getch();

    switch(current_char){
      case QUIT_CHAR:
        quit_game = 1;
        break;
      case KEY_ENTER:
       start_game = 1;
       break;
    }
    refresh();
  }

  endwin();
  return 1;
}
