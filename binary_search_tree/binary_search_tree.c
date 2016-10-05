#include "binary_search_tree.h"
#include "assert.h"
#include "stdlib.h"

node *create_node(int val) {
    node *n = (node *)malloc(sizeof(n));
    n->left = NULL;
    n->right = NULL;
    n->val = val;
    return n;
}

node *search_tree(node *t, int val) {
    if (t == NULL)
        return NULL;
    if (t->val == val)
        return t;
    if (t->val < val)
        return search_tree(t->right, val);
    else
        return search_tree(t->left, val);
}

int insert_node(node *t, node *n) {
    assert(t && n);

    if (n->val == t->val)
        return ERR;
    else if (n->val > t->val) {
        if (t->right == NULL) {
            t->right = n;
            return OK;
        } else {
            return insert_node(t->right, n);
        }
    } else {
        if (t->left == NULL) {
            t->left = n;
            return OK;
        } else {
            return insert_node(t->left, n);
        }
    }
    return OK;
}

int delete_node(node *t, int val) {
    if (!t)
        return ERR;

    node *s = search_tree(t, val);
    /*没有节点*/
    if (s == NULL)
        return ERR;
    /*无左右节点的情况*/
    if (!s->left && !s->right) {
        free(s);
        s = NULL;
        return OK;
    }

    if (!s->left) {
        free(s);
        s = s->right;
        return OK;
    }

    if (!s->right) {
        free(s);
        s = s->left;
        return OK;
    }

    if (s->left && s->right) {
        node *p, *q;
        p = s;
        q = s->right;

        while (q->left != NULL) {
            p = q;
            q = q->left;
        }

        s->val = q->val;

        if (s == p)
            s->right = q->right;
        else
            s->left = q->right;

        free(q);
        q = NULL;
        return OK;
    }
    abort();
}

void free_node(node *t) {
    if (t == NULL)
        return;
    if (t->left)
        free_node(t->left);
    if (t->right)
        free_node(t->right);

    free(t);
    t = NULL;
}
