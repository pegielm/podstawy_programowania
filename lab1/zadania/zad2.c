#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
double rng(double min, double max) 
{
    double zakres,mianownik;
    zakres = max - min; 
    mianownik = RAND_MAX / zakres;
    return min + (rand() / mianownik);
}
int main(){
    srand(time(NULL));
    int liczba_punktow=0;
    double pole=0;
    double wynik;
    double x,y;
    printf("podaj liczbe losowan : ");
    scanf("%d",&liczba_punktow);
    //określenie ćwiartki
    for(int i=0;i<liczba_punktow;i++){
        x=rng(-0.5,0.5);
        y=rng(-0.5,0.5);
        printf("\n x = %f , y = %f ",x,y);
        if(x<0 && y>0 && y<=(sqrt(0.25-(x*x)))){  //sprawdzanie ćwiartki i czy  znajduje sie nad/pod polem w danej ćwiartce 
            pole++;
            printf("1");
        }
        else if(x>0 && y>0 && y<=(-sqrt(-(x*x)+x)+0.5)){
            pole++;
            printf("2");
        }
        else if(x<0 && y<0 && y>=(-sqrt((1-((x*x*4)))*0.09))){
            pole++;
            printf("3");
        }
        else if(x>0 && y<0 && y>=((1.2*x*x)-0.3)){
            pole++;
            printf("4");
        }
        else if(x==0  || y==0){
            pole++;
            printf("0");
        }
    }
    wynik=pole/liczba_punktow;
    printf("\n pole figury =  %f ",wynik);
    return 0;
}
/*
LICZBA LOSOWAN      POLE  
1000                0.483000
10000               0.467100
100000              0.464950
*/