#include "btree.h"
#include <stdio.h>

int main(){
    Tree *t = btree_create("/tmp/");
    if(!t){
        printf("create btree failed!");
        return 0;
    }
    printf("%d",t->height);
    return 0;
}
