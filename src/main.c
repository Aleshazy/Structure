#include <stdio.h>
#include "student_manage.h"


void addStudent(struct Students array[], int *size) { 
    FILE *fp = fopen(stxt, "a");
    fprintf(fp, "%d %s %s %d %s\n", student->id, student->name, student->sname, student->age, student->course);
    fclose(fp);
} 
 
void deleteStudent(struct Students array[], int *size, int index) { 
    if (index < 0 ||  index >= *size) { 
        printf("Anlak\n"); 
        return; 
    } 
    for (int i = index; i < *size - 1; i++) { 
        array[i] = array[i + 1]; 
    } s
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
 
int main(int argc, char* argv[]) { 
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
 
    if (strcmp(argv[1], "add") == 0) { 
        Student student;

        strcpy(student.Name, argv[2]);
        strcpy(student.Surnamename, argv[3]);
        student.age = atoi(argv[4]);
        strcpy(student.Program, argv[5]);

        addStudent(&student);
 
    } 
    else if (choice == 2) { 
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