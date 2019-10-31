all: GLL
GLL: GLL.o source.o
	gfortran source.o GLL.o -g -o GLL -lm
GLL.o: GLL.f90
	gfortran -c -g GLL.f90
source.o: source.f90
	gfortran -c -g source.f90
