#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define LENGTH_FILE 256

typedef struct {
    char region[LENGTH_FILE];
    float area;
    float population;
} Record;

void Create_File(char* name);
void Read_File(char* name);
void Delete_File(char* name);

void WriteToFile(char* name);
void Create_Record(Record *record);
void Paste_Record(char* name);
void Read_Record(char* name);
void Edit_Record(char* name);
void Sort_Records(char* name);
void Delete_Record(char* name);

int Get_Name(char *name, int choice);
int Valid_Name(char* name);
int ValidInputI(int* num, int minimum, int maximum);
int File_Exists(char *name);
void NewYear();

int main() {
    int choice = -1;
    char name[MAX_LENGTH] = "";
    int fileSelected = 0;
    int show = 5;
    NewYear();
    while (choice != 0) {
        if(show == 5){
            printf("\n\t\t Menu\n");
            printf("\033[32mFile mode:\t\tRecords mode:\033[0m\n");
            printf("1 - create file \t 4 - create record\n");
            printf("2 - read file \t\t 5 - read record\n");
            printf("3 - delete file \t 6 - edit record\n");
            printf(" \t\t\t 7 - sort record\n");
            printf(" \t\t\t 8 - paste record\n");
            printf(" \t\t\t 9 - delete record\n");
            printf(" \t\t\t 10 - select the file\n");
            printf(" \t 0 - exit the program\n");
        }
        if(show == 5){
            show = 0;
        }
        show++;

        printf("\033[32mChoose the option:\033[0m\n-> ");
        if (!ValidInputI(&choice, 0, 10)) {
            continue;
        }

        if ((choice >= 2 && choice <= 9) && !fileSelected) {
            printf("Error: No file selected. Please select or create a file first.\n");
            continue;
        }

        if (choice == 1) {
            Get_Name(name, choice);
            fileSelected = 1;
        }

        switch (choice) {
            case 0:
                printf("Exiting the program.\n");
                break;
            case 1:
                if (strcmp(name, "q") == 0)
                    break;
                else
                Create_File(name);
                break;
            case 2:
                Read_File(name);
                break;
            case 3:
                Delete_File(name);
                break;
            case 4:
                WriteToFile(name);
                break;
            case 5:
                Read_Record(name);
                break;
            case 6:
                Edit_Record(name);
                break;
            case 7:
                Sort_Records(name);
                break;
            case 8:
                Paste_Record(name);
                break;
            case 9:
                Delete_Record(name);
                break;
            case 10:
                Get_Name(name, choice);
                fileSelected = 1;
                break;
            default:
                printf("Invalid choice or unimplemented functionality.\n");
                break;
        }
    }

    return 0;
}

void Create_File(char* name) {
    char filename[MAX_LENGTH]; 
    // Формуємо ім'я файлу з розширенням .txt
    sprintf(filename, "%s.txt", name);

    // Перевірка, чи існує файл із заданим ім'ям
    if (File_Exists(name)) {
        printf("Error: File '%s' already exists.\n", name);
        return;
    }

    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "Anne\n");
        printf("File '%s.txt' created successfully.\n", name);
        fclose(file);
    } else {
        printf("Error creating file");
    }
}

void Read_File(char* name) {
    char filename[MAX_LENGTH];
    // Формуємо ім'я файлу з розширенням .txt
    snprintf(filename, sizeof(filename), "%s.txt", name);
    
    FILE* file = fopen(filename, "r");

    if (file != NULL) {
        char ch;
        printf("Contents of file %s:\n", name);
        
        // Зчитуємо файл символ за символом до кінця
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch); // Виводимо символ на екран
        }
        
        fclose(file);
        printf("\n");
    } else {
        printf("File '%s' is missing.\n", name);
    }
}

