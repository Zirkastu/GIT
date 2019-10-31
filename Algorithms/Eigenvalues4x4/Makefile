all: Eigenvalues
Eigenvalues: main.o mathfunctions.o GAUSS.o roots.o
	gcc main.o mathfunctions.o GAUSS.o roots.o -o Eigenvalues -lm
main.o: main.c
	gcc -c -g main.c     
mathfunctions.o: mathfunctions.c
	gcc -c -g mathfunctions.c
GAUSS.o: GAUSS.c
	gcc -c -g GAUSS.c	
roots.o: roots.c
	gcc -c -g roots.c
