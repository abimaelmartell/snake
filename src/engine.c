#include "engine.h"

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
  pos_x = pos_x - 3; // this is just an offset, nothing important
  
  mvprintw(pos_x, pos_y, "%s", WELCOME_MESSAGE);
}

int get_speed(){
  return 100000;
}

int play_game(int direction, struct snake_obj *snake){
  draw_border();
  draw_snake(snake);

  if(direction == -1){
    direction = snake->direction;
  }

  snake->position_x++;

  usleep(get_speed());
  return 1;
}