void Delete_File(char* name) {
    char filename[MAX_LENGTH];
    // Формуємо ім'я файлу з розширенням .txt
    snprintf(filename, sizeof(filename), "%s.txt", name);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File '%s' doesn't exist or cannot be opened.\n", filename);
        return;
    }

    char firstLine[LENGTH_FILE];
    // Зчитуємо перший рядок файлу
    if (fgets(firstLine, sizeof(firstLine), file) != NULL) {
        // Видаляємо символ нового рядка з кінця першого рядка
        firstLine[strcspn(firstLine, "\n")] = 0;

        // Перевіряємо підпис "Anne"
        if (strcmp(firstLine, "Anne") == 0) {
            fclose(file);

            // Видаляємо файл
            if (remove(filename) == 0) {
                printf("File '%s' deleted successfully.\n", filename);
            } else {
                printf("Failed to delete file '%s'.\n", filename);
            }
        } else {
            fclose(file); // Закриваємо файл, якщо підпис не збігається
            printf("File '%s' is not yours (signature mismatch).\n", filename);
        }
    } else {
        fclose(file);
        printf("File '%s' is empty or cannot be read.\n", filename);
    }
}


void WriteToFile(char* name) {
    char filename[MAX_LENGTH];
    FILE* file;

    // Формуємо ім'я файлу з розширенням .txt
    snprintf(filename, sizeof(filename), "%s.txt", name);

    file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error opening '%s' file.\n", filename);
        return;
    }

    char firstLine[LENGTH_FILE];
    // Зчитуємо перший рядок файлу
    if (fgets(firstLine, sizeof(firstLine), file) != NULL) {
        // Видаляємо символ нового рядка з кінця першого рядка
        firstLine[strcspn(firstLine, "\n")] = 0;

        if (strcmp(firstLine, "Anne") == 0) {
            fseek(file, 0, SEEK_END);// Переміщаємо вказівник у кінець файлу для додавання записц

            Record record;
            printf("Enter the data for the record:\n");
            Create_Record(&record); // Зчитуємо дані для нового запису

            // Додаємо запис до файлу
            if (fprintf(file, "%s %.2f %.2f\n", record.region, record.area, record.population) > 0) {
                printf("Record successfully added to the file '%s'.\n", filename);
            } else {
                printf("Error writing to file '%s'.\n", filename);
            }
        } else {
            printf("File '%s' is not yours (signature mismatch).\n", filename);
        }
    } else {
        printf("File '%s' is empty or cannot be read.\n", filename);
    }
    fclose(file);
}

void Create_Record(Record *record) {
    int c;
    printf("Enter region name: ");
    fgets(record->region, MAX_LENGTH, stdin);
    record->region[strcspn(record->region, "\n")] = '\0'; // Удаляем символ новой строки
    fflush(stdin);

    printf("Enter area: ");
    while (scanf("%f", &record->area) != 1 || record->area <= 0 || record->area > 100000) {
        printf("Invalid input. Please enter a valid float for area (0 - 100000): ");
        while (getchar() != '\n'); // Очищаем буфер ввода
    }

    printf("Enter population: ");
    while (scanf("%f", &record->population) != 1 || record->population <= 0 || record->population > 100000) {
        printf("Invalid input. Please enter a valid float for population (0 - 100000): ");
        while (getchar() != '\n'); // Очищаем буфер ввода
    }
}

