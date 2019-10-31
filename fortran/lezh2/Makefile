all: lezh
lezh: CNM.o source.o
	gfortran source.o CNM.o -g -o lezh -lm
CNM.o: CNM.f90
	gfortran -c -g CNM.f90
source.o: source.f90
	gfortran -c -g source.f90
