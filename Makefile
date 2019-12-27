CC = g++
CFLAGS = -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio
OBJS = main.o ./AnimatedSprite/AnimatedSprite.o

all: main
main.o: main.cpp
	$(CC) -c main.cpp
	

main: $(OBJS)
	$(CC) -o main $(OBJS) $(CFLAGS)
	

clean:
	rm $(OBJS) main
