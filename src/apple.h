#define APPLE_CHAR 'a'

/**
 * Represents the apple
 **/
struct apple_obj {
  int x, y;
} apple_obj;

extern struct apple_obj apple;

extern void draw_apple();
extern void position_apple();
