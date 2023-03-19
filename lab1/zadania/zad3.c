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
    int a,b,roznica=d-k,suma,reszta=0;
    char gora[100];
    int wynik[100];
    char dc,kc;
    bool przesun=false;
    char dodatkowa;
    for(int i=d-1,j=k-1;j>=0;i--,j--){ //idziemy od końca obu liczb dopóki dłuższa sie nie skończy
        
        dc=dluga[i];
        kc=krotka[j];
        a=dc-'0';
        b=kc-'0';
        
        printf("\n i %d   j %d   a %d     b %d",i,j,a,b);
        suma=a+b+reszta;
        if(suma>9){
            reszta=1;
            gora[i]='1';
        }
        else{
            reszta=0;
            gora[i]='0';
        }
        suma = suma % 10;
        wynik[i]=suma;
        printf("\n suma: %d , indeks i: %d j: %d , roznica %d",suma,i,j,roznica);

    }
    for(int i=roznica-1;i>=0;i--){
        dc=dluga[i];
        a=dc-'0';
        suma=a+reszta;
        if(suma>9){
            reszta=1;
            gora[i]='1';
        }
        else{
            reszta=0;
            gora[i]='0';
        }
        suma=suma % 10;
        wynik[i]=suma;
    }
    printf("\n");
    for(int i=0;i<d;i++){
        if(gora[i]=='1'){
            printf("%c ",gora[i]);
        }
        else{
            printf("  ");
        }
    }

    printf("\n  ");
    for(int i=0;i<d;i++){
        printf("%c ",dluga[i]);
    }

    printf("\n  ");
    for(int i=(roznica*2)-1;i>=0;i--){
        printf(" ");
    }
    for(int i=0;i<k;i++){
        printf("%c ",krotka[i]);
    }
    
    printf("\n");
    if(reszta==1){
        printf("1 ");
    }
    else{
        printf("  ");
    }
    for(int i=0;i<d;i++){
        printf("%d ",wynik[i]);
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