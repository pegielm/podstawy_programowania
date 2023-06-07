#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *start;
    char *end;
} NumberRange;

bool is_valid_digit(char digit, int base) {
    if (base <= 10) {
        return (digit >= '0' && digit < '0' + base);
    } else {
        return ((digit >= '0' && digit <= '9') || (tolower(digit) >= 'a' && tolower(digit) < 'a' + base - 10));
    }
}

NumberRange* extract_number_ranges(const char **lines, int num_lines, int base, int *num_ranges) {
    NumberRange *ranges = (NumberRange*) malloc(num_lines * sizeof(NumberRange));
    *num_ranges = 0;

    for (int i = 0; i < num_lines; i++) {
        const char *line = lines[i];
        const int line_length = strlen(line);

        int j = 0;
        while (j < line_length) {
            // Pomijanie początkowych znaków, które nie tworzą liczby
            while (j < line_length && !is_valid_digit(line[j], base)) {
                j++;
            }

            if (j >= line_length) {
                break;
            }

            // Znaleziono początek liczby
            ranges[*num_ranges].start = &((char*)line)[j];

            // Szukanie końca liczby
            while (j < line_length && is_valid_digit(line[j], base)) {
                j++;
            }

            // Znaleziono koniec liczby
            ranges[*num_ranges].end = &((char*)line)[j-1];
            (*num_ranges)++;

            if (*num_ranges >= num_lines) {
                // Dokonaj realokacji pamięci dla "niebieskiej" tablicy
                ranges = (NumberRange*) realloc(ranges, (2 * num_lines) * sizeof(NumberRange));
                num_lines *= 2;
            }
        }
    }

    return ranges;
}
