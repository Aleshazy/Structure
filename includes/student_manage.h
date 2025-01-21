#ifndef STUDENT_MANAGE_H
#define STUDENT_MANAGE_H

#include <stdio.h>

// структура
struct Students {
    char Name[50];      // Имя
    char Surname[50];   // Фамилия
    int age;            // Возраст
    char Programm[50];  // Программа
};

// функции
void addStudent(struct Students array[], int *size); // Добавить студента
void deleteStudent(struct Students array[], int *size, int index); // Удалить студента
void editStudent(struct Students array[], int index); // Редактировать студента
int compareStrings(char str1[], char str2[]); // Сравнить строки
void sortByName(struct Students array[], int size); // Сортировать по имени
void sortBySurname(struct Students array[], int size); // Сортировать по фамилии
void sortByAge(struct Students array[], int size); // Сортировать по возрасту
void sortByProgram(struct Students array[], int size); // Сортировать по программе

// функция для работы с файлами
void saveToFile(struct Students array[], int size, const char *filename); // Сохранить данные
void loadFromFile(struct Students array[], int *size, const char *filename); // Загрузить данные

#endif // STUDENT_MANAGE_H