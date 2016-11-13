#ifndef __BTREE__
#define __BTREE__
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MINIMUM_DEGREE 100

typedef struct {
    bool leaf;
    int nodes;
    uint64_t key[2 * MINIMUM_DEGREE - 1];
    uint64_t ptr[2 * MINIMUM_DEGREE];
} Node;

typedef struct {
    int height;
    int t;
    Node *root;
    FILE *idx;
    FILE *data;
} Tree;

Tree *btree_create();
Node *btree_search(Node *n, Tree *t, uint64_t key, uint64_t *index);
Node *allocate_node();

bool disk_write(FILE *p, size_t pos, Node *n);
Node *disk_read(Tree *t, size_t pos);
void btree_split_child(Node *n, uint64_t i);
#endif
