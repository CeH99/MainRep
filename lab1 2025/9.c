#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
    Nameval *next;
};

/* newitem: create new item from name and value */
Nameval *newitem(char *name, int value) {
    Nameval *newp = (Nameval *) malloc(sizeof(Nameval));
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

/* copylist: create a copy of the given list */
Nameval *copylist(Nameval *listp) {
    if (listp == NULL) return NULL;
    Nameval *newlist = newitem(listp->name, listp->value);
    Nameval *curr = newlist;
    for (Nameval *p = listp->next; p != NULL; p = p->next) {
        curr->next = newitem(p->name, p->value);
        curr = curr->next;
    }
    return newlist;
}

/* merge: merge two lists */
Nameval *merge(Nameval *list1, Nameval *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    Nameval *p = list1;
    while (p->next != NULL) p = p->next;
    p->next = list2;
    return list1;
}

/* splitlist: split the list into two halves */
void splitlist(Nameval *listp, Nameval **first, Nameval **second) {
    if (listp == NULL || listp->next == NULL) {
        *first = listp;
        *second = NULL;
        return;
    }
    Nameval *slow = listp, *fast = listp->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *first = listp;
    *second = slow->next;
    slow->next = NULL;
}

/* insertbefore: insert newp before specific element */
Nameval *insertbefore(Nameval *listp, Nameval *newp, char *before) {
    if (listp == NULL) return newp;
    if (listp->name == before) {
        newp->next = listp;
        return newp;
    }
    Nameval *p = listp;
    while (p->next && p->next->name != before) p = p->next;
    if (p->next) {
        newp->next = p->next;
        p->next = newp;
    }
    return listp;
}

/* insertafter: insert newp after specific element */
void insertafter(Nameval *listp, Nameval *newp, char *after) {
    while (listp && listp->name != after) listp = listp->next;
    if (listp) {
        newp->next = listp->next;
        listp->next = newp;
    }
}

/* printlist: print the list */
void printlist(Nameval *listp) {
    for (; listp != NULL; listp = listp->next)
        printf("%s %d -> ", listp->name, listp->value);
    printf("NULL\n");
}

int main(void) {
    Nameval *nvlist = NULL;
    nvlist = addfront(nvlist, newitem("data1", 10));
    nvlist = addend(nvlist, newitem("data2", 45));
    nvlist = addend(nvlist, newitem("data3", 30));

    printf("Original List: ");
    printlist(nvlist);

    Nameval *copy = copylist(nvlist);
    printf("Copied List: ");
    printlist(copy);

    Nameval *half1, *half2;
    splitlist(nvlist, &half1, &half2);
    printf("First Half: ");
    printlist(half1);
    printf("Second Half: ");
    printlist(half2);

    Nameval *merged = merge(half1, half2);
    printf("Merged List: ");
    printlist(merged);

    nvlist = insertbefore(nvlist, newitem("before_data2", 99), "data2");
    printf("List after inserting before data2: ");
    printlist(nvlist);

    insertafter(nvlist, newitem("after_data1", 77), "data1");
    printf("List after inserting after data1: ");
    printlist(nvlist);

    return 0;
}

/*
Відповіді на питання:
1. Вставка перед елементом складніша, бо потрібно знайти попередній елемент перед тим, у який вставляємо.
2. Вставка після елемента простіша, бо достатньо знайти елемент і змінити його next.
3. Функції зі списками, такі як додавання в початок/кінець, частково можна було використати.
4. Довелося написати копіювання, злиття, розбиття та вставку перед/після.
*/
