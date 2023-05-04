#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
            printf("%d\n", lines+1);
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
    char text[]="abc\ndef\nghi\nas";
    char option='l';

    //char text[]="abc def \nghi";
    //char option='w';

    //char text[]="abc def ghi";
    //char option='m';

    wc(text, option);


    return EXIT_SUCCESS;
}