#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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

    // Allocate memory for the array of integers
    int * parts = (int*)malloc(sizeof(int) * count);

    // Split the string by periods and convert each part to an integer
    char* token = strtok(str, ".");
    int i = 0;
    while (token != NULL) {
        parts[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    // Set the number of parts
    *num_parts = count;

    return parts;
}
int *usun_powtorzenia_sortuj(int *tab, int n) {
    int i, j, k, m;

    // Sortowanie tablicy za pomocą sortowania przez wstawianie
    for (i = 1; i < n; i++) {
        k = tab[i];
        j = i - 1;

        while (j >= 0 && tab[j] > k) {
            tab[j + 1] = tab[j];
            j--;
        }

        tab[j + 1] = k;
    }

    // Usuwanie powtórzeń
    i = 0;
    while (i < n - 1) {
        if (tab[i] == tab[i + 1]) {
            for (j = i + 1; j < n - 1; j++) {
                tab[j] = tab[j + 1];
            }
            n--;
        } else {
            i++;
        }
    }

    // Tworzenie nowej tablicy bez powtórzeń i posortowanej
    int *nowa_tab = (int *) malloc(n * sizeof(int));
    if (nowa_tab == NULL) {
        printf("Blad alokacji pamieci\n");
        return NULL;
    }

    for (i = 0, m = 0; i < n; i++, m++) {
        nowa_tab[m] = tab[i];
    }

    return nowa_tab;
}
void operations(int n,int * A,int * B,int lenA,int lenB){
    int * noweA = usun_powtorzenia_sortuj(A,lenA);
    int * noweB = usun_powtorzenia_sortuj(B,lenB);
    switch (n)
    {
    case 1: //suma
        printf("suma\n");
        suma(A,B,lenA,lenB);
        break;
    case 2: //czesc wspolna
        printf("czesc wspolna\n ");
        czesc_wspolna(A,B,lenA,lenB);
        break;
    case 3: //roznica
        printf("roznica\n ");
        roznica(A,B,lenA,lenB);
        break;
    case 4://roznica symetryczna
        printf("roznica symetryczna\n");
        roznica_symetryczna(A,B,lenA,lenB);
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

void suma(int *A, int *B, int lenA, int lenB) {
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
}

void czesc_wspolna(int *A, int *B, int lenA, int lenB) {
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
}
void roznica(int *A, int *B, int lenA, int lenB) {
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
}

void roznica_symetryczna(int *A, int *B, int lenA, int lenB) {
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
}

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
            return;
        }
    }
    printf("Zbiory A i B sa rowne.\n");
}

void zawiera(int *A, int *B, int lenA, int lenB) {
    if (lenA < lenB) {
        int *temp = A;
        A = B;
        B = temp;
        int tempLen = lenA;
        lenA = lenB;
        lenB = tempLen;
    }
    bool A_contains_B = true;
    bool B_contains_A = true;
    for (int i = 0; i < lenB; i++) {
        bool found = false;
        for (int j = 0; j < lenA; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            A_contains_B = false;
        }
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
            B_contains_A = false;
        }
    }
    if (A_contains_B && B_contains_A) {
        printf("Zbiory A i B sa sobie rowne.\n");
    } else if (A_contains_B) {
        printf("Zbior A zawiera zbior B.\n");
    } else if (B_contains_A) {
        printf("Zbior B zawiera zbior A.\n");
    } else {
        printf("Zbiory A i B nie zawieraja sie nawzajem.\n");
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
        printf("\n A: ");
        for(int i=0;i<lenA;i++){
            printf("%d ",current->A[i]);
        }
        printf("\n B: ");
        for(int i=0;i<lenB;i++){
            printf("%d ",current->B[i]);
        }

        operations(current->nr,current->A,current->B,lenA,lenB);
        current=current->next;
        
    } 

    return 0;
}