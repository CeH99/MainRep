#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Binary Tree Node Structure
typedef struct Nameval Nameval;
struct Nameval {
    char *name;
    int value;
    Nameval *left;
    Nameval *right;
};

// Insert a node into the binary tree
Nameval *insert(Nameval *treep, Nameval *newp) {
    if (treep == NULL)
        return newp;
    int cmp = strcmp(newp->name, treep->name);
    if (cmp < 0)
        treep->left = insert(treep->left, newp);
    else if (cmp > 0)
        treep->right = insert(treep->right, newp);
    return treep;
}

// Recursive lookup
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

// Iterative lookup
Nameval *nrlookup(Nameval *treep, char *name) {
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

// In-order traversal
void applyinorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg) {
    if (treep == NULL)
        return;
    applyinorder(treep->left, fn, arg);
    fn(treep, arg);
    applyinorder(treep->right, fn, arg);
}

// Function to print a node
void printnode(Nameval *p, void *arg) {
    char *fmt = (char *)arg;
    printf(fmt, p->name, p->value);
}

// Test suite
void run_tests() {
    printf("Running tests...\n");

    // Create a test tree
    Nameval *treep = NULL;
    treep = insert(treep, &(Nameval){.name = "Charlie", .value = 15});
    treep = insert(treep, &(Nameval){.name = "Andy", .value = 12});
    treep = insert(treep, &(Nameval){.name = "Billy", .value = 18});

    // Test 1: Lookup (recursive)
    Nameval *res = lookup(treep, "Andy");
    if (res && res->value == 12)
        printf("Test 1 passed: Recursive lookup\n");
    else
        printf("Test 1 failed: Recursive lookup\n");

    // Test 2: Lookup (iterative)
    res = nrlookup(treep, "Billy");
    if (res && res->value == 18)
        printf("Test 2 passed: Iterative lookup\n");
    else
        printf("Test 2 failed: Iterative lookup\n");

    // Test 3: In-order traversal
    printf("Test 3: In-order traversal\n");
    applyinorder(treep, printnode, "%s: %d\n");

    // Test 4: Lookup non-existent node
    res = lookup(treep, "Daniel");
    if (res == NULL)
        printf("Test 4 passed: Lookup non-existent node\n");
    else
        printf("Test 4 failed: Lookup non-existent node\n");

    // Test 5: Iterative lookup for non-existent node
    res = nrlookup(treep, "Emma");
    if (res == NULL)
        printf("Test 5 passed: Iterative lookup non-existent node\n");
    else
        printf("Test 5 failed: Iterative lookup non-existent node\n");

    printf("All tests completed.\n");
}

int main(void) {
    run_tests();
    return 0;
}
