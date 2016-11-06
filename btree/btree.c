#include "btree.h"

Tree *btree_create(const char *path) {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    Node *n = allocate_node();
    if (!n)
        return NULL;
    n->leaf = true;
    n->nodes = 0;
    //disk_write(n, path);
    tree->root = n;
    tree->idxfd = -1;
    tree->datafd = -1;

    char index[100];
    strcat(index,path);
    strcat(index, "db.index");
    int fd = open(index, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
    
    if (fd < 0) {
        
        if (errno == EEXIST) {
            printf("%d",errno);
            tree->idxfd = open(index, O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
        }
        goto error;
    } else {
        tree->idxfd = fd;
    }
    
    char data[100];
    strcat(data,path);
    strcat(data, "db.data");
    fd = open(data, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        if (errno == EEXIST) {
            tree->datafd = open(data, O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
        }
        goto error;
    } else {
        tree->datafd = fd;
    }
    return tree;

error:
    free(tree->root);
    close(tree->idxfd);
    close(tree->datafd);
    free(tree);
    return NULL;
}

Node* allocate_node(){
    Node *n = (Node *)malloc(sizeof(Node));
    return n;
}

//bool disk_write(Node *n) { return true; }
