#include "engine.h"

void engine_start(void){
  // start ncurses screen
  initscr();
  start_color();

  // customizations
  raw();
  nodelay(stdscr, TRUE);
  noecho();
  nonl();
  curs_set(0);
  keypad(stdscr, TRUE);
  refresh();

  // render game
  draw_border();
  print_welcome_message();
}

void draw_border(void){
  int i, o;
  for(i = 0; i < LINES; i++){
    for(o = 0; o < COLS; o++){
      if(i == 0 || i == LINES -1 ||
        o == 0 || o == COLS -1){
        mvaddch(i, o, '#');
      }else{
        mvaddch(i, o, ' ');
      }
    }
  }
}

void print_welcome_message(void){
  int pos_x, pos_y, text_offset;

  pos_x = LINES / 2;
  pos_y = COLS / 2;

  text_offset = strlen(WELCOME_MESSAGE) / 2;

  pos_y = pos_y - text_offset;
  pos_x = pos_x - 3; // this is just an offset, not important
  
  mvprintw(pos_x, pos_y, "%s", WELCOME_MESSAGE);
}

int get_speed(){
  // TODO: calculate this value based on a level or something
  return 200000;
}

int play_game(){
  draw_border();
  draw_snake();

  update_position();

  usleep(get_speed());
  return 1;
}

