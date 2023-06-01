#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


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
        printf("Zla opcja");
        return;
    }

}


void wc(char *text, char option) {
    int lines = 0;
    int words = 0;
    int chars = 0;
    int in_word = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if(text[i]!=' ')chars++;

        if (text[i] == '\n') {
            lines++;
        }

        if (isspace(text[i])) {
            in_word = 0;
        } else if (!in_word) {
            words++;
            in_word = 1;
        }
    }
    switch (option) {
        case 'l':
            printf("%d\n", lines);
            break;
        case 'w':
            printf("%d\n", words);
            break;
        case 'm':
            printf("%d\n", chars);
            break;
        default:
            printf("%d %d %d\n", lines, words, chars);
    }
}

int main() {
    char command[100];
    char option[10];
    char text[1000];

    printf("Podaj komende:\n");
    fgets(command, sizeof(command), stdin);

    // Usunięcie znaku nowej linii z komendy
    command[strcspn(command, "\n")] = '\0';

    // Wyszukanie spacji w komendzie
    char *space = strchr(command, ' ');
    if (space == NULL) {
        printf("Nieprawidlowa komenda\n");
        return 1;
    }

    // Podział komendy na opcję i tekst
    strncpy(option, command, space - command);
    option[space - command] = '\0';
    strcpy(text, space + 1);

    // Wczytywanie danych ze standardowego wejścia
    printf("Wczytuje dane(do ctrl+z):\n");
    char line[1000];
    char input[1000] = "";

    while (fgets(line, sizeof(line), stdin) != NULL) {
        strcat(input, line);
    }

    // Wywołanie odpowiedniej funkcji na podstawie komendy
    //printf("option >%s<\n",text);
    if (strcmp(option, "cut") == 0) {
        cut(input, text);
    } else if (strcmp(option, "wc") == 0) {
        wc(input, text[1]);
    } else {
        printf("Nieznana komenda\n");
        return 1;
    }

    return 0;
}

/*
cut
"-d: -f0,1,2,6"
"a:b:c:d:e:f:g:h:i:j:k"

"-c2-5"
"-c0,2,4,6,7,8,9"
wc
-l 
-w
-m
*/




