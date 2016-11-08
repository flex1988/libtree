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

typedef struct {
    bool leaf;
    int nodes;
    uint64_t key[1000];
    uint64_t ptr[1001];
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
#endif
