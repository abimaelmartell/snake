#include "snake.h"

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

int play_game(int direction, struct snake_obj *snake){
  draw_snake(snake);

  if(direction == -1){
    direction = snake->direction;
  }

  return 1;
}

void draw_snake(struct snake_obj *snake){
  int start_pos_x, i;

  start_pos_x = snake->position_x - snake->length;

  for(i = 0; i < snake->length; i++){
    mvaddch(snake->position_y, start_pos_x + i, '@');
  }
}

void initialize_snake(struct snake_obj *snake){
  snake->length = DEFAULT_LENGTH;
  snake->position_y = LINES / 2;
  snake->position_x = COLS / 2;
  snake->direction = DIRECTION_RIGHT;
  snake->is_playing = 0;
}
