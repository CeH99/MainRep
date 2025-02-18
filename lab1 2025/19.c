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

/* Generate test data */
void generate_data(int multiplier) {
    char *test_strings[] = {
        "abc", "abcd", "abcde", "abcdef", "abcdefg",
        "url1", "url2", "url3", "url4", "url5",
        "test1", "test2", "test3", "test4", "test5"
    };
    int num_strings = sizeof(test_strings) / sizeof(test_strings[0]);
    for (int i = 0; i < num_strings; i++) {
        insert(test_strings[i], i + 1, multiplier);
    }
    analyze_distribution(multiplier);
}

int main(void) {
    for (int multiplier = 31; multiplier <= 37; multiplier++) {
        memset(symtab, 0, sizeof(symtab)); // 1 - що мтреба заповнити, 2 - значення, яким потрібно заповнити пам'ять, 3 - кількість байтів, які потрібно заповнити
        generate_data(multiplier);
    }
    return 0;
}

/*
Answers to the questions:
    Щоб змусити хеш-функцію працювати погано, можна зробити так щоб:

    Всі рядки мають однакову структуру та відрізняються лише останніми символами (наприклад, "aaaa", "aaab", "aaac").
    Вибраний MULTIPLIER спричиняє поганий розподіл (наприклад, множник, що викликає багато однакових остач при mod NHASH).
    Значення NHASH занадто мале, що збільшує ймовірність колізій.

1. Наскільки добре хеш-функції кодують короткі та довгі рядки? 
   - Короткі рядки зазвичай розподіляються рівномірно, але довші можуть створювати більше колізій через накопичений вплив символів.

2. Що можна сказати про струни однакової довжини з незначними відмінностями?
   - Якщо відмінності полягають в останніх символах, хеш може істотно змінитися, але подібні префікси можуть призвести до колізій.

3. Як МНОЖНИК впливає на розподіл?
   - Деякі значення MULTIPLIER (наприклад, 31 або 37) можуть забезпечити більш рівномірний розподіл, зменшуючи надмірні зіткнення.
*/
