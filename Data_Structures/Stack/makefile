all: Stack

Stack: main.o stack.o
	gcc main.o stack.o -o Stack
main.o: main.c
	gcc -c -g main.c
stack.o: stack.c
	gcc -c -g stack.c