all: LU
LU: main.o LU.o solve.o inverse.o Zeidel.o operations.o
	gcc main.o LU.o solve.o  inverse.o Zeidel.o operations.o -o LU -lm
main.o: main.c
	gcc -c -g main.c     
LU.o: LU.c
	gcc -c -g LU.c
solve.o: solve.c
	gcc -c -g solve.c	
inverse.o: inverse.c
	gcc -c -g inverse.c
Zeidel.o: Zeidel.c
	gcc -c -g Zeidel.c
operations.o: operations.c
	gcc -c -g operations.c	
		

