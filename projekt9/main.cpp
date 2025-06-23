#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wyswietlInstrukcje(const char* nazwa_programu) {
    printf("%s <liczba1> <dzialanie> <liczba2>\n", nazwa_programu);
    printf("Dostepne operacje: add  sub  mul  div\n");
    exit(1);
}

int main(int liczba_arg, const char* argumenty[]) {
    if (liczba_arg != 4) {
        wyswietlInstrukcje(argumenty[0]);
    }

    double x = atof(argumenty[1]);
    const char* dzialanie = argumenty[2];
    double y = atof(argumenty[3]);
    double wynik;

    if (strcmp(dzialanie, "add") == 0) {
        wynik = x + y;
        printf("Wynik: %f + %f = %f\n", x, y, wynik);
    } else if (strcmp(dzialanie, "sub") == 0) {
        wynik = x - y;
        printf("Wynik: %f - %f = %f\n", x, y, wynik);
    } else if (strcmp(dzialanie, "mul") == 0) {
        wynik = x * y;
        printf("Wynik: %f * %f = %f\n", x, y, wynik);
    } else if (strcmp(dzialanie, "div") == 0) {
        if (y == 0) {
            printf("Blad: dzielenie przez zero!\n");
            return 1;
        }
        wynik = x / y;
        printf("Wynik: %f / %f = %f\n", x, y, wynik);
    } else {
        printf("Nieznana operacja: %s\n", dzialanie);
        wyswietlInstrukcje(argumenty[0]);
    }

    return 0;
}
