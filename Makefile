HEADERS = engine.h snake.h apple.h
OBJECTS = src/main.o src/apple.o src/snake.o src/engine.o

LIBS = -lncurses

default: snake

%.o: %.c $(HEADERS)
	gcc -c $< -o $@ $(LIBS)

snake: $(OBJECTS)
	gcc $(OBJECTS) -o $@ $(LIBS)

clean:
	-rm -f $(OBJECTS)
	-rm -f snake
