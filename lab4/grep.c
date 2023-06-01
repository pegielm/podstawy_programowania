#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#define MAX_LEN 100

void grep (char strings[][MAX_LEN], int n, char* token) {
    token = strtok (NULL, " ");
    int option_i = 0, option_r = 0, option_w = 0, option_c = 0;
    char pattern [MAX_LEN] = "";
    // Parse options
    while (token != NULL) {
    if (strcmp(token, "-i") == 0) {
        option_i= 1;
    } else if (strcmp(token, "-r") == 0) {
        option_r = 1;
    } else if (strcmp(token, "-w") == 0) {
        option_w = 1;
    }
    else if (strcmp(token, "-c") == 0) {
        option_c = 1;
    }
    else {
        strncpy(pattern, token, MAX_LEN);
    }
    token = strtok (NULL, "");
    }
    regex_t regex;
    regmatch_t match;
    int result;
    for (int i = 0; i<n; i++) {
        char* str = strings[i];
    if (option_r) {
    // Match recursively
    }
    result = regcomp (&regex, pattern, REG_EXTENDED | REG_NOSUB);
    if (result != 0) {
        printf("Nieprawidłowe wyrażenie regularne\n");
        return;
    }
    if (regexec(&regex, str, 0, NULL, 0) == 0) {
        printf("%s\n", str);
    }
    } else {
        regfree(&regex);
        // Match in a single Line
        char* search_str = str;
        // Compiling a regular expression, taking into account the -i option
        while ((result = regcomp (&regex, pattern, REG_EXTENDED | (option_i? REG_ICASE : 0))) == 0) {
        // Searching...
            if (regexec(&regex, search_str, 1, &match, 0) == 0) {
                if (!option_w || (match.rm_so == 0 || !isalnum (*(search_str + match.rm_so - 1))) 
                &&(match.rm_eo == strlen(search_str) || !isalnum(*(search_str + match.rm_eo)))) {
                printf("%s\n", str);
                    if (option_c) {
                        break;
                    }
                } 
            }else {
            search_str += match.rm_eo;
            break;
            }
            // Free memory
            regfree(&regex);
            }
            }
    
    }
    int main(int argc, char* argv[]) {
    char strings[][MAX_LEN] = {"abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz"};
    int n = 9;
    char* token = strtok (argv[1], " ");
    grep(strings, n, token);
    return EXIT_SUCCESS;
    }