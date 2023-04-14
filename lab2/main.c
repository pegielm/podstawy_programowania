/*
gcc -o app main.c suma.c czesc_wspolna.c roznica.c roznica_symetryczna.c rowne.c zawiera.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "suma.h"
#include "roznica.h"
#include "czesc_wspolna.h"
#include "roznica_symetryczna.h"
#include "rowne.h"
#include "zawiera.h"

#define SIZE 100
typedef struct command{
    int nr;
    int * A;
    int * B;
    int lenA;
    int lenB;
    struct command * next;
} command_t;
void new_command(command_t * first,int nr_nowy,int * A_nowe,int * B_nowe,int lenA_nowe,int lenB_nowe){
    
    command_t * current =  first;
    while (current->next != NULL) {
        current = current->next;
        
    }
    current->next = (command_t *) malloc(sizeof(command_t));
    current->next->nr = nr_nowy;
    current->next->A = A_nowe;
    current->next->B = B_nowe;
    current->next->lenA = lenA_nowe;
    current->next->lenB = lenB_nowe;
    current->next->next = NULL;
    //printf("\nnew cmd");
}
int* split_string(char* str, int* num_parts) {
    int len = strlen(str);
    int count = 1;
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            count++;
        }
    }

    
    int * parts = (int*)malloc(sizeof(int) * count);

   
    char* token = strtok(str, ".");
    int i = 0;
    while (token != NULL) {
        parts[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    
    *num_parts = count;

    return parts;
}
int compare(const void* a, const void* b) {
    const int* x = (const int*)a;
    const int* y = (const int*)b;
    return (*x - *y);
}

int remove_duplicates(int* arr, int length) {
    int i, j, new_length;
    new_length = 1;

    // iterujemy po tablicy i usuwamy powtórzenia
    for (i = 1; i < length; i++) {
        if (arr[i] != arr[i-1]) {
            arr[new_length++] = arr[i];
        }
    }

    return new_length;
}
void operations(int n,int * A,int * B,int lenA,int lenB){
    qsort(A, lenA, sizeof(int), compare);
    qsort(B, lenB, sizeof(int), compare);
    lenA = remove_duplicates(A, lenA);
    lenB = remove_duplicates(B, lenB);
    printf("\n A: ");
        for(int i=0;i<lenA;i++){
            printf("%d ",A[i]);
        }
        printf("\n B: ");
        for(int i=0;i<lenB;i++){
            printf("%d ",B[i]);
        }
    int * wynik;
    switch (n)
    {
    case 1: //suma
        printf("suma\n");
        wynik = suma(A,B,lenA,lenB);
        break;
    case 2: //czesc wspolna
        printf("czesc wspolna\n ");
        czesc_wspolna(A,B,lenA,lenB);
        wynik = czesc_wspolna(A,B,lenA,lenB);
        break;
    case 3: //roznica
        printf("roznica\n ");
        wynik = roznica(A,B,lenA,lenB);
        break;
    case 4://roznica symetryczna
        printf("roznica symetryczna\n");
        wynik = roznica_symetryczna(A,B,lenA,lenB);
        break;
    case 5:// czy A==B
        printf("czy rowne\n");
        rowne(A,B,lenA,lenB);
        break;
    case 6:// czy A zawiera B lub czy B zawiera A
        printf("czy zawiera\n");
        zawiera(A,B,lenA,lenB);
        break;
    default:
        printf("\nzla operacja\n");
        break;
    }
}



//koniec funckji
int main() {
    printf(" OPERACJE NA ZBIORACH \nnr\na.b.c d.e.f\n1>suma\n2>czesc wspolna\n3>roznica\n4>roznica symetryczna\n5>czy rowne\n6>czy zawiera\n");
    int num;
    char str1[SIZE], str2[SIZE];
    int n1,n2;
    command_t * commands;
    commands = (command_t*) malloc(sizeof(command_t));
    commands->nr=0;
    commands->A=NULL;
    commands->B=NULL;
    commands->next=NULL;
    while(scanf("%d\n", &num) != EOF) {
        scanf("%s %s", str1, str2);
        int * tab1 = split_string(str1,&n1);
        int * tab2 = split_string(str2,&n2);
        new_command(commands,num,tab1,tab2,n1,n2);
        /*
        printf("\n");
        for(int i=0;i<n1;i++){
            printf("%d ",tab1[i]);
        }
        printf("\n");
        for(int i=0;i<n2;i++){
            printf("%d ",tab2[i]);
        }
        */
        printf("\n");
        


    }
    command_t *  current = commands->next;
    while(current != NULL){
        //printf("\n nr %d",current->nr);
        int lenA = current->lenA;
        int lenB = current->lenB;
        //printf("\n rozmiary %d %d\n A: ",lenA,lenB);
        
        //printf("\n operacja: %d",current->nr);
        operations(current->nr,current->A,current->B,lenA,lenB);
        current=current->next;
        
    } 

    return 0;
}