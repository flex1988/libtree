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
#define FULL_NODES 2 * MINIMUM_DEGREE - 1
typedef struct
{
    bool leaf;
    int nodes;
    uint64_t key[FULL_NODES];
    uint64_t ptr[FULL_NODES + 1];
    uint64_t pos;
} Node;

typedef struct
{
    int height;
    int t;
    Node* root;
    FILE* idx;
    FILE* data;
    uint64_t pos;
} Tree;

Tree* btree_create();
Node* btree_search(Node* n, Tree* t, uint64_t key, uint64_t* index);
Node* allocate_node(Tree* t);

bool disk_write(FILE* p, size_t pos, Node* n);
Node* disk_read(Tree* t, size_t pos);
void btree_split_child(Tree* t, Node* x, uint64_t i);
void btree_insert(Tree* t, uint64_t key);
void btree_insert_nonfull(Tree* t, Node* n, uint64_t key);
#endif
