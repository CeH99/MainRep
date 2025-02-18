#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 11
#define MULTIPLIER 31
#define LOAD_FACTOR 3
#define GROWTH_FACTOR 2

typedef struct Nameval {
    char *name;
    int value;
    struct Nameval *next;
} Nameval;

int table_size = INITIAL_SIZE;
int num_elements = 0;
Nameval **hash_table;

unsigned int hash(char *str) {
    unsigned int h = 0;
    while (*str)
        h = h * MULTIPLIER + *str++;
    return h % table_size;
}

// Function to resize the hash table
void resize_table() {
    int old_size = table_size;
    table_size *= GROWTH_FACTOR;
    Nameval **new_table = malloc(table_size * sizeof(Nameval *));
    for (int i = 0; i < table_size; i++)
        new_table[i] = NULL;
    
    for (int i = 0; i < old_size; i++) {
        Nameval *entry = hash_table[i];
        while (entry) {
            Nameval *next = entry->next;
            int new_index = hash(entry->name);
            entry->next = new_table[new_index];
            new_table[new_index] = entry;
            entry = next;
        }
    }
    free(hash_table);
    hash_table = new_table;
}

Nameval *lookup(char *name, int create, int value) {
    if (num_elements / table_size > LOAD_FACTOR)
        resize_table();
    
    int index = hash(name);
    Nameval *entry = hash_table[index];
    while (entry) {
        if (strcmp(entry->name, name) == 0)
            return entry;
        entry = entry->next;
    }
    
    if (create) {
        entry = malloc(sizeof(Nameval));
        entry->name = strdup(name);
        entry->value = value;
        entry->next = hash_table[index];
        hash_table[index] = entry;
        num_elements++;
    }
    return entry;
}

int main() {
    hash_table = malloc(table_size * sizeof(Nameval *));
    for (int i = 0; i < table_size; i++)
        hash_table[i] = NULL;
    
    lookup("Billy", 1, 12);
    lookup("Alice", 1, 25);
    lookup("Bob", 1, 37);
    lookup("Charlie", 1, 49);
    lookup("Dave", 1, 50);
    lookup("Eve", 1, 75);
    lookup("Frank", 1, 88);
    
    Nameval *node = lookup("Billy", 0, 0);
    if (node)
        printf("%s %d\n", node->name, node->value);
    
    return 0;
}