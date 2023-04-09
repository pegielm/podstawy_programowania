#include "roznica_symetryczna.h"
#include <stdio.h>
#include <stdlib.h>

int * roznica_symetryczna(int *A, int *B, int lenA, int lenB) {
    int symmetric_difference[lenA + lenB];
    int i, j, k;
    i = j = k = 0;
    while (i < lenA && j < lenB) {
        if (A[i] < B[j]) {
            symmetric_difference[k++] = A[i++];
        } else if (A[i] > B[j]) {
            symmetric_difference[k++] = B[j++];
        } else {
            i++;
            j++;
        }
    }
    while (i < lenA) {
        symmetric_difference[k++] = A[i++];
    }
    while (j < lenB) {
        symmetric_difference[k++] = B[j++];
    }
    printf("Roznica symetryczna zbiorow A i B: ");
    if (k == 0) {
        printf("brak\n");
    } else {
        for (i = 0; i < k; i++) {
            printf("%d ", symmetric_difference[i]);
        }
        printf("\n");
    }
    return symmetric_difference;
}