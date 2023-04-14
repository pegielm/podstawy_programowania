#include "suma.h"
#include <stdio.h>
#include <stdlib.h>
int * suma(int *A, int *B, int lenA, int lenB) {
    int sum[lenA + lenB];
    int i, j, k;
    i = j = k = 0;
    while (i < lenA && j < lenB) {
        if (A[i] < B[j]) {
            sum[k++] = A[i++];
        } else if (A[i] > B[j]) {
            sum[k++] = B[j++];
        } else {
            sum[k++] = A[i++];
            j++;
        }
    }
    while (i < lenA) {
        sum[k++] = A[i++];
    }
    while (j < lenB) {
        sum[k++] = B[j++];
    }
    printf("Suma zbiorow A i B: ");
    for (i = 0; i < k; i++) {
        printf("%d ", sum[i]);
    }
    printf("\n");
    
    int *result = (int *)malloc(k * sizeof(int));
    
    for (i = 0; i < k; i++) {
        result[i] = sum[i];
    }
    return result;
}