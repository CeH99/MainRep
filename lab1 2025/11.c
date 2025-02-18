#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
    Nameval *next; /* next in list */
};

/* newitem: create new item from name and value */
Nameval *newitem(char *name, int value) {
    Nameval *newp = (Nameval *)malloc(sizeof(Nameval));
    newp->name = strdup(name); // Виділяємо пам'ять для name
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

/* lookup: sequential search for name in listp */
Nameval *lookup(Nameval *listp, char *name) {
    for (; listp != NULL; listp = listp->next)
        if (strcmp(name, listp->name) == 0)
            return listp;
    return NULL; /* no match */
}

/* freeall: free all elements of listp */
void freeall(Nameval *listp) {
    Nameval *next;
    for (; listp != NULL; listp = next) {
        next = listp->next;
        free(listp->name); // Звільняємо пам'ять під name
        free(listp);
    }
}

//--------------------------------------------------------------------------------------

/* delitem: delete first "name" from listp */
Nameval *delitem(Nameval *listp, char *name) {
    Nameval *p, *prev;
    prev = NULL;
    for (p = listp; p != NULL; p = p->next) {
        if (strcmp(name, p->name) == 0) {
            if (prev == NULL)
                listp = p->next;
            else
                prev->next = p->next;
            free(p->name); // Звільняємо пам'ять під name
            free(p);
            return listp;
        }
        prev = p;
    }
    printf("delitem: %s not in list\n", name);
    return listp;
}

int main(void) {
    Nameval *nvlist = NULL;
    nvlist = addfront(nvlist, newitem("data1", 10));
    Nameval *item = newitem("data2", 45);
    nvlist = addend(nvlist, item);
    nvlist = addend(nvlist, newitem("data3", 78));

    printf("List elements:\n");
    printlist(nvlist);

    printf("\nDeleting 'data2'...\n");
    nvlist = delitem(nvlist, "data2");
    printlist(nvlist);

    freeall(nvlist); // Звільняємо всю пам'ять
    return 0;
}
