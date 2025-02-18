#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
    Nameval *left;
    Nameval *right;
};

Nameval *insert(Nameval *treep, Nameval *newp) {
    if (treep == NULL)
        return newp;
    int cmp = strcmp(newp->name, treep->name);
    if (cmp < 0)
        treep->left = insert(treep->left, newp);
    else if (cmp > 0)
        treep->right = insert(treep->right, newp);
    return treep;
}

void collect_inorder(Nameval *treep, Nameval **array, int *index) {
    if (treep == NULL)
        return;
    collect_inorder(treep->left, array, index);
    array[*index] = treep;
    (*index)++;
    collect_inorder(treep->right, array, index);
}

void free_tree(Nameval *treep) {
    if (treep == NULL)
        return;
    free_tree(treep->left);
    free_tree(treep->right);
    free(treep->name); 
    free(treep);
}

int main(void) {
    Nameval *treep = NULL;

    treep = insert(treep, &(Nameval){.name = strdup("Andy"), .value = 12});
    treep = insert(treep, &(Nameval){.name = strdup("Billy"), .value = 18});
    treep = insert(treep, &(Nameval){.name = strdup("Charlie"), .value = 15});

    const int n = 3;
    Nameval *array[n];
    int index = 0;

    collect_inorder(treep, array, &index);

    printf("Sorted order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", array[i]->name, array[i]->value);
    }

    free_tree(treep);

    return 0;
}
