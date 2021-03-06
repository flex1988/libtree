#include "btree.h"
#include <assert.h>
#include <stdio.h>

static void
disk_read_write_test(Tree* t)
{
    Node* n = allocate_node(t);
    assert(n);
    printf("allocate_node test passed\n");
    n->nodes = 1000;
    n->leaf = true;
    n->key[101] = 1001;

    bool r = disk_write(t->idx, 0, n);
    assert(r == true);
    printf("disk_write test passed\n");

    n = disk_read(t, 0);
    assert(n->nodes == 1000);
    assert(n->leaf == true);
    assert(n->key[101] == 1001);

    free(n);
    printf("disk_read test passed\n");
}

static Tree*
btree_create_test()
{
    Tree* t = btree_create();
    if (!t) {
        printf("btree_create test failed\n");
        return NULL;
    }
    printf("btree_create test passed\n");
    return t;
}

static void
btree_insert_test(Tree* t)
{
    uint64_t i;
    for (i = 0; i < 100000; i++) {
        btree_insert(t, i);
    }
}

int
main()
{
    Tree* t = btree_create_test();
    disk_read_write_test(t);
    btree_insert_test(t);
    return 0;
}
