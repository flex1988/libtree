#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binary_search_tree.h"

void create_ordered_tree(node *tree, int num) {
    int i, ret;
    node *t;

    for (i = 0; i < num; i++) {
        t = create_node(i);
        ret = insert_node(tree, t);
        if (ret != OK)
            continue;
    }
    printf("create node done ordered\n");
}

void create_unordered_tree(node *tree, int num) {
    int i, ret;
    node *t;
    for (i = 0; i < num; i++) {
        t = create_node(rand());
        ret = insert_node(tree, t);
        if (ret != OK)
            continue;
    }
    printf("create node done unordered\n");
}

int main(int argc,char **argv) {
    int num = atoi(argv[1]);
    node *tree = create_node(0);
    create_ordered_tree(tree, num);

    time_t start, end;
    node *s;

    start = time(NULL);
    s = search_tree(tree, 10);
    end = time(NULL);
    printf("searching for 10 in ordered tree in %.2f ms\n", (float)(end - start));

    start = time(NULL);
    s = search_tree(tree, 100);
    end = time(NULL);
    printf("searching for 100 in ordered tree in %.2f ms\n",
           (float)(end - start));

    start = time(NULL);
    s = search_tree(tree, 1000);
    end = time(NULL);
    printf("searching for 1000 in ordered tree in %.2f ms\n",
           (float)(end - start));

    start = time(NULL);
    s = search_tree(tree, 10000);
    end = time(NULL);
    printf("searching for 10000 in ordered tree in %.2f ms\n",
           (float)(end - start));

    free_node(tree);

    tree = create_node(0);
    create_unordered_tree(tree, num);

    start = time(NULL);
    s = search_tree(tree, 10);
    end = time(NULL);
    printf("searching for 10 in unordered tree in %.2f ms\n",
           (float)(end - start));

    start = time(NULL);
    s = search_tree(tree, 100);
    end = time(NULL);
    printf("searching for 100 in unordered tree in %.2f ms\n",
           (float)(end - start));

    start = time(NULL);
    s = search_tree(tree, 1000);
    end = time(NULL);
    printf("searching for 1000 in unordered tree in %.2f ms\n",
           (float)(end - start));

    start = time(NULL);
    s = search_tree(tree, 10000);
    end = time(NULL);
    printf("searching for 10000 in unordered tree in %.2f ms\n",
         (float)(end - start));

    free_node(tree);

    return 0;
}