void Paste_Record(char* name) {
    Record records[MAX_LENGTH];
    int count = 0;

    char filename[MAX_LENGTH];
    // Формуємо ім'я файлу з розширенням .txt
    snprintf(filename, sizeof(filename), "%s.txt", name);

    // Відкриваємо файл для читання і запису
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error: File '%s' does not exist.\n", filename);
        return;
    }

    char signature[MAX_LENGTH];
    if (fgets(signature, sizeof(signature), file) == NULL) {
        printf("Error: File '%s' is empty or cannot be read.\n", filename);
        fclose(file);
        return;
    }

    if (strncmp(signature, "Anne", 4) != 0) {
        printf("Error: File '%s' does not have a valid signature or was not created by you.\n", filename);
        fclose(file);
        return;
    }

    // Зчитуємо всі записи з файлу до масиву `records`
    while (fscanf(file, "%s %f %f", records[count].region, &records[count].area, &records[count].population) == 3) {
        int len = strlen(records[count].region);

        // Якщо в кінці назви регіону є зайвий пробіл, видаляємо його
        if (len > 0 && records[count].region[len - 1] == ' ') {
            records[count].region[len - 1] = '\0';
        }
        count++;

        if (count >= MAX_LENGTH) {
            printf("Error: Too many records in file. Max supported is %d.\n", MAX_LENGTH);
            fclose(file);
            return;
        }
    }
    fclose(file);

    if (count == 0) {
        printf("No records to process in the file '%s'.\n", filename);
        return;
    }

    // Ініціалізуємо змінні для перевірки сортування
    int is_sorted_by_region_asc = 1, is_sorted_by_region_desc = 1;
    int is_sorted_by_area_asc = 1, is_sorted_by_area_desc = 1;
    int is_sorted_by_population_asc = 1, is_sorted_by_population_desc = 1;

    // Перевіряємо, чи впорядковані записи за кожним із полів
    for (int i = 0; i < count - 1; i++) {
        // Перевірка сортування за назвою регіону
        if (strcmp(records[i].region, records[i + 1].region) > 0) is_sorted_by_region_asc = 0;
        if (strcmp(records[i].region, records[i + 1].region) < 0) is_sorted_by_region_desc = 0;

        // Перевірка сортування за площею
        if (records[i].area > records[i + 1].area) is_sorted_by_area_asc = 0;
        if (records[i].area < records[i + 1].area) is_sorted_by_area_desc = 0;

        // Перевірка сортування за населенням
        if (records[i].population > records[i + 1].population) is_sorted_by_population_asc = 0;
        if (records[i].population < records[i + 1].population) is_sorted_by_population_desc = 0;
    }

    int sorted_field = 0;
    int sort_order = 0; // 1 - за зростанням, 2 - за спаданням
    if (is_sorted_by_region_asc) { sorted_field = 1; sort_order = 1; }
    else if (is_sorted_by_region_desc) { sorted_field = 1; sort_order = 2; }
    else if (is_sorted_by_area_asc) { sorted_field = 2; sort_order = 1; }
    else if (is_sorted_by_area_desc) { sorted_field = 2; sort_order = 2; }
    else if (is_sorted_by_population_asc) { sorted_field = 3; sort_order = 1; }
    else if (is_sorted_by_population_desc) { sorted_field = 3; sort_order = 2; }

    // Якщо файл не впорядкований, виводимо помилку
    if (sorted_field == 0) {
    printf("Error: File '%s' is not sorted by any field. Wanna sort it first? (y/n): ", filename);
    char response;
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        printf("Sorting the file '%s'...\n", filename);
        Sort_Records(name);
    } else {
        printf("Operation aborted. File '%s' remains unsorted.\n", filename);
        return;
    }
}


    // Якщо масив заповнений, не можемо додати новий запис
    if (count >= MAX_LENGTH) {
        printf("Error: Cannot add more records. Array is full.\n");
        return;
    }

    Record new_record;
    printf("Enter the data for the new record:\n");
    Create_Record(&new_record);

    // Визначаємо позицію для вставки нового запису
    int pos = 0;
    if (sorted_field == 1) { // Сортування за назвою регіону
        while (pos < count && ((sort_order == 1 && strcmp(records[pos].region, new_record.region) < 0) ||
                               (sort_order == 2 && strcmp(records[pos].region, new_record.region) > 0))) {
            pos++;
        }
    } else if (sorted_field == 2) { // Сортування за площею
        while (pos < count && ((sort_order == 1 && records[pos].area < new_record.area) ||
                               (sort_order == 2 && records[pos].area > new_record.area))) {
            pos++;
        }
    } else if (sorted_field == 3) { // Сортування за населенням
        while (pos < count && ((sort_order == 1 && records[pos].population < new_record.population) ||
                               (sort_order == 2 && records[pos].population > new_record.population))) {
            pos++;
        }
    }

    // Зсуваємо елементи масиву, щоб звільнити місце для нового запису
    for (int i = count; i > pos; i--) {
        records[i] = records[i - 1];
    }
    records[pos] = new_record;
    count++;

    //перезаписуємо всі дані
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file '%s' for writing.\n", filename);
        return;
    }

    // Спочатку записуємо підпис
    fprintf(file, "%s", signature);
    // Потім записуємо всі записи з масиву
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f %.2f\n", records[i].region, records[i].area, records[i].population);
    }
    fclose(file);

    printf("Record successfully inserted into the file '%s'.\n", filename);
}

