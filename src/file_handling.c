#include <stdio.h>
#include "student_manager.h"

// Функция для сохранения
void saveToFile(struct Students array[], int size, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s %d %s\n", array[i].Name, array[i].Surname, array[i].age, array[i].Programm);
    }

    fclose(file);
    printf("Данные сохранены %s.\n", filename);
}

// Функция для загрузки
void loadFromFile(struct Students array[], int *size, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка\n");
        return;
    }

    *size = 0;
    while (fscanf(file, "%s %s %d %s", array[*size].Name, array[*size].Surname, &array[*size].age, array[*size].Programm) != EOF) {
        (*size)++;
    }

    fclose(file);
    printf("Данные згружены %s.\n", filename);
}
