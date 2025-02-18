#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
};

struct NVtab {
    int nval;            /* Current number of elements */
    int max;             /* Allocated number of elements */
    Nameval *nameval;    /* Array of name-value pairs */
} nvtab;

enum { NVINIT = 1, NVGROW = 2 };

/* addname: adds a new element to nvtab */
int addname(Nameval newname) {
    Nameval *nvp;

    if (nvtab.nameval == NULL) { /* First-time allocation */
        nvtab.nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
        if (nvtab.nameval == NULL)
            return -1;
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    } else if (nvtab.nval >= nvtab.max) { /* Increase size */
        nvp = (Nameval *) realloc(nvtab.nameval,
                                  (NVGROW * nvtab.max) * sizeof(Nameval));
        if (nvp == NULL)
            return -1;
        nvtab.max *= NVGROW;
        nvtab.nameval = nvp;
    }
    nvtab.nameval[nvtab.nval++] = newname;
    return 0;
}

/* delname: removes the first matching name-value pair from nvtab */
int delname(char *name) {
    for (int i = 0; i < nvtab.nval; i++) {
        if (strcmp(nvtab.nameval[i].name, name) == 0) {
            memmove(nvtab.nameval + i, nvtab.nameval + i + 1,
                    (nvtab.nval - (i + 1)) * sizeof(Nameval));
            nvtab.nval--;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int curNum = addname((Nameval) {.name = "Andy", .value = 12});
    printf("%d\n", curNum);

    curNum = addname((Nameval) {.name = "Billy", .value = 18});
    printf("%d\n", curNum);

    for (int i = 0; i < nvtab.nval; i++) {
        printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
    }

    return 0;
}

/*
Відповіді на питання:

1. Чи правильно в цьому випадку не використовувати функцію realloc?
   - Так, це виправдано, оскільки часте перевиділення пам'яті після кожного видалення може призвести до великих витрат продуктивності.
   - Видалена пам'ять буде використовуватися при додаванні нових елементів, тому її можна не звільняти відразу.

2. Чи можливо реалізувати поставлені у прикладі задачі іншим шляхом?
   - Так, можна використовувати зв'язний список замість масиву. Це дозволить ефективно вставляти і видаляти елементи без необхідності зміщувати масив.
   - Ще один варіант — використання хеш-таблиці для швидкого пошуку та видалення.

3. Який варіант вирішення буде кращим?
   - Якщо кількість елементів невелика і видалення відбувається рідко, масив — це просте і ефективне рішення.
   - Якщо видалення та вставка виконуються часто, краще використовувати зв'язний список.
   - Якщо потрібен дуже швидкий пошук та видалення, найкращим рішенням буде хеш-таблиця.
*/ 
