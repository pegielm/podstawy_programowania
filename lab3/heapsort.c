#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
int random(int min,int max){
    int range=max-min;
    int resoult=(rand()%range)+min;
    return resoult;
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
    for(int i=0;i<n;i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
    
    return 0;
}