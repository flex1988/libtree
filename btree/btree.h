#ifndef __BTREE__
#define __BTREE__
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    bool leaf;
    int nodes;
    uint64_t key[1000];
    uint64_t ptr[1001];
} Node;

typedef struct {
    int height;
    int t;
    Node* root;
    int idxfd;
    int datafd;
} Tree;

Tree* btree_create(const char *path);
//Node* btree_search(uint64_t key);
Node* allocate_node();

//bool disk_write(Node* n, char* path);
//bool disk_read(Node* n, char* path);
#endif
