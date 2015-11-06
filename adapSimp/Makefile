rCC = g++
CC = clang++
FLAGS = -std=c++11 -g -Wall -pedantic

main.out: main.cpp adaptiveSimpson.h
	$(CC) $(FLAGS) main.cpp -o main.out

clean:
	rm -f *.o *.out && clear
