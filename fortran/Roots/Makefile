all: ROOT
ROOT: ROOTS.o source.o
	gfortran source.o ROOTS.o -g -o ROOT -lm
ROOTS.o: ROOTS.f90
	gfortran -c -g ROOTS.f90
source.o: source.f90
	gfortran -c -g source.f90
