all: btree

btree.o:btree.c btree.h

btree:btree.o
	gcc -g -O2 -Wall -o btree btree_test.c btree.o

clean:
	rm *.o btree
	rm -rf btree.dSYM
	rm db.index
	rm db.data
