#include "btree.h"

Tree *btree_create() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    Node *n = allocate_node();
    if (!n)
        return NULL;
    n->leaf = true;
    n->nodes = 0;
    tree->root = n;
    tree->idx = NULL;
    tree->data = NULL;

    tree->idx = fopen("./db.index", "w+");

    if (!tree->idx) {
        printf("open index file failed %s\n", strerror(errno));
        goto error;
    }

    tree->data = fopen("./db.data", "w+");

    if (!tree->data) {
        printf("open data file failed %s\n", strerror(errno));
        goto error;
    }

    if (!disk_write(tree->idx, 0, n)) {
        printf("write node to disk failed %s\n", strerror(errno));
        goto error;
    }
    return tree;

error:
    free(tree->root);
    fclose(tree->idx);
    fclose(tree->data);
    free(tree);
    return NULL;
}

Node *allocate_node() {
    Node *n = (Node *)malloc(sizeof(Node));
    return n;
}

bool disk_write(FILE *p, size_t pos, Node *n) {
    fseek(p, pos, SEEK_SET);
    size_t r = fwrite(n, sizeof(Node), 1, p);
    return r == 1;
}

Node *btree_search(Node *n, Tree *t, uint64_t key, uint64_t *index) {
    int i = 0;

    while (i < n->nodes && key > n->key[i]) i++;

    if (i < n->nodes && key == n->key[i]) {
        *index = i;
        return n;
    } else if (n->leaf) {
        *index = 0;
        return NULL;
    } else {
        Node *next = disk_read(t, n->ptr[i]);
        return btree_search(next, t, key, index);
    }
}

Node *disk_read(Tree *t, size_t pos) {
    Node *buf = malloc(sizeof(Node));
    fseek(t->idx, pos, SEEK_SET);
    size_t r = fread(buf, sizeof(Node), 1, t->idx);
    return r == 1 ? buf : NULL;
}

/*bool disk_write_index(FILE *p, size_t pos, Node *n) {*/
/*size_t r = fwrite(n, sizeof(Node), 1, p);*/
/*return r == sizeof(Node);*/
/*}*/
