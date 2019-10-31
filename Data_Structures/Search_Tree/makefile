all: Tree

Tree: main.o Tree.o Search_Tree.o Functions.o
	gcc main.o Tree.o Search_Tree.o Functions.o -o Tree
main.o: main.c
	gcc -c -g main.c
Tree.o: Tree.c
	gcc -c -g Tree.c
Search_Tree.o: Search_Tree.c
	gcc -c -g Search_Tree.c
Functions.o: Functions.c
	gcc -c -g Functions.c
