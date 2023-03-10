#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

int random(int min,int max){
    
    int range=max-min;
    int resoult=(rand()%range)+min;
    return resoult;
}
int prime(int x){
    if(x<2){
        return false;
    }
    for(int i=2;i<=x/2;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;

}

int main(){
    int x,y,n;
    bool flag=true;
    int positive=0;
    int negative=0;
    printf("podaj liczbe losowan ");
    scanf("%d",&n);
    srand(time(NULL));
    for(int i=0;i<=n;i++){
        x=random(-1001,1001);
        y=random(-1001,1001);
        printf("wylosowano %d , %d \n",x,y);

        if(x>0){
            positive++;
        }
        else if(x<0){
            negative++;
        }

        if(y>0){
            positive++;
        }
        else if(y<0){
            negative++;
        }
        if(prime(x+y)){
            printf("suma liczb jest liczba pierwsza %d ",x+y);
            flag=false;
            break;
        }
    }
    if(flag){
        printf("\nprzekroczono ilosc losowan ");
    }
    printf("\nilosc liczb dodatnich %d , ilosc liczb ujemnych %d",positive,negative);
    
    return 0;
}