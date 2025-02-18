#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
    Nameval *left;  /* Nodes with smaller values */
    Nameval *right; /* Nodes with larger values */
};

/* Lookup: searches for a name in the tree */
Nameval *lookup(Nameval *treep, char *name) {
    if (treep == NULL)
        return NULL;
    int cmp = strcmp(name, treep->name);
    if (cmp == 0)
        return treep;
    else if (cmp < 0)
        return lookup(treep->left, name);
    else
        return lookup(treep->right, name);
}

/* Non-recursive lookup: searches for a name without recursion */
Nameval *nvlookup(Nameval *treep, char *name) {
    while (treep != NULL) {
        int cmp = strcmp(name, treep->name);
        if (cmp == 0)
            return treep;
        else if (cmp < 0)
            treep = treep->left;
        else
            treep = treep->right;
    }
    return NULL;
}

/* Insert: adds a new node (newp) to the tree */
Nameval *insert(Nameval *treep, Nameval *newp) {
    if (treep == NULL)
        return newp;
    int cmp = strcmp(newp->name, treep->name);
    if (cmp == 0)
        printf("Insert: duplicate entry %s ignored\n", newp->name);
    else if (cmp < 0)
        treep->left = insert(treep->left, newp);
    else
        treep->right = insert(treep->right, newp);
    return treep;
}

int main(void) {
    Nameval *treep = NULL;

    // Insert the first node
    struct Nameval new = {.name = "Andy", .value = 12};
    printf("%s %d\n", new.name, new.value);
    treep = insert(treep, &new);

    // Insert the second node
    treep = insert(treep, &(struct Nameval){.name = "Billy", .value = 18});

    // Perform a recursive lookup for "Billy"
    Nameval *res = lookup(treep, "Billy");
    printf("%s %d\n", res->name, res->value);

    // Perform a non-recursive lookup for "Andy"
    res = nvlookup(treep, "Andy");
    printf("%s %d\n", res->name, res->value);

    return 0;
}

/*
lookup витрачає більше пам'яті через стек рекурсії, може викликати переповнення при глибоких деревах.
nvlookup ефективніше працює з пам'яттю завдяки циклу.

Рекурсивна: компактний код, зрозуміла логіка, але витратна по пам'яті.
Ітераційна: надійна для глибоких дерев, але складніша в реалізації.
Рекомендація:

Рекурсія: для простоти, якщо дерево невелике.
Ітерація: для глибоких або великих дерев.*/