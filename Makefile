HEADERS = engine.h snake.h
OBJECTS = src/main.o src/snake.o src/engine.o

LIBS = -lncurses

default: snake

%.o: %.c $(HEADERS)
	gcc -c $< -o $@ $(LIBS)

snake: $(OBJECTS)
	gcc $(OBJECTS) -o $@ $(LIBS)

clean:
	-rm -f $(OBJECTS)
	-rm -f snake
