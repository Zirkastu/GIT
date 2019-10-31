all: Stack

Stack: main.o Stack.o
	gcc main.o Stack.o -o Stack
main.o: main.c
	gcc -c -g main.c
Stack.o: Stack.c
	gcc -c -g Stack.c
