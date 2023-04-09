#include "zawiera.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void zawiera(int *A, int *B, int lenA, int lenB) {
    int i, j, found;
    
    // Sprawdzenie czy tablica A zawiera tablicę B
    for (i = 0; i <= lenA - lenB; i++) {
        found = 1;
        for (j = 0; j < lenB; j++) {
            if (A[i+j] != B[j]) {
                found = 0;
                break;
            }
        }
        if (found == 1) {
            printf("Zbior A zawiera zbior B\n");
            return;
        }
    }

    // Sprawdzenie czy tablica B zawiera tablice A
    for (i = 0; i <= lenB - lenA; i++) {
        found = 1;
        for (j = 0; j < lenA; j++) {
            if (B[i+j] != A[j]) {
                found = 0;
                break;
            }
        }
        if (found == 1) {
            printf("Zbior B zawiera zbior A\n");
            return;
        }
    }
    
    printf("Zbiory nie zawieraja sie nawzajem\n");
}