// directions
#define DIRECTION_UP    1
#define DIRECTION_DOWN  2
#define DIRECTION_LEFT  3
#define DIRECTION_RIGHT 4

#define DEFAULT_LENGTH 20


/**
 * Represents each piece of the snake's body
 **/
struct snake_piece{
  int x, y;
} snake_piece;

/**
 * Snake object
 */
struct snake_obj{
  int length,
    position_x,
    position_y,
    direction,
    is_playing;
  struct snake_piece *pieces;
} snake_obj;

extern void draw_snake(struct snake_obj *snake);
extern void initialize_snake(struct snake_obj *snake);
extern void set_direction(struct snake_obj *snake, int input_char);
extern void increase_length(struct snake_obj *snake, int how_much);
extern void update_position(struct snake_obj *snake);
