all: RESULT
RESULT: DGPY.o GPY1.o source.o ROOTS.o
	gfortran DGPY.o GPY1.o source.o ROOTS.o -o RESULT 
GPY1.o: GPY1.f90
	gfortran -c GPY1.f90
DGPY.o: DGPY.f90
	gfortran -c DGPY.f90
ROOTS.o: ROOTS.f90
	gfortran -c -g ROOTS.f90
source.o: source.f90
	gfortran -c -g source.f90

