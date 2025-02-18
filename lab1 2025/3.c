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

// Функція для додавання нового Nameval у nvtab
int addname(Nameval newname) {
    Nameval *nvp;
    if (nvtab.nameval == NULL) {  // Перший виклик
        nvtab.nameval = (Nameval *)malloc(NVINIT * sizeof(Nameval));
        if (nvtab.nameval == NULL)
            return -1; // Помилка виділення пам'яті
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    } else if (nvtab.nval >= nvtab.max) { // Розширення
        nvp = (Nameval *)realloc(nvtab.nameval, 
                (NVGROW * nvtab.max) * sizeof(Nameval));
        if (nvp == NULL)
            return -1; // Помилка виділення пам'яті
        nvtab.max *= NVGROW;
        nvtab.nameval = nvp;
    }
    nvtab.nameval[nvtab.nval] = newname;
    return nvtab.nval++;
}

// Основна функція
int main(void) {
    // Додавання елементів до масиву
    addname((Nameval){.name = "Andy", .value = 12});
    addname((Nameval){.name = "Billy", .value = 18});

    // Створюємо вказівник на перший елемент масиву
    Nameval *ptr = &nvtab.nameval[0];

    // Виводимо елементи через вказівники
    printf("Pointer access before realloc:\n");
    printf("Name: %s, Value: %d\n", ptr->name, ptr->value);

    // Додаємо новий елемент, що викликає realloc
    addname((Nameval){.name = "Charlie", .value = 25});

    // Спроба доступу через старий вказівник після realloc
    printf("\nPointer access after realloc:\n");
    printf("Name: %s, Value: %d\n", ptr->name, ptr->value); // Можлива помилка!

    // Коректний доступ через індекси
    printf("\nCorrect access via index after realloc:\n");
    for (int i = 0; i < nvtab.nval; i++) {
        printf("Index %d -> Name: %s, Value: %d\n", i, nvtab.nameval[i].name, nvtab.nameval[i].value);
    }

    return 0;
}
/*Звернення через вказівник:

До realloc доступ через вказівник ptr працює коректно.
Після realloc вказівник ptr може вказувати на недійсну пам'ять, що викликає непередбачувану поведінку.
Коректний доступ через індекси:

Навіть після realloc доступ через індекси працює правильно, оскільки nvtab.nameval оновлюється після зміни адреси масиву.*/