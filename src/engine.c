#include "engine.h"

int is_gameover = 0;

void engine_start(void)
{
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

void draw_border(void)
{
  int i, o;
  for (i = 0; i < LINES; i++)
  {
    for (o = 0; o < COLS; o++)
    {
      if (i == 0 || i == LINES - 1 ||
          o == 0 || o == COLS - 1)
      {
        mvaddch(i, o, '#');
      }
      else
      {
        mvaddch(i, o, ' ');
      }
    }
  }
}

void print_welcome_message(void)
{
  int pos_x, pos_y, text_offset;

  pos_x = LINES / 2;
  pos_y = COLS / 2;

  text_offset = strlen(WELCOME_MESSAGE) / 2;

  pos_y = pos_y - text_offset;
  pos_x = pos_x - 3; // this is just an offset, not important

  mvprintw(pos_x, pos_y, "%s", WELCOME_MESSAGE);
}

int get_speed()
{
  if (snake.length > 5)
    return 30000;
  if (snake.length > 10)
    return 20000;
  if (snake.length > 20)
    return 10000;
  if (snake.length > 30)
    return 5000;

  return 50000;
}

void print_gameover_message()
{
  int msg_length = strlen(GAMEOVER_MESSAGE) + 10;
  char msg[msg_length];
  int pos_x, pos_y, text_offset;

  pos_x = LINES / 2;
  pos_y = COLS / 2;

  text_offset = msg_length / 2;

  pos_y = pos_y - text_offset;
  pos_x = pos_x - 3; // this is just an offset, not important

  sprintf(msg, GAMEOVER_MESSAGE, snake.length - DEFAULT_LENGTH);

  mvprintw(pos_x, pos_y, "%s", msg);
}

int play_game()
{
  if (is_gameover == 1)
  {
    print_gameover_message();
    return 0;
  }

  draw_border();
  update_position();
  draw_snake();
  draw_apple();

  is_gameover = check_snake_position();

  usleep(get_speed());
  return 1;
}
