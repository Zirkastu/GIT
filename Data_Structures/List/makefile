all: List

List: main.o List.o
	gcc main.o List.o -o List
main.o: main.c
	gcc -c main.c
List.o: List.c
	gcc -c List.c
