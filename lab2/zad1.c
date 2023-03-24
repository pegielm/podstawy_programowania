#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    bool run=true;
    while(run){
        char command;
        
        command = getchar();
        
        if (command == EOF){
            printf("koniec"); //trzeba enter po ctrl+z
            break;
        }
    }
    return 0;
}