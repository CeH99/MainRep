#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NHASH 11

/* Structure to store name and value */
typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *next;
} Nameval;

Nameval *symtab[NHASH];

/* Hash function with variable MULTIPLIER */
unsigned int hash(char *str, int multiplier) {
    unsigned int h = 0;
    unsigned char *p;
    for (p = (unsigned char *)str; *p != '\0'; p++) {
        h = multiplier * h + *p;
    }
    return h % NHASH;
}

/* Insert element into the hash table */
void insert(char *name, int value, int multiplier) {
    unsigned int h = hash(name, multiplier);
    Nameval *new_node = (Nameval *)malloc(sizeof(Nameval));
    new_node->name = name;
    new_node->value = value;
    new_node->next = symtab[h];
    symtab[h] = new_node;
}

/* TASK Iterate for the hole hash table */
void iterate_hash_table() {
    for (int i = 0; i < NHASH; i++) {
        Nameval *current = symtab[i];
        while (current) {
            printf("Name: %s, Value: %d\n", current->name, current->value);
            current = current->next;
        }
    }
}

int main(void) {
    insert("Alice", 10, 31);
    insert("Bob", 20, 31);
    insert("Charlie", 30, 31);
    insert("Dave", 40, 31);
    insert("Eve", 50, 31);
    
    printf("\nIterating over hash table:\n");
    iterate_hash_table();
    
    return 0;
}
