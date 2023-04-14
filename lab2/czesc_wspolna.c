#include "czesc_wspolna.h"
#include <stdio.h>
#include <stdlib.h>

int * czesc_wspolna(int *A, int *B, int lenA, int lenB) {
    int intersection[lenA < lenB ? lenA : lenB];
    int i, j, k;
    i = j = k = 0;
    while (i < lenA && j < lenB) {
        if (A[i] < B[j]) {
            i++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            intersection[k++] = A[i++];
            j++;
        }
    }
    printf("Czesc wspolna zbiorow A i B: ");
    if (k == 0) {
        printf("brak\n");
    } else {
        for (i = 0; i < k; i++) {
            printf("%d ", intersection[i]);
        }
        printf("\n");
    }
    
    int *result = (int *)malloc(k * sizeof(int));
    
    for (i = 0; i < k; i++) {
        result[i] = intersection[i];
    }
    return result;

}