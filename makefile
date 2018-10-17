all: list.o library.o main.o
	gcc -o go main.o library.o list.o

main.o: main.c list.h library.h
	gcc -c main.c

list.o: list.c list.h
	gcc -c list.c

library.o: library.c library.h list.h
	gcc -c library.c

run:
	./go

clear:
	rm go
	rm *.o
