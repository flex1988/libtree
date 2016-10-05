all: tree_testtree_test

binary_search_tree.o:binary_search_tree.c binary_search_tree.h

tree_testtree_test:binary_search_tree.o
	gcc -g -o test tree_test.c binary_search_tree.o

clean:
	rm *.o *.gch test
