#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NHASH 11
#define MULTIPLIER 31

typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *next; /* next in chain */
} Nameval;

Nameval *symtab[NHASH]; /* a symbol table */

/* hash: compute hash value of string */
unsigned int hash(char *str) {
    unsigned int h = 0;
    unsigned char *p;
    for (p = (unsigned char *)str; *p != '\0'; p++) {
        h = MULTIPLIER * h + *p;
    }
    return h % NHASH;
}

/* lookup: find name in symtab, with optional create */
Nameval *lookup(char *name, int create, int value) {
    Nameval *sym;
    int h = hash(name);
    for (sym = symtab[h]; sym != NULL; sym = sym->next) {
        if (strcmp(name, sym->name) == 0)
            return sym;
    }
    if (create) {
        sym = (Nameval *)malloc(sizeof(Nameval));
        sym->name = name; /* assumed allocated elsewhere */
        sym->value = value;
        sym->next = symtab[h];
        symtab[h] = sym;
    }
    return sym;
}

int main(void) {
    Nameval *node = lookup("Billy", 1, 12);
    printf("%s %d\n", node->name, node->value);
    return 0;
}

/*
Відповіді на питання:
1. Яким повинен бути розмір масиву symtab у цьому прикладі?
   - У прикладі масив symtab має розмір NHASH = 11, що є простим числом.
   - Розмір обраний для зменшення колізій і оптимізації роботи хеш-функції.

2. Чому важливий вибір розміру масиву?
   - Масив повинен бути достатньо великим, щоб мінімізувати довжину ланцюжків, і кожна операція пошуку мала ефективність O(1).
   - Розмір має бути простим числом, що зменшує кількість колізій при хешуванні.

3. Як змінити розмір для великої кількості елементів?
   - Якщо очікується більше елементів, наприклад 50-100, слід збільшити NHASH до 101, 103 або іншого простого числа близько цієї кількості.
*/
