#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval {
    char *name;
    int value;
} Nameval;

typedef struct NVtab {
    int nval;             // поточна кількість значень
    int max;              // виділена кількість елементів
    Nameval *nameval;     // масив пар "ім'я-значення"
} NVtab;

NVtab nvtab = {0, 0, NULL}; // глобальна змінна

enum { NVINIT = 1, NVGROW = 2 }; // розмір для ініціалізації і зростання

// Функція для додавання нового елементу до nvtab
int addname(Nameval newname) {
    Nameval *nvp;

    if (nvtab.nameval == NULL) { // перший виклик
        nvtab.nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
        if (nvtab.nameval == NULL)
            return -1;
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    } else if (nvtab.nval >= nvtab.max) { // збільшення розміру масиву
        nvp = (Nameval *) realloc(nvtab.nameval, NVGROW * nvtab.max * sizeof(Nameval));
        if (nvp == NULL)
            return -1;
        nvtab.max *= NVGROW;
        nvtab.nameval = nvp;
    }
    nvtab.nameval[nvtab.nval++] = newname;
    return 0;
}

// Функція для видалення першого елементу з nvtab за ім'ям
int delname(char *name) {
    for (int i = 0; i < nvtab.nval; i++) {
        if (strcmp(nvtab.nameval[i].name, name) == 0) {
            memmove(&nvtab.nameval[i], &nvtab.nameval[i + 1], (nvtab.nval - i - 1) * sizeof(Nameval));
            nvtab.nval--;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    // Додавання елементів
    addname((Nameval){.name = "Andy", .value = 12});
    addname((Nameval){.name = "Billy", .value = 18});

    // Виведення всіх елементів
    for (int i = 0; i < nvtab.nval; i++) {
        printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
    }

    // Видалення елемента "Andy"
    delname("Andy");

    // Виведення оновленого списку
    for (int i = 0; i < nvtab.nval; i++) {
        printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
    }

    // Звільнення пам'яті
    free(nvtab.nameval);

    return 0;
}