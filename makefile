all: library.o list.o main.o
	gcc -o go library.o list.o

main.o: main.c list.h library.h
	gcc -c main.c

list.o: list.c list.h
	gcc -c list.c

library.o: library.c library.h
	gcc -c library.c

run: ./go

clear:
	rm go
	rm *.o
