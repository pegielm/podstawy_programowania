#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 3

// Struktura przechowująca informacje o początkach i końcach obszarów zawierających liczby
typedef struct {
    char** lines;
    int lineCount;
    int capacity;
} DataStructure;

// Funkcja inicjalizująca strukturę danych
DataStructure* initializeDataStructure() {
    DataStructure* data = (DataStructure*)malloc(sizeof(DataStructure));
    data->lines = (char**)malloc(INITIAL_CAPACITY * sizeof(char*));
    data->lineCount = 0;
    data->capacity = INITIAL_CAPACITY;
    return data;
}

// Funkcja wczytująca linie tekstu z klawiatury
void readLines(DataStructure* data) {
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (data->lineCount >= data->capacity) {
            // Jeśli liczba linii przekracza pojemność, dokonaj realokacji pamięci
            int newCapacity = data->capacity * 2;
            data->lines = (char**)realloc(data->lines, newCapacity * sizeof(char*));
            data->capacity = newCapacity;
        }
        int lineLength = strlen(buffer);
        data->lines[data->lineCount] = (char*)malloc((lineLength + 1) * sizeof(char));
        strcpy(data->lines[data->lineCount], buffer);
        data->lineCount++;
    }
}

// Funkcja wyodrębniająca ciągi znaków tworzące prawidłową liczbę dla podanego systemu liczbowego
int* extractNumbers(DataStructure* data, int base) {
    int* numbers = (int*)malloc(data->lineCount * sizeof(int));
    for (int i = 0; i < data->lineCount; i++) {
        numbers[i] = strtol(data->lines[i], NULL, base);
    }
    return numbers;
}

// Funkcja zwalniająca pamięć zajmowaną przez strukturę danych
void freeDataStructure(DataStructure* data) {
    for (int i = 0; i < data->lineCount; i++) {
        free(data->lines[i]);
    }
    free(data->lines);
    free(data);
}

// Testy jednostkowe

void runUnitTests() {
    // Test initializeDataStructure
    DataStructure* data = initializeDataStructure();
    if (data->lineCount == 0 && data->capacity == INITIAL_CAPACITY) {
        printf("Test initializeDataStructure: Passed\n");
    } else {
        printf("Test initializeDataStructure: Failed\n");
    }

    // Test readLines
    printf("Enter test lines (end with Ctrl+D):\n");
    readLines(data);
    if (data->lineCount > 0) {
        printf("Test readLines: Passed\n");
    } else {
        printf("Test readLines: Failed\n");
    }

    // Test extractNumbers
    int* numbers = extractNumbers(data, 10);
    if (numbers != NULL) {
        printf("Test extractNumbers: Passed\n");
    } else {
        printf("Test extractNumbers: Failed\n");
    }
    free(numbers);

    // Test freeDataStructure
    freeDataStructure(data);
    printf("Test freeDataStructure: Passed\n");
}

// Test integracyjny

void runIntegrationTest() {
    printf("Enter test lines (end with Ctrl+D):\n");
    DataStructure* data = initializeDataStructure();
    readLines(data);
    int* numbers = extractNumbers(data, 10);
    printf("Extracted numbers:\n");
    for (int i = 0; i < data->lineCount; i++) {
        printf("%d\n", numbers[i]);
    }
    free(numbers);
    freeDataStructure(data);
}

int main() {
    DataStructure* data = initializeDataStructure();
    printf("Enter lines (end with Ctrl+D):\n");
    readLines(data);
    int* numbers = extractNumbers(data, 10);
    printf("Extracted numbers:\n");
    for (int i = 0; i < data->lineCount; i++) {
        printf("%d\n", numbers[i]);
    }
    free(numbers);
    freeDataStructure(data);
    printf("\nrun tests? (y/n): ");
    char answer;
    scanf("%c", &answer);
    if (answer == 'y') {
        runUnitTests();
        runIntegrationTest();
    }
    

    return 0;
}
