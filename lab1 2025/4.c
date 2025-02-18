#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура Nameval для збереження імені та значення
typedef struct Nameval {
    char *name;
    int value;
} Nameval;

// Структура NVtab для керування динамічним масивом Nameval
struct NVtab {
    int nval;            // Поточна кількість елементів
    int max;             // Максимальна кількість виділених елементів
    Nameval *nameval;    // Вказівник на масив Nameval
} nvtab;

// Константи ініціалізації
enum { NVINIT = 1, NVGROW = 2 };

// Функція для додавання нового Nameval у nvtab (небезпечний спосіб)
int addname_dangerous(Nameval newname) {
    if (nvtab.nameval == NULL) { // Перший виклик
        nvtab.nameval = (Nameval *)malloc(NVINIT * sizeof(Nameval));
        if (nvtab.nameval == NULL)
            return -1; // Помилка виділення пам'яті
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    } else if (nvtab.nval >= nvtab.max) { // Розширення
        nvtab.nameval = (Nameval *)realloc(nvtab.nameval, (NVGROW * nvtab.max) * sizeof(Nameval));
        // Якщо realloc поверне NULL, nvtab.nameval втратить доступ до старих даних
        if (nvtab.nameval == NULL)
            return -1; // Втрата всіх даних
        nvtab.max *= NVGROW;
    }
    nvtab.nameval[nvtab.nval] = newname;
    return nvtab.nval++;
}

// Функція для додавання нового Nameval у nvtab (безпечний спосіб)
int addname_safe(Nameval newname) {
    Nameval *nvp;
    if (nvtab.nameval == NULL) { // Перший виклик
        nvtab.nameval = (Nameval *)malloc(NVINIT * sizeof(Nameval));
        if (nvtab.nameval == NULL)
            return -1; // Помилка виділення пам'яті
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    } else if (nvtab.nval >= nvtab.max) { // Розширення
        nvp = (Nameval *)realloc(nvtab.nameval, (NVGROW * nvtab.max) * sizeof(Nameval));
        if (nvp == NULL) {
            printf("Error: Memory allocation failed. Data preserved.\n");
            return -1; // Помилка, але дані збережено
        }
        nvtab.nameval = nvp; // Оновлюємо вказівник тільки після успіху
        nvtab.max *= NVGROW;
    }
    nvtab.nameval[nvtab.nval] = newname;
    return nvtab.nval++;
}

// Основна функція
int main(void) {
    // Ініціалізуємо масив
    nvtab.nameval = NULL;
    nvtab.nval = 0;
    nvtab.max = 0;

    // Додаємо елементи, використовуючи небезпечний спосіб
    if (addname_dangerous((Nameval){.name = "Andy", .value = 12}) == 0) {
        printf("Error in addname_dangerous. All data lost.\n");
    }

    if (addname_dangerous((Nameval){.name = "Billy", .value = 18}) == 0) {
        printf("Error in addname_dangerous. All data lost.\n");
    }

    // Імітуємо брак пам'яті
    printf("\nSwitching to safe method...\n");

    // Додаємо елементи, використовуючи безпечний спосіб
    if (addname_safe((Nameval){.name = "Charlie", .value = 25}) == -1) {
        printf("Error in addname_safe. Data preserved.\n");
    }

    // Виводимо вміст масиву
    for (int i = 0; i < nvtab.nval; i++) {
        printf("Index %d -> Name: %s, Value: %d\n", i, nvtab.nameval[i].name, nvtab.nameval[i].value);
    }

    return 0;
}