void Read_Record(char* name) {
    char filename[MAX_LENGTH];
    FILE* file = NULL;

    while (file == NULL) {
        snprintf(filename, sizeof(filename), "%s.txt", name);
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error opening file '%s'. Please enter a valid file name: ", filename);
            scanf("%s", name);
        }
    }

    char signature[LENGTH_FILE];
    // Перевірка, чи файл не порожній і доступний для читання
    if (fgets(signature, sizeof(signature), file) == NULL) {
        printf("Error: File '%s' is empty or cannot be read.\n", filename);
        fclose(file);
        return;
    }

    Record records[MAX_LENGTH];
    int count = 0;

    // Зчитування даних про записи з файлу
    while (fscanf(file, "%s %f %f", records[count].region, &records[count].area, &records[count].population) == 3) { 
        int len = strlen(records[count].region);
        
        // Видалення пробілу в кінці рядка, якщо є
        if (len > 0 && records[count].region[len - 1] == ' ') {
            records[count].region[len - 1] = '\0';
        }
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("No records in the file '%s'.\n", filename);
        return;
    }

    printf("Number of records in file '%s' - %d\n", filename, count);

    int index;

    do {
        printf("Choose a record to read by entering the index (1-%d): ", count);
    } while (!ValidInputI(&index, 1, count));

    // Виведення обраного запису
    printf("Selected record:\n");
    printf("Region: %s, Area: %.2f, Population: %.2f\n", 
           records[index - 1].region, records[index - 1].area, records[index - 1].population);
}

void Edit_Record(char* name) {
    char filename[MAX_LENGTH];
    FILE* file = NULL;

    while (file == NULL) {
        snprintf(filename, sizeof(filename), "%s.txt", name);
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error: File '%s' does not exist. Please enter a valid file name: ", filename);
            scanf("%s", name);
        }
    }

    char signature[LENGTH_FILE];
    // Перевірка, чи файл не порожній і доступний для читання
    if (fgets(signature, sizeof(signature), file) == NULL) {
        printf("Error: File '%s' is empty or cannot be read.\n", filename);
        fclose(file);
        return;
    }

    if (strncmp(signature, "Anne", 4) != 0) {
        printf("Error: File '%s' does not have a valid signature or was not created by you.\n", filename);
        fclose(file);
        return;
    }

    Record records[MAX_LENGTH];
    int count = 0;

    // Зчитування записів з файлу
    while (fscanf(file, "%s %f %f", records[count].region, &records[count].area, &records[count].population) == 3) {
        int len = strlen(records[count].region);
        // Видалення пробілу в кінці рядка, якщо він є
        if (len > 0 && records[count].region[len - 1] == ' ') {
            records[count].region[len - 1] = '\0';
        }
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("No records to edit in the file '%s'.\n", filename);
        return;
    }

    // Виведення списку записів для вибору
    printf("Choose a record to edit by entering the index (1-%d):\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d: Region: %s, Area: %.2f, Population: %.2f\n", i + 1, records[i].region, records[i].area, records[i].population);
    }

    int index;
    do {
        printf("Enter the index of the record to edit: ");
        scanf("%d", &index);

        if (index < 0 || index > count) {
            printf("Invalid index. Try again.\n");
        }
    } while (index < 0 || index > count);

    while (getchar() != '\n');

    // Запит нових даних для обраного запису
    printf("Enter new data for the selected record:\n");
    Create_Record(&records[index - 1]);

    // Відкриття файлу для запису оновлених даних
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: File '%s' could not be reopened for writing.\n", filename);
        return;
    }

    fprintf(file, "%s", signature);

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f %.2f\n", records[i].region, records[i].area, records[i].population);
    }

    fclose(file);
    printf("Record updated successfully.\n");
}

