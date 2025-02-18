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

int main(void) {
    Nameval *nvlist = NULL;
    nvlist = addfront(nvlist, newitem("data1", 10));
    Nameval *item = newitem("data2", 45);
    nvlist = addend(nvlist, item);
    nvlist = addend(nvlist, newitem("data3", 78));

    printf("List elements:\n");
    printlist(nvlist);

    return 0;
}
