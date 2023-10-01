CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=-lMLV
EXEC=game
SRC=src
BIN=bin
snake: $(EXEC)
game: bin/game.o bin/grid.o bin/getlong.o
	$(CC) -o game bin/game.o bin/grid.o bin/getlong.o -lMLV
bin/getlong.o: src/getopt_long.c
	$(CC) -o bin/getlong.o -c src/getopt_long.c
bin/grid.o: src/grid.c src/snake.h
	$(CC) -o bin/grid.o -c src/grid.c -lMLV
bin/game.o: src/game.c src/grid.h src/getlong.h src/snake.h
	$(CC) -o bin/game.o -c src/game.c
bin/snake.o: src/snake.c
	$(CC) -o bin/snake.o -c src/snake.c
clean:
	rm  bin/*.o
clear :
	rm bin/*
tgz :
	make clear
	tar czf ../GOURE_SNAKE2021.tgz *

