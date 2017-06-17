calc.exe: calcolatrice.o stack.o list.o item.o main.o
	gcc calcolatrice.o stack.o list.o item.o main.o -o calc.exe
	
calcolatrice.o: calcolatrice.c calcolatrice.h
	gcc -c calcolatrice.c
	
stack.o: stack.c stack.h
	gcc -c stack.c

list.o: list.c list.h
	gcc -c list.c
	
item.o: item.c item.h
	gcc -c item.c
	
main.o: main.c
	gcc -c main.c

clean:
	 rm calcolatrice.o stack.o list.o item.o main.o calc.exe
