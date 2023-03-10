/*
Aby program się kompilował:
- Odkomentuj dyrektywy '#include' znajdujące się w liniach 7-11
- Zastąp każde wystąpienie 'plikNagłówkowyNr{N}.h' nazwą konkretnego, wymaganego pliku nagłówkowego
*/
 #define _XOPEN_SOURCE
 #include <stdbool.h>
 #include <stdio.h>
 #include <stddef.h>
 #include <complex.h>
 #include <time.h> 
 #include <stdlib.h> 
 
 
int main()
{
    int n = rand();
    int iloczyn = 1;
    double a, b, c, d;
    double complex z1;
    double complex z2;
    double complex suma;
    /*
    // Przykład ze strony 'https://valgrind.org/docs/manual/quick-start.html'
    // int* x = malloc(10 * sizeof(int));
    // x[10] = 0;  
    // Komentarz
    */
    bool zywy = true;
    printf("\033[31mZmienna 'zywy' ma wartość:\033[0m %d\n", zywy);
    srand(time(NULL));
    
    printf("\033[31mWylosowano liczbę:\033[0m %d\n", n);
    n = n % 10;
    printf("\033[31mWylosowana liczba modulo 10 =\033[0m %d\n", n);
    switch (n)
    {
    case 1:
        printf("\033[31mOtrzymana wartość należy do przedziału od 1 do 5\033[0m\n");
        break;
    case 2:
        printf("\033[31mOtrzymana wartość należy do przedziału od 1 do 5\033[0m\n");
        break;
    case 3:
        printf("\033[31mOtrzymana wartość należy do przedziału od 1 do 5\033[0m\n");
        break;
    case 4:
        printf("\033[31mOtrzymana wartość należy do przedziału od 1 do 5\033[0m\n");
        break;
    case 5:
        printf("\033[31mOtrzymana wartość należy do przedziału od 1 do 5\033[0m\n");
        break;
    case 9:
        printf("\033[31mOtrzymano wartość 9\033[0m\n");
        break;
    default:
        printf("\033[31mOtrzymana wartość nie należy do przedziału od 1 do 5 oraz jest różna od 9\033[0m\n");
    }
    
   /* for (int i = n; i > 0; i--)
    {
        iloczyn = iloczyn * i;
        printf("\033[31m%d \033[0m", i);
    }
    */
    printf("\033[31mStart\n");
    printf("\033[31mWartość iloczynu:\033[0m %d\n", iloczyn);
    
    printf("\033[31mObliczanie (a+bi)+(c-di)\033[0m\n");
    printf("\033[31mPodaj wartość współczynników: a,b,c oraz d: \033[0m");
    if (scanf("%lf%lf%lf%lf", &a, &b, &c, &d) < 4)
    {
        printf("\n\033[31mPodałeś(aś) zbyt mało liczb\033[0m\n");
        return 1;
    }
    z1 = a + b * I;
    z2 = c - d * I;
    suma = z1 + z2;
    printf("\033[31m(%.1f+%.1fi) + (%.1f-%.1fi)  =\033[0m %.1f%+.1fi\n", a, b, c, d, creal(suma), cimag(suma));
    /*
    // https://www.geeksforgeeks.org/_generic-keyword-c/
    */
    #define cbrt(x) _Generic((x), long double: cbrtl, \
                                      default: cbrt, \
                                        float: cbrtf)(x)
                                        /*
    // https://www.geeksforgeeks.org/g-fact-38-anonymous-union-and-structure/
    */
   /*
    struct T
    {
        int tag;
        union {
            float x;
            int n;
        };
    };
    */
    return 0;
}