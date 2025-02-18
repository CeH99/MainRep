#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval {
    char *name;
    int value;
} Nameval;

typedef struct NVtab {
    int nval;             // current number of values
    int max;              // allocated number of elements
    Nameval *nameval;     // array of name-value pairs
} NVtab;

NVtab nvtab = {0, 0, NULL}; // global variable

enum { NVINIT = 1, NVGROW = 2 }; // size for initialization and growth

// Function to add a new element to nvtab
int addname(Nameval newname) {
    //TASK: Reuse deleted slots if available
    for (int i = 0; i < nvtab.nval; i++) {
        if (nvtab.nameval[i].name == NULL) { // Using deleted slot
            nvtab.nameval[i] = newname;
            return 0;
        }
    }
    
    // If no free slots, expand the array
    if (nvtab.nameval == NULL) {
        nvtab.nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
        if (nvtab.nameval == NULL)
            return -1;
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    } else if (nvtab.nval >= nvtab.max) {
        Nameval *nvp = (Nameval *) realloc(nvtab.nameval, NVGROW * nvtab.max * sizeof(Nameval));
        if (nvp == NULL)
            return -1;
        nvtab.max *= NVGROW;
        nvtab.nameval = nvp;
    }
    nvtab.nameval[nvtab.nval++] = newname;
    return 0;
}

// Function to logically delete an element
int delname(char *name) {
    //TASK: Mark deleted element as unused instead of shifting
    for (int i = 0; i < nvtab.nval; i++) {
        if (nvtab.nameval[i].name != NULL && strcmp(nvtab.nameval[i].name, name) == 0) {
            free(nvtab.nameval[i].name); // Free memory for the name
            nvtab.nameval[i].name = NULL; // Mark element as "unused"
            return 1;
        }
    }
    return 0;
}

int main(void) {
    // Adding elements
    addname((Nameval){.name = strdup("Andy"), .value = 12});
    addname((Nameval){.name = strdup("Billy"), .value = 18});
    addname((Nameval){.name = strdup("Charlie"), .value = 25});

    // Displaying all elements
    printf("Before deletion:\n");
    for (int i = 0; i < nvtab.nval; i++) {
        if (nvtab.nameval[i].name != NULL)
            printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
    }

    // Deleting "Andy"
    delname("Andy");

    // Displaying updated list
    printf("After deletion:\n");
    for (int i = 0; i < nvtab.nval; i++) {
        if (nvtab.nameval[i].name != NULL)
            printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
    }

    // Freeing memory
    for (int i = 0; i < nvtab.nval; i++) {
        if (nvtab.nameval[i].name != NULL)
            free(nvtab.nameval[i].name);
    }
    free(nvtab.nameval);
    
    return 0;
}
