#include <stdlib.h>

#include "engine.h"

struct apple_obj apple;

void draw_apple(){
  int i;

    mvaddch(
      apple.y,
      apple.x,
      APPLE_CHAR
    );
}

void position_apple(){
  int y = rand() % LINES;
  int x = rand() % COLS;
  apple.y = y;
  apple.x = x;
}
