#include "roznica.h"
#include <stdio.h>
#include <stdlib.h>
int * roznica(int *A, int *B, int lenA, int lenB) {
    int difference[lenA];
    int i, j, k;
    i = j = k = 0;
    while (i < lenA && j < lenB) {
        if (A[i] < B[j]) {
            difference[k++] = A[i++];
        } else if (A[i] > B[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    while (i < lenA) {
        difference[k++] = A[i++];
    }
    printf("Roznica zbiorow A i B: ");
    if (k == 0) {
        printf("brak\n");
    } else {
        for (i = 0; i < k; i++) {
            printf("%d ", difference[i]);
        }
        printf("\n");
    }
    //allocate memory for the result
    int *result = (int *)malloc(k * sizeof(int));
    //copy the result to the allocated memory
    for (i = 0; i < k; i++) {
        result[i] = difference[i];
    }
    return result;
}