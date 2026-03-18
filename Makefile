CC= g++
CFLAGS= -g -Wall -Wextra
default: main
main: main.o game.o
	$(CC) $(CFLAGS) -o main main.o game.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
game.o: game.cpp
	 $(CC) $(CFLAGS) -c game.cpp
clean:
	$(RM) main *.o *~
	$(RM) game *.o *~