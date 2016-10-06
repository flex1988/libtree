#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#define OK 1
#define ERR 0

#define PERF 1

typedef struct node {
    struct node *left;
    struct node *right;
    int val;
} node;

node *create_node(int val);
node *search_tree(node *t,int val);
int insert_node(node* t,node *n);
int delete_node(node* t,int val);
void free_node(node *t);
#endif
