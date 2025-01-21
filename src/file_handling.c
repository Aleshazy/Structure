#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Students {
    char Name[50];
    char Surname[50];
    int age;
    char Program[50];
};

void loadFromFile(struct Students array[], int *size, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        return;
    }
    *size = 0;
    while (fscanf(file, "%s %s %d %s", array[*size].Name, array[*size].Surname, &array[*size].age, array[*size].Program) != EOF) {
        (*size)++;
    }
    fclose(file);
    printf("Data loaded from %s.\n", filename);
}
void saveToFile(struct Students array[], int size, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s %d %s\n", array[i].Name, array[i].Surname, array[i].age, array[i].Program);
    }
    fclose(file);
    printf("Data saved to %s.\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <load_filename> <save_filename>\n", argv[0]);
        return 1;
    }
    const char *load_filename = argv[1];
    const char *save_filename = argv[2];
    struct Students students[100];
    int size;
    
    loadFromFile(students, &size, load_filename);
    saveToFile(students, size, save_filename);

    return 0;
}