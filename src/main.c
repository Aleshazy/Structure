#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_manage.h"

void loadStudents(struct Students array[], int *size) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Чёто пошло не так\n");
        return;
    }
    *size = 0;
    while (fscanf(fp, "%s %s %d %s", array[*size].name, array[*size].surname, &array[*size].age, array[*size].program) != EOF) {
        (*size)++;
    }
    fclose(fp);
}

void saveStudents(struct Students array[], int size) {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Чёто пошло не так\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(fp, "%s %s %d %s\n", array[i].name, array[i].surname, array[i].age, array[i].program);
    }
    fclose(fp);
}

void addStudent(struct Students array[], int *size) {
    struct Students student;
    printf("Enter name: ");
    scanf("%s", student.name);
    printf("Enter surname: ");
    scanf("%s", student.surname);
    printf("Enter age: ");
    scanf("%d", &student.age);
    printf("Enter program: ");
    scanf("%s", student.program);
    array[*size] = student;
    (*size)++;
    saveStudents(array, *size);
    printf("Добавлен\n");
}

void deleteStudent(struct Students array[], int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }
    (*size)--;
    saveStudents(array, *size);
    printf("Удалён\n");
}

void editStudent(struct Students array[], int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Такого нету\n");
        return;
    }
    printf("Enter new name: ");
    scanf("%s", array[index].name);
    printf("Enter new surname: ");
    scanf("%s", array[index].surname);
    printf("Enter new age: ");
    scanf("%d", &array[index].age);
    printf("Enter new program: ");
    scanf("%s", array[index].program);
    saveStudents(array, *size);
    printf("ВСЁ СУПЕР\n");
}

void sortByName(struct Students array[], int size) {
    struct Students temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(array[i].name, array[j].name) > 0) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    saveStudents(array, size);
    printf("ВСЁ СУПЕР\n");
}

void sortBySurname(struct Students array[], int size) {
    struct Students temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(array[i].surname, array[j].surname) > 0) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    saveStudents(array, size);
    printf("ВСЁ СУПЕР\n");
}

void sortByProgram(struct Students array[], int size) {
    struct Students temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(array[i].program, array[j].program) > 0) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    saveStudents(array, size);
    printf("ВСЁ СУПЕР\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    struct Students students[100];
    int size = 0;

    loadStudents(students, &size);

    if (strcmp(argv[1], "add") == 0) {
        addStudent(students, &size);
    } else if (strcmp(argv[1], "delete") == 0) {
        if (argc < 3) {
            printf("Usage: %s delete <index>\n", argv[0]);
            return 1;
        }
        int index = atoi(argv[2]);
        deleteStudent(students, &size, index);
    } else if (strcmp(argv[1], "edit") == 0) {
        if (argc < 3) {
            printf("Usage: %s edit <index>\n", argv[0]);
            return 1;
        }
        int index = atoi(argv[2]);
        editStudent(students, &size, index);
    } else if (strcmp(argv[1], "sort") == 0) {
        if (argc < 3) {
            printf("Usage: %s sort <criteria>\n", argv[0]);
            return 1;
        }
        if (strcmp(argv[2], "name") == 0) {
            sortByName(students, size);
        } else if (strcmp(argv[2], "surname") == 0) {
            sortBySurname(students, size);
        } else if (strcmp(argv[2], "program") == 0) {
            sortByProgram(students, size);
        } else {
            printf("Неправильный критерий: %s\n", argv[2]);
            return 1;
        }
    } else {
        printf("Unknown command: %s\n", argv[1]);
        return 1;
    }

    return 0;
}