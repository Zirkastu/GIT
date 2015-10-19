all: List

List: main.o List.o
	gcc main.o list.o -o List
main.o: main.c
	gcc -c main.c
List.o: List.c
	gcc -c List.c