#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int value;
} Nameval;

void delname(Nameval array[], int *nval, int indexToDelete) {
    if (indexToDelete < 0 || indexToDelete >= *nval) {
        printf("Invalid index!\n");
        return;
    }

    // if element is last
    if (indexToDelete == *nval - 1) {
        (*nval)--;
    } else {
        // moving last element on pos where we deleted smth
        array[indexToDelete] = array[*nval - 1];
        (*nval)--;
    }
}

void printArray(Nameval array[], int nval) {
    for (int i = 0; i < nval; i++) {
        printf("[%d] Name: %s, Value: %d\n", i, array[i].name, array[i].value);
    }
}

int main() {
    Nameval array[MAX] = {
        {"Alice", 10},
        {"Bob", 20},
        {"Charlie", 30},
        {"Diana", 40},
    };

    int nval = 4; // size 

    printf("Initial array:\n");
    printArray(array, nval);

    // deleting
    int indexToDelete;
    printf("\nEnter index to delete: ");
    scanf("%d", &indexToDelete);

    delname(array, &nval, indexToDelete);

    printf("\nArray after deletion:\n");
    printArray(array, nval);

    return 0;
}
