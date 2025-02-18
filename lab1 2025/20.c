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

/* Count the length of chains in the hash table */
void analyze_distribution(int multiplier) {
    int lengths[NHASH] = {0};
    for (int i = 0; i < NHASH; i++) {
        Nameval *current = symtab[i];
        while (current) {
            lengths[i]++;
            current = current->next;
        }
    }
    printf("MULTIPLIER = %d\n", multiplier);
    for (int i = 0; i < NHASH; i++) {
        printf("Bucket %d: %d elements\n", i, lengths[i]);
    }
    printf("-------------------------\n");
}

/* Generate test data with poor hash distribution */
void generate_bad_data(int multiplier) {
    char *bad_strings[] = {
        "aaaa", "aaab", "aaac", "aaad", "aaae",
        "aaaf", "aaag", "aaah", "aaai", "aaaj"
    };
    int num_strings = sizeof(bad_strings) / sizeof(bad_strings[0]);
    for (int i = 0; i < num_strings; i++) {
        insert(bad_strings[i], i + 1, multiplier);
    }
    analyze_distribution(multiplier);
}

int main(void) {
    for (int multiplier = 31; multiplier <= 37; multiplier++) {
        memset(symtab, 0, sizeof(symtab));
        generate_bad_data(multiplier);
    }
    return 0;
}

/*
    Наскільки складно побудувати набір неправильних вхідних даних для різних значень NHASH?
   - Для малих значень NHASH відносно легко створити поганий розподіл. Чим менше NHASH, тим більше відбувається зіткнень. 
   - Для більших значень NHASH це стає складніше, але вибір структурованих вхідних даних 
   (наприклад, подібних префіксів) може погіршити продуктивність.
*/
