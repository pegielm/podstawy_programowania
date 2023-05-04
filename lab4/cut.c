#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void cut(char* text, char* option) {
    char delimiter;
    int field;
    int i,j,k,l=0;
    char c;
    int fields[50];
    if (option[0]=='-' && option[1]=='d'){
        delimiter = option[2];
        printf("delim: %c\n", delimiter);
        if(option[3]==' ' && option[4]=='-' && option[5]=='f'){
            int len = strlen(option);
            for(i = 6; i < len; i++){
                if(isdigit(option[i])){
                    field = option[i] - '0';
                    fields[l] = field;
                    l++;
                }

            }
            for(i=0; i<l; i++){
                printf("%d ", fields[i]);
            }
            printf("\n");
            int current =0;
            for(i=0; text[i]!='\0'; i++){
                if(text[i]==delimiter){
                    current++;
                }
                else{
                    for (j = 0; j < l; j++) {
                        if (current == fields[j]) {
                            for (k = i; text[k] != delimiter; k++) {
                                printf("%c", text[k]);
                            }
                            printf("\n");
                        }
                    }
                }
            }

        }
    }
    else if(option[0]=='-' && option[1]=='c'){
        if(isdigit(option[2]) && option[3]=='-' && isdigit(option[4])){
            int start = option[2] - '0';
            int end = option[4] - '0';
            for(i=start; i<=end; i++){
                printf("%c", text[i]);
            }
            printf("\n");
        }
        else{
            l=0;
            int len = strlen(option);
            for(i = 2; i < len; i++){
                if(isdigit(option[i])){
                    field = option[i] - '0';
                    fields[l] = field;
                    l++;
                }

            }
            len = strlen(text);
            for(j=0; j<l; j++){
                printf("%c", text[fields[j]]);

            }

            
            printf("\n");
        }
        
    }
    else{
        printf("Invalid option");
        return;
    }

}

int main() {
    char text[] = "a:b:c:d:e:f:g:h:i:j:k";
    char option[] = "-d: -f0,1,2";
    //char option[] = "-c0,2,4,6,7,8,9";
    //char option[] = "-c2-5";
    

    cut(text, option);

    return 0;
}