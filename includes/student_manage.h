#ifndef STUDENT_MANAGE_H
#define STUDENT_MANAGE_H

struct Students {
    char name[50];
    char surname[50];
    int age;
    char program[50];
};

void loadStudents(struct Students array[], int *size);
void saveStudents(struct Students array[], int size);
void addStudent(struct Students array[], int *size);
void deleteStudent(struct Students array[], int *size, int index);
void editStudent(struct Students array[], int *size, int index);
void sortByName(struct Students array[], int size);
void sortBySurname(struct Students array[], int size);
void sortByProgram(struct Students array[], int size);

#endif // STUDENT_MANAGE_H
