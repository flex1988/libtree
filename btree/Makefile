all: btree

btree.o:btree.c btree.h

btree:btree.o
	gcc -g -o btree btree_test.c btree.o

clean:
	rm *.o btree
	rm -rf btree.dSYM
