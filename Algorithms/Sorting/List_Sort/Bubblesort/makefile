all: Bubblesort

Bubblesort: main.o List.o Bubblesort.o Functions.o
	gcc main.o List.o Bubblesort.o Functions.o -o Bubblesort
main.o: main.c
	gcc -c main.c
List.o: List.c
	gcc -c List.c
Bubblesort.o: Bubblesort.c
	gcc -c Bubblesort.c
Functions.o: Functions.c
	gcc -c Functions.c