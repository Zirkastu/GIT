TARGET = Stack
all: $(TARGET)

$(TARGET): main.o stack.o
	gcc main.o stack.o -o $(TARGET)
main.o: main.c
	gcc -c -g main.c
stack.o: stack.c
	gcc -c -g stack.c