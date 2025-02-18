#include <stdio.h>
#include <stdlib.h>

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
    Nameval *next; /* next in list */
};

/* newitem: create new item from name and value */
Nameval *newitem(char *name, int value) {
    Nameval *newp = (Nameval *)malloc(sizeof(Nameval));
    newp->name = name;
    newp->value = value;
    newp->next = NULL;
    return newp;
}

/* addfront: add newp to front of listp */
Nameval *addfront(Nameval *listp, Nameval *newp) {
    newp->next = listp;
    return newp;
}

/* addend: add newp to end of listp */
Nameval *addend(Nameval *listp, Nameval *newp) {
    if (listp == NULL) return newp;
    Nameval *p;
    for (p = listp; p->next != NULL; p = p->next);
    p->next = newp;
    return listp;
}

/* printlist: print all elements in the list */
void printlist(Nameval *listp) {
    for (Nameval *p = listp; p != NULL; p = p->next) {
        printf("%s %d\n", p->name, p->value);
    }
}

/* Iterative reverse_list */
Nameval *reverse_list_iterative(Nameval *listp) {
    Nameval *prev = NULL, *current = listp, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/* Recursive reverse_list */
Nameval *reverse_list_recursive(Nameval *listp, Nameval *prev) {
    if (listp == NULL) return prev;
    Nameval *next = listp->next;
    listp->next = prev;
    return reverse_list_recursive(next, listp);
}

int main(void) {
    Nameval *nvlist = NULL;
    nvlist = addfront(nvlist, newitem("data1", 10));
    nvlist = addend(nvlist, newitem("data2", 45));
    nvlist = addend(nvlist, newitem("data3", 78));

    printf("Original List:\n");
    printlist(nvlist);
    
    nvlist = reverse_list_iterative(nvlist);
    printf("\nReversed List (Iterative):\n");
    printlist(nvlist);
    
    nvlist = reverse_list_recursive(nvlist, NULL);
    printf("\nReversed List (Recursive):\n");
    printlist(nvlist);

    return 0;
}
