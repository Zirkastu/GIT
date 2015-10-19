all: Quicksort

Quicksort: main.o quicksort.o
	gcc main.o quicksort.o -o Quicksort
main.o: main.c
	gcc -c main.c
quicksort.o: quicksort.c
	gcc -c quicksort.c