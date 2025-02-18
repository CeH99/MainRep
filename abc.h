#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void printArray(int *arr, int size) {
    for (const int *p = arr; p < arr + size; p++) {
        printf("%d ", *p);
    }
    printf("\n\n");
}

void print2DArray(int arr[][20], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortDescending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSort2D(int *arr, int rows, int cols) {
    bubbleSort(arr, rows * cols);
}

void shellSort(int *arr, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int *i = arr + gap; i < arr + size; i++) {
            int temp = *i;
            int *j;
            for (j = i; j >= arr + gap && *(j - gap) > temp; j -= gap) {
                *j = *(j - gap);
            }
            *j = temp;
        }
    }
}

void shellSort2D(int *arr, int rows, int cols) {
    shellSort(arr, rows * cols);
}

int *partition(int *low, int *high) {
    int pivot = *high;
    int *i = low - 1;
    for (int *j = low; j < high; j++) {
        if (*j <= pivot) {
            i++;
            int temp = *i;
            *i = *j;
            *j = temp;
        }
    }
    int temp = *(i + 1);
    *(i + 1) = *high;
    *high = temp;
    return i + 1;
}

void quickSort(int *low, int *high) {
    if (low < high) {
        int *pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void quickSort2D(int *arr, int rows, int cols) {
    quickSort(arr, arr + rows * cols - 1);
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void selectionSort2D(int* arr, int rows, int cols) {
    int totalElements = rows * cols;
    for (int i = 0; i < totalElements - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < totalElements; j++) {
            if (*(arr + j) < *(arr + minIndex)) {
                minIndex = j;
            }
        }
        int temp = *(arr + minIndex);
        *(arr + minIndex) = *(arr + i);
        *(arr + i) = temp;
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void insertionSort2D(int* arr, int rows, int cols) {
    int size = rows * cols;

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void reverseArray2D(int arr[][20], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[i][cols - j - 1];
            arr[i][cols - j - 1] = temp;
        }
    }
}

void transposeArray2D(int* arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            int temp = *((arr + i * cols) + j);
            *((arr + i * cols) + j) = *((arr + j * cols) + i);
            *((arr + j * cols) + i) = temp;
        }
    }
}

void reverseArray2D180(int* arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            int temp = *(arr + i * cols + j);
            *(arr + i * cols + j) = *(arr + i * cols + (cols - j - 1));
            *(arr + i * cols + (cols - j - 1)) = temp;
        }
    }

    for (int i = 0; i < rows / 2; i++) {
        for (int j = 0; j < cols; j++) {
            int temp = *(arr + i * cols + j);
            *(arr + i * cols + j) = *(arr + (rows - i - 1) * cols + j);
            *(arr + (rows - i - 1) * cols + j) = temp;
        }
    }
}

void reverseArray(int size, int arr[]) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fillArray(int *arr, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = ((float)rand() / RAND_MAX) * 200.0 - 100.0;
    }
}

void fill2DArray(int* arr, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(arr + i * cols + j) = rand() % 100; 
        }
    }
}


int Validfordigits(const char *str) {
    int has_decimal_point = 0;
    int has_digits = 0;       

    if (*str == '\0') {
        return 0;
    }
    if (*str == '-' || *str == '+') {
        str++;
    }

    while (*str != '\0') {
        if (*str == ',') {
            if (has_decimal_point) {
                return 0;
            }
            has_decimal_point = 1; 
        } else if (isdigit((unsigned char)*str)) {
            has_digits = 1; 
        } else {
            return 0;
        }
        str++;
    }
    return has_digits;
}

