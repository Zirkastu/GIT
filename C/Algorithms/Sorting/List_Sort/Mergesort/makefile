all: Mergesort

Mergesort: main.o List.o Mergesort.o Functions.o
	gcc main.o List.o Mergesort.o Functions.o -o Mergesort
main.o: main.c
	gcc -c main.c
List.o: List.c
	gcc -c List.c
Mergesort.o: Mergesort.c
	gcc -c Mergesort.c
Functions.o: Functions.c
	gcc -c Functions.c