#include "engine.h"

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
