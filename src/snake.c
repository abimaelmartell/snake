#include "engine.h"

struct snake_obj snake;

void draw_snake(){
  int i;
  for(i = 0; i < snake.length; i++){
    mvaddch(
      snake.pieces[i].y,
      snake.pieces[i].x,
      i == 0 ? '@' : '#'
    );
  }
}

void initialize_snake(){
  int i;

  snake.length = DEFAULT_LENGTH;
  snake.pieces = malloc(sizeof(struct snake_piece) * DEFAULT_LENGTH);
  snake.position_y = LINES / 2;
  snake.position_x = COLS / 2;
  snake.direction = DIRECTION_RIGHT;
  snake.is_playing = 0;

  for(i = 0; i < snake.length; i++){
    snake.pieces[i].x = COLS / 2;
    snake.pieces[i].y = LINES / 2;
  }
}

void set_direction(int new_direction){
  if(
    (snake.direction == DIRECTION_RIGHT && new_direction != DIRECTION_LEFT) ||
    (snake.direction == DIRECTION_LEFT && new_direction != DIRECTION_RIGHT) ||
    (snake.direction == DIRECTION_UP && new_direction != DIRECTION_DOWN) ||
    (snake.direction == DIRECTION_DOWN && new_direction != DIRECTION_UP)
  )
    snake.direction = new_direction;
}

void increase_length(int how_much){
  int i, total_pieces;
  struct snake_piece *piece;

  total_pieces = snake.length + how_much;

  snake.pieces = realloc(snake.pieces, total_pieces);

  snake.length = total_pieces;
}

void update_position(){
  int i;

  for(i = (snake.length-1); i > 0; i--){
    snake.pieces[i].x = snake.pieces[i-1].x;
    snake.pieces[i].y = snake.pieces[i-1].y;
  }

  if(snake.direction == DIRECTION_RIGHT)
    snake.pieces[0].x += 1;
  else if(snake.direction == DIRECTION_LEFT)
    snake.pieces[0].x -= 1;
  else if(snake.direction == DIRECTION_UP)
    snake.pieces[0].y -= 1;
  else if(snake.direction == DIRECTION_DOWN)
    snake.pieces[0].y += 1;
}

int check_snake_position(){
  // is eating apple
  if (snake.pieces[0].x == apple.x && snake.pieces[0].y == apple.y) {
    snake.length++;

    position_apple();
  }

  // check if crash with himself
  int i;

  for (i = (snake.length-1); i > 0; i--){
    if (snake.pieces[0].x == snake.pieces[i].x && snake.pieces[0].y == snake.pieces[i].y) {
      return 1;
    }
  }

  // check if in borders
  if (snake.pieces[0].x == 0) {
    snake.pieces[0].x = COLS;
  } else if (snake.pieces[0].x == COLS) {
    snake.pieces[0].x = 0;
  } else if (snake.pieces[0].y == 0) {
    snake.pieces[0].y = LINES;
  } else if (snake.pieces[0].y == LINES) {
    snake.pieces[0].y = 0;
  }

  return 0;
}
