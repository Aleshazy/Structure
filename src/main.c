#include <stdio.h>
#include "student_manager.h"

int main() {
    struct Students arrayOFStudents[100] = {
        {"AA", "aa", 18, "PX-23"},
        {"aaa", "bb", 17, "PX-24"},
        {"a", "cc", 16, "PX-25"},
        {"D", "dd", 15, "PX-25"}
    };
    int size = 4;

    printf("1. Add students\n2. Delete student\n3. Edit students\n4. Sort by Name\n5. Sort by Surname\n6. Sort by Age\n7. Sort by Program\n8. Save to file\n9. Load from file\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        addStudent(arrayOFStudents, &size);
    } else if (choice == 2) {
        int index;
        printf("Enter index to delete: ");
        scanf("%d", &index);
        deleteStudent(arrayOFStudents, &size, index);
    } else if (choice == 3) {
        int index;
        printf("Enter index to edit: ");
        scanf("%d", &index);
        editStudent(arrayOFStudents, index);
    } else if (choice == 4) {
        sortByName(arrayOFStudents, size);
    } else if (choice == 5) {
        sortBySurname(arrayOFStudents, size);
    } else if (choice == 6) {
        sortByAge(arrayOFStudents, size);
    } else if (choice == 7) {
        sortByProgram(arrayOFStudents, size);
    } else if (choice == 8) {
        saveToFile(arrayOFStudents, size, "students.txt");
    } else if (choice == 9) {
        loadFromFile(arrayOFStudents, &size, "students.txt");
    } else {
        printf("Введите число от 1 до 9.\n");
        return -1;
    }

    // Печать информации о студентах
    for (int i = 0; i < size; i++) {
        printf("%s %s %d %s\n", arrayOFStudents[i].Name, arrayOFStudents[i].Surname, arrayOFStudents[i].age, arrayOFStudents[i].Programm);
    }

    return 0;
}

 
struct Students { 
    char Name[50]; 
    char Surname[50]; 
    int age; 
    char Programm[50]; 
}; 
 
void addStudent(struct Students array[], int *size) { 
    if (*size >= 100) { // max students 100 
     printf ("max students"); 
        return; 
    } 
    printf("Enter Name: "); 
    scanf("%s", array[*size].Name); 
    printf("Enter Surname: "); 
    scanf("%s", array[*size].Surname); 
    printf("Enter Age: "); 
    scanf("%d", &array[*size].age); 
    printf("Enter Program: "); 
    scanf("%s", array[*size].Programm); 
    (*size)++; 
} 
 
void deleteStudent(struct Students array[], int *size, int index) { 
    if (index < 0 ||  index >= *size) { 
        printf("Anlak\n"); 
        return; 
    } 
    for (int i = index; i < *size - 1; i++) { 
        array[i] = array[i + 1]; 
    } 
    (*size)--; 
} 
 
void editStudent(struct Students array[], int index) { 
    if (index < 0 || index >= 100) { 
        printf("Invalid index\n"); 
        return; 
    } 
    printf("Enter new Name: "); 
    scanf("%s", array[index].Name); 
    printf("Enter new Surname: "); 
    scanf("%s", array[index].Surname); 
    printf("Enter new Age: "); 
    scanf("%d", &array[index].age); 
    printf("Enter new Program: "); 
    scanf("%s", array[index].Programm); 
} 
 
int compareStrings(char str1[], char str2[]) { 
    int i = 0; 
    while (str1[i] != '\0' && str2[i] != '\0') { 
        if (str1[i] != str2[i]) { 
            return str1[i] - str2[i]; 
        } 
        i++; 
    } 
    return str1[i] - str2[i]; 
} 
 
void sortByName(struct Students array[], int size) { 
    for (int i = 0; i < size - 1; i++) { 
        for (int j = i + 1; j < size; j++) { 
            if (compareStrings(array[i].Name, array[j].Name) > 0) { 
                struct Students temp = array[i]; 
                array[i] = array[j]; 
                array[j] = temp; 
            } 
        } 
    } 
} 
 
void sortBySurname(struct Students array[], int size) { 
    for (int i = 0; i < size - 1; i++) { 
        for (int j = i + 1; j < size; j++) { 
            if (compareStrings(array[i].Surname, array[j].Surname) > 0) { 
                struct Students temp = array[i]; 
                array[i] = array[j]; 
                array[j] = temp; 
            } 
        } 
    } 
} 
 
void sortByAge(struct Students array[], int size) { 
    for (int i = 0; i < size - 1; i++) { 
        for (int j = i + 1; j < size; j++) { 
            if (array[i].age > array[j].age) { 
                struct Students temp = array[i]; 
                array[i] = array[j]; 
                array[j] = temp; 
            } 
        } 
    } 
} 
 
void sortByProgram(struct Students array[], int size) { 
    for (int i = 0; i < size - 1; i++) { 
        for (int j = i + 1; j < size; j++) { 
            if (compareStrings(array[i].Programm, array[j].Programm) > 0) { 
                struct Students temp = array[i]; 
                array[i] = array[j]; 
                array[j] = temp; 
            } 
        } 
    } 
} 
 
int main() { 
    struct Students arrayOFStudents[100] = { 
        {"AA", "aa", 18, "PX-23"}, 
        {"aaa", "bb", 17, "PX-24"}, 
        {"a", "cc", 16, "PX-25"}, 
        {"D", "dd", 15, "PX-25"} 
    }; 
    int size = 4; 
 
    printf("1. Add students\n2. Delete student\n3. Edit students\n4. Sort by Name\n5. Sort by Surname\n6. Sort by Age\n7. Sort by Program\n"); 
    int choice; 
    scanf("%d", &choice); 
 
    if (choice == 1) { 
        addStudent(arrayOFStudents, &size); 
    } else if (choice == 2) { 
        int index; 
        printf("Enter index to delete: "); 
        scanf("%d", &index); 
        deleteStudent(arrayOFStudents, &size, index); 
    } else if (choice == 3) { 
        int index; 
        printf("Enter index to edit: "); 
        scanf("%d", &index); 
        editStudent(arrayOFStudents, index); 
    } else if (choice == 4) { 
        sortByName(arrayOFStudents, size); 
    } else if (choice == 5) { 
        sortBySurname(arrayOFStudents, size); 
    } else if (choice == 6) {
        sortByAge(arrayOFStudents, size); 
    } else if (choice == 7) { 
        sortByProgram(arrayOFStudents, size); 
    } 
    else { 
        printf("убежище цифры от 1 до 7 пиши а не вот это вот"); 
        return -1; 
    } 
    // Print student names 
    for (int i = 0; i < size; i++) { 
        printf("%s %s %d %s\n", arrayOFStudents[i].Name, arrayOFStudents[i].Surname, arrayOFStudents[i].age, arrayOFStudents[i].Programm); 
    } 
 
    return 0; 
}
