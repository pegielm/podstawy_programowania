#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
void wypisz(int tab[], int n, int k){
    //wypisz elementy od n do k
    for(int i=n;i<k;i++){ 
        if(tab[i]>=0){
            printf(" ");
        }
        printf("%d ", tab[i]);
    }
}
void spacje(int n){
    for(int i=0;i<n;i++){
        printf("   ");
    }
}
int random(int min,int max){
    int range=max-min;
    int resoult=(rand()%range)+min;
    return resoult;
}
void kopiec(int tab[],int n,int i){
    int max=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && tab[l]>tab[max]){
        max=l;
    }
    if(r<n && tab[r]>tab[max]){
        max=r;
    }
    if(max!=i){
        int temp=tab[i];
        tab[i]=tab[max];
        tab[max]=temp;
        kopiec(tab,n,max);
    }
}
int * sortowanie(int tab[],int n){
    for(int i=n/2-1;i>=0;i--){
        kopiec(tab,n,i);
    }
    wypisz(tab,0,n);
    spacje(n);
    printf("<- utworzenie kopca\n");
    for(int i=n-1;i>=0;i--){
        int temp=tab[0];
        tab[0]=tab[i];
        tab[i]=temp;
        kopiec(tab,i,0);
        wypisz(tab,0,i);
        spacje(n);
        wypisz(tab,i,n);
        printf("<-przeniesienie wierzcholka %d do sorted i ponowne kopcowanie\n",tab[i]);
    }
    return tab;
}
int main(int argc, char **argv){
    srand(time(NULL));
    bool t = false;
    if(argc==2){
        if(strcmp(argv[1],"--track")==0){
            printf("track\n");
            t=true;
        }
    }
    int n;
    scanf("%d", &n);
    int *heap = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        heap[i]=random(-10,10);
    }
    wypisz(heap,0,n);
    spacje(n);
    printf("<- wylosowana tablica\n");
    int *sorted=sortowanie(heap,n);

    
    return 0;
}