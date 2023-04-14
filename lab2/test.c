#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "suma.h"
#include "roznica.h"
#include "czesc_wspolna.h"
#include "roznica_symetryczna.h"
#include "rowne.h"
#include "zawiera.h"
int compare(int arr1[], int arr2[], int n) {
    for (int i = 0; i < n; i++) {
        //printf("xd");
        if (arr1[i] != arr2[i]) {
            return 0; 
        }
    }
    return 1; 
}
int main(){
    //basic unit tests with assert.h
    //------------------SUMA------------------
    printf("TESTY JEDNOSTKOWE\n");
    printf("------------------SUMA------------------\n");
    int A[3] = {1,2,3};
    int B[3] = {4,5,6};
    int lenA = 3;
    int lenB = 3;
    int * wynik ;
    wynik = suma(A,B,lenA,lenB);
    int oczekiwany[6] = {1,2,3,4,5,6};
    assert(compare(wynik, oczekiwany, 6) == 1);
    printf("OK\n");
    //------------------CZESC WSPOLNA------------------
    printf("------------------CZESC WSPOLNA------------------\n");
    int C[3] = {1,2,3};
    int D[3] = {2,3,4};
    int lenC = 3;
    int lenD = 3;
    int oczekiwany2[2] = {2,3};
    wynik = czesc_wspolna(C,D,lenC,lenD);
    assert(compare(wynik, oczekiwany2, 2) == 1);
    printf("OK\n");
    //------------------ROZNICA------------------
    printf("------------------ROZNICA------------------\n");
    wynik = roznica(C,D,lenC,lenD);
    int oczekiwany3[1] = {1};
    assert(compare(wynik, oczekiwany3, 1) == 1);
    printf("OK\n");
    //------------------ROZNICA SYMETRYCZNA------------------
    printf("------------------ROZNICA SYMETRYCZNA------------------\n");
    int G[3] = {1,2,3};
    int H[3] = {2,3,4};
    int lenG = 3;
    int lenH = 3;
    wynik = roznica_symetryczna(G,H,lenG,lenH);
    int oczekiwany4[2] = {1,4};
    assert(compare(wynik, oczekiwany4, 2) == 1);
    printf("OK\n");
    
    return 0;
}