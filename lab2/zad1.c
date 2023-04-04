#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    printf("\nnew cmd");
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
void operations(int n,int * A,int * B,int lenA,int lenB){
    switch (n)
    {
    case 1:
        printf(" op1 ");
        break;
    case 2:
        printf(" op2 ");
        break;
    case 3:
        printf(" op3 ");
        break;
    case 4:
        printf(" op4 ");
        break;
    case 5:
        printf(" op5 ");
        break;
    case 6:
        printf(" op6 ");
        break;
    default:
        break;
    }
}
int main() {
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
        printf("\n");
        for(int i=0;i<n1;i++){
            printf("%d ",tab1[i]);
        }
        printf("\n");
        for(int i=0;i<n2;i++){
            printf("%d ",tab2[i]);
        }
        printf("\n");
        


    }
    command_t *  current = commands->next;
    while(current != NULL){
        printf("\n nr %d",current->nr);
        int lenA = current->lenA;
        int lenB = current->lenB;
        printf("\n rozmiary %d %d\n A: ",lenA,lenB);
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