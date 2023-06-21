#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int cols_num;
    int row;
    int col;
} Element;

int get(Element e, const int *matrix) {
    int cols_num = e.cols_num;
    int row = e.row;
    int col = e.col; //  1 2 3 4 5 6 7 8 9 
    int index = row * cols_num + col;
    return matrix[index];
}
// Funkcja zwraca tablicę zawierającą maksymalne elementy wierszy lub kolumn macierzy
int *max_matrix_row_or_col_element(bool horizontal, int rowsA, int colsA, int rowsB, int colsB, int *A, int *B) {
    if (horizontal && colsA != colsB) {
        printf("Macierze nie maja takiej samej liczby kolumn\n");
        return NULL;
    } 
    if (!horizontal && rowsA != rowsB) {
        printf("Macierze nie maja takiej samej liczby wierszy\n");
        return NULL;
    }
    int size;
    if(horizontal){
        size = colsA>colsB ? colsA : colsB;
    } else if (!horizontal){
        size = rowsA>rowsB ? rowsA : rowsB;
    }else{
        printf("Nieprawidlowy parametr horizontal\n");
        return NULL;
    }
    int *result = (int *)malloc(size * sizeof(int));
    //znajdź maksymalny element w każdym wierszu lub kolumnie obu macierzy
    int sizeA = horizontal ? rowsA : colsA;
    int sizeB = horizontal ? rowsB : colsB;
    Element e;
    for (int i = 0; i < size; i++) {
        int max =0;
        for (int j=0; j<sizeA; j++){
            
            e.cols_num = colsA;
            e.row = horizontal ? j : i; 
            e.col = horizontal ? i : j; 
            int valueA = get(e, A);  
            if (valueA > max){
                max = valueA;
            }
        }
        for(int j=0; j<sizeB; j++){
            
            e.cols_num =colsB;
            e.row = horizontal ? j : i; 
            e.col = horizontal ? i : j; 
            int valueB = get(e, B);
            if (valueB > max){
                max = valueB;
            }
        }
        
        result[i] = max;
    }

    return result;
}
/*
for (int i = 0; i < size; i++) {
        
        Element e;
        e.cols_num = colsA;
        e.row = horizontal ? 0 : i; 
        e.col = horizontal ? i : 0; 

        int valueA = get(e, A);  
        int valueB = get(e, B);

        result[i] = valueA + valueB;
    }*/
// Testy jednostkowe

void run_get_test() {
    int matrix[4] = {1, 2, 3, 4};
    Element e;
    e.cols_num = 2;
    e.row = 1;
    e.col = 0;

    int result = get(e, matrix);
    printf("get() Test: %d\n", result);  // Oczekiwany wynik: 3
}

void run_max_matrix_row_or_col_element_test() { 
    int A[4] = {1, 2, 3, 4};
    /*
    1 2         5 6
    3 4         7 8 
    */
    int B[4] = {5, 6, 7, 8};

    int *result_row = max_matrix_row_or_col_element(false, 2, 2, 2, 2, A, B);
    printf("max_matrix_row_or_col_element() Test (row): ");
    for (int i = 0; i < 2; i++) {
        printf("%d ", result_row[i]);
    }
    printf("\n");
    // Oczekiwany wynik: 6 8

    int *result_col = max_matrix_row_or_col_element(true, 2, 2, 2, 2, A, B);
    printf("max_matrix_row_or_col_element() Test (col): ");
    for (int i = 0; i < 2; i++) {
        printf("%d ", result_col[i]);
    }
    printf("\n");
    // Oczekiwany wynik: 7 8

    free(result_row);
    free(result_col);
}

int main() {
    printf("wymiary pierwszej macierzy: ");
    int rowsA, colsA;
    scanf("%d %d", &rowsA, &colsA);
    int *A = (int *)malloc(rowsA * colsA * sizeof(int));
    printf("elementy pierwszej macierzy: ");
    for (int i = 0; i < rowsA * colsA; i++) {
        scanf("%d", &A[i]);
    }
    printf("wymiary drugiej macierzy: ");
    int rowsB, colsB;
    scanf("%d %d", &rowsB, &colsB);
    int *B = (int *)malloc(rowsB * colsB * sizeof(int));
    printf("elementy drugiej macierzy: ");
    for (int i = 0; i < rowsB * colsB; i++) {
        scanf("%d", &B[i]);
    }
    int* resoult_row = max_matrix_row_or_col_element(false, rowsA, colsA, rowsB, colsB, A, B);
    int* resoult_col = max_matrix_row_or_col_element(true, rowsA, colsA, rowsB, colsB, A, B);
    printf("max_matrix_row_or_col_element() (row): ");
    int len = rowsA>rowsB ? rowsA : rowsB;
    if (resoult_row == NULL) {
        printf("NULL\n");
        
    }else{
        for (int i = 0; i < len; i++) {
            printf("%d ", resoult_row[i]);
        }
    }
    printf("\n");
    printf("max_matrix_row_or_col_element() (col): ");
    len = colsA>colsB ? colsA : colsB;
    if (resoult_col == NULL) {
        printf("NULL\n");
    }else{
        for (int i = 0; i < len; i++) {
            printf("%d ", resoult_col[i]);
        }
    }
    printf("\n testy jednostkowe: \n");
    
        run_get_test();
        run_max_matrix_row_or_col_element_test();
    

    return 0;
}
/*
2 3                                    1 2 3    7 8
1 2 3 4 5 6                            4 5 6    9 10                 
2 2
7 8 9 10

3 3                                     1 2 3   10 11 12
1 2 3 4 5 6 7 8 9                       4 5 6   13 14 15
3 3                                     7 8 9   16 17 18
10 11 12 13 14 15 16 17 18

4 2
1 2 3 4 5 6 7 8                         1 2     9 10
2 2                                     3 4     11 12                 
9 10 11 12                              5 6
                                        7 8


*/
