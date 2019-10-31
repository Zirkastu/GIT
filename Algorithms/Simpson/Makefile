all: Sim
Sim: a.o b.o f.o
	gcc a.o b.o f.o -o Sim -lm
a.o: a.c
	gcc -c a.c     
b.o: b.c	
	gcc -c b.c
f.o: f.c
	gcc -c f.c 
clean:
	rm -f *.o 