void Sort_Records(char* name) {
    char filename[MAX_LENGTH];
    FILE* file = NULL;
    
    while (file == NULL) {
        snprintf(filename, sizeof(filename), "%s.txt", name); // Формування імені файлу
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error: File '%s' does not exist. Please enter a valid file name: ", filename);
            scanf("%s", name); // Запит нового імені файлу
        }
    }

    char signature[LENGTH_FILE];
    // Перевірка, чи файл не порожній і доступний для читання
    if (fgets(signature, sizeof(signature), file) == NULL) {
        printf("Error: File '%s' is empty or cannot be read.\n", filename);
        fclose(file);
        return;
    }

    if (strncmp(signature, "Anne", 4) != 0) {
        printf("Error: File '%s' does not have a valid signature or was not created by you.\n", filename);
        fclose(file);
        return;
    }

    Record records[MAX_LENGTH];
    int count = 0;

    // Зчитування записів з файлу
    while (fscanf(file, "%s %f %f", records[count].region, &records[count].area, &records[count].population) == 3) {
        int len = strlen(records[count].region);
        // Видалення пробілу в кінці рядка, якщо він є (для забезпечення коректності рядків)
        if (len > 0 && records[count].region[len - 1] == ' ') {
            records[count].region[len - 1] = '\0';
        }
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("No records to sort in the file '%s'.\n", filename);
        return;
    }

    int choice;
    do {
        printf("Choose a field to sort by:\n1: Region\n2: Area\n3: Population\n");
    } while (!ValidInputI(&choice, 1, 3));

    // Запит у користувача напряму сортування
    int choice2;
    do {
        printf("Choose the method of sorting: 1 - descending, 2 - ascending\n");
    } while (!ValidInputI(&choice2, 1, 2)); // Перевірка на валідний вибір

    // Реалізація сортування бульбашкою
    for (int i = 0; i < count - 1; i++) { // Зовнішній цикл: кожна ітерація зменшує кількість елементів для перевірки
        for (int j = 0; j < count - i - 1; j++) { // Внутрішній цикл: порівняння сусідніх елементів
            int swap = 0; // Флаг, чи потрібно міняти місцями два елементи

            // Вибір поля для сортування
            if (choice == 1) { // Сортування за регіоном (лексикографічний порядок)
                swap = (choice2 == 2) ? (strcmp(records[j].region, records[j + 1].region) > 0) // За зростанням
                                      : (strcmp(records[j].region, records[j + 1].region) < 0); // За спаданням
            } else if (choice == 2) { // Сортування за площею
                swap = (choice2 == 2) ? (records[j].area > records[j + 1].area) // За зростанням
                                      : (records[j].area < records[j + 1].area); // За спаданням
            } else if (choice == 3) { // Сортування за населенням
                swap = (choice2 == 2) ? (records[j].population > records[j + 1].population) // За зростанням
                                      : (records[j].population < records[j + 1].population); // За спаданням
            }

            // Якщо умова swap виконана, міняємо місцями сусідні елементи
            if (swap) {
                Record temp = records[j];        // Тимчасове збереження першого елемента
                records[j] = records[j + 1];    // Перестановка другого елемента на місце першого
                records[j + 1] = temp;          // Повернення першого елемента на місце другого
            }
        }
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: File '%s' could not be reopened for writing.\n", filename);
        return;
    }

    // Запис підпису файлу
    fprintf(file, "%s", signature);

    // Запис відсортованих записів у файл
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f %.2f\n", records[i].region, records[i].area, records[i].population);
    }

    fclose(file);
    printf("Records sorted successfully.\n");
}

