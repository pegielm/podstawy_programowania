#include "rowne.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void rowne(int *A, int *B, int lenA, int lenB) {
    if (lenA != lenB) {
        printf("Zbiory A i B nie sa rowne.\n");
        return;
    }
    for (int i = 0; i < lenA; i++) {
        bool found = false;
        for (int j = 0; j < lenB; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            printf("Zbiory A i B nie sa rowne.\n");
            return false;
        }
    }
    printf("Zbiory A i B sa rowne.\n");
    return;
}