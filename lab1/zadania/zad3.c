#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
bool sprawdz(char *liczba,int dl){
    for (int i=0;i<dl;i++)
    {
        if (!isdigit(liczba[i])){
            return false;
        }
        /*printf(" znak %c \n",liczba[i]); */
    }
    return true;
}
void slupek(char *dluga,char *krotka,int d,int k){
    if(k==0 || d==0){
        printf("\n nie podano dwoch liczb");
        return;
    }
    if(!sprawdz(dluga,d)){
        printf("\n to nie liczba -> %s",dluga);
        return;
    }
    if(!sprawdz(krotka,k)){
        printf("\n to nie liczba -> %s",krotka);
        return;
    }

    printf("\n dluzsza liczba %s , krotsza %s",dluga,krotka);
    for(int i=d-1;i>=0;i--){
        
    }
}
int main(){
    char liczba1[100], liczba2[100];
    printf("podaj pierwsza liczbe : ");
    scanf("%s",&liczba1);
    printf("podaj druga liczbe : ");
    scanf("%s",&liczba2);
    int n1=strlen(liczba1),n2=strlen(liczba2);
    if(n1>=n2){
        slupek(liczba1,liczba2,n1,n2);
    }
    else{
        slupek(liczba2,liczba1,n2,n1);
    }

    
}