void Delete_Record(char* name) {
    char filename[MAX_LENGTH];
    FILE* file = NULL;
     // Формування імені файлу
    while (file == NULL) {
        snprintf(filename, sizeof(filename), "%s.txt", name);
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error: File '%s' does not exist. Please enter a valid file name: ", filename);
            scanf("%s", name);//Запит нового імені файлу 
        }
    }

    char signature[LENGTH_FILE];
    // Перевірка, чи файл не порожній і доступний для читання
    if (fgets(signature, sizeof(signature), file) == NULL) {
        printf("Error: File '%s' is empty or cannot be read.\n", filename);
        fclose(file);
        return;
    }

    if (strncmp(signature, "Anne", 4) != 0) {
        printf("Error: File '%s' does not have a valid signature or was not created by you.\n", filename);
        fclose(file);
        return;
    }

    Record records[MAX_LENGTH];
    int count = 0;

    // Зчитування записів з файлу
    while (fscanf(file, " %s %f %f", records[count].region, &records[count].area, &records[count].population) == 3) {
        int len = strlen(records[count].region);
        // Видалення пробілу в кінці рядка, якщо він є
        if (len > 0 && records[count].region[len - 1] == ' ') {
            records[count].region[len - 1] = '\0';
        }
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("No records to delete in the file '%s'.\n", filename);
        return;
    }

    // Виведення списку записів для вибору
    printf("Choose a record to delete by entering the index (1-%d):\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d: Region: %s, Area: %.2f, Population: %.2f\n", i + 1, records[i].region, records[i].area, records[i].population);
    }

    int index;
    do {
        printf("Enter the index of the record to delete: ");
        scanf("%d", &index);

        if (index < 1 || index > count) {
            printf("Invalid index. Try again.\n");
        }
    } while (index < 1 || index > count);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: File '%s' could not be reopened for writing.\n", filename);
        return;
    }

    fprintf(file, "%s", signature);

    // Перезапис усіх записів, крім обраного для видалення
    for (int i = 0; i < count; i++) {
        if (i != index - 1) { // Пропускаємо обраний запис
            fprintf(file, "%s %.2f %.2f\n", records[i].region, records[i].area, records[i].population);
        }
    }

    fclose(file);
    printf("Record deleted successfully.\n");
}

int Valid_Name(char* name){
const char invalid_chars[] = "\\/:*?\"<>|.";

    for (int i = 0; i < strlen(name); i++) {
        if (strchr(invalid_chars, name[i])) {
            return 0;
        }

        if ((name[i] == '.' || name[i] == ',') && name[i + 1] == name[i]) {
            return 0;
        }
    }
    return 1; 
}

int ValidInputI(int* num, int minimum, int maximum) 
{
    char check=0;
    if(scanf("%d%c", num, &check) !=2 || check != '\n')
    {
        printf("Error, not correct symbols!\n"); 
        while (getchar()!='\n');
        return 0;
    }else if( *num > maximum || *num < minimum)
    {
        printf("Enter value within %d and %d!\n", minimum, maximum); 
        return 0;
    }

    return 1;
}

int Get_Name(char* name, int choice) {
    int exit = 0;

    while (!exit) {
        printf("Enter file name (it will be opened with .txt format) | 'q' to cancel:\n");
        printf("-> ");
        
        // Читаємо ім'я файлу від користувача
        if (fgets(name, sizeof(name), stdin) != NULL) 
            name[strcspn(name, "\n")] = 0; // Видаляємо символ нового рядка '\n'

        // Якщо введено 'q', відміняємо операцію
        if (strcmp(name, "q") == 0) {
            printf("Canceled.\n");
            return 0;
        }

        if (!Valid_Name(name)) {
            printf("You cannot name the file like this!\n");
            continue;
        }

        // Якщо це не створення нового файлу (choice != 1), перевіряємо існування файлу
        if (choice != 1 && !File_Exists(name)) {
            printf("Error: File '%s' does not exist.\n", name);
            continue;
        }

        // Якщо всі перевірки пройдено, виходимо з циклу
        exit = 1;
    }

    return 1;
}

int File_Exists(char *name) {
    char filename[MAX_LENGTH]; 
    sprintf(filename, "%s.txt", name);
    FILE* file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

void NewYear()
{
    printf("\n\t  ");
    const char *text = "Happy New 2025 Year";
    int colors[] = {31, 37};

    for (int i = 0; text[i] != '\0'; i++) {
        printf("\033[%dm%c\033[0m", colors[i % 2], text[i]);
    }
    printf("\n");
}