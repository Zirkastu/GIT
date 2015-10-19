all: Queue

Queue: main.o queue.o
	gcc main.o queue.o -o Queue
main.o: main.c
	gcc -c main.c
queue.o: queue.c
	gcc -c queue.c