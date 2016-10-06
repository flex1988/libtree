all: bst.test

bst.o:bst.c bst.h

bst.test:bst.o
	gcc -g -o bst.test bst_test.c bst.o

clean:
	rm *.o *.gch test
