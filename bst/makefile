bst.exe: item.o  main.o queue.o stack.o bst.o 
	gcc  -o bst.exe item.o main.o queue.o stack.o bst.o 


item.o: item.c item.h
	gcc -c item.c

main.o : main.c bst.h
	gcc -c main.c

queue.o:queue.c queue.h itemqueue.h
	gcc -c queue.c


stack.o:stack.c stack.h stackitem.h
	gcc -c stack.c
	
bst.o: bst.c item.h bst.h stack.h queue.h
	gcc -c bst.c
	
clean:
	rm bst.o item.o  main.o queue.o stack.o bst.exe
