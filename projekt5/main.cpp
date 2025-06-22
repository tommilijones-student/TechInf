#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "operacje.h"

#define ROZMIAR 5

void pokazMenu() {
    printf("MENU:\n\n");
    printf("1. Wyświetl tablicę\n");
    printf("2. Największa wartość\n");
    printf("3. Najmniejsza wartość\n");
    printf("4. Oblicz średnią\n");
    printf("5. Oblicz medianę\n");
    printf("6. Zapisz tablicę do pliku\n");
    printf("7. Wczytaj tablicę z pliku\n");
    printf("8. Edytuj tablicę\n");
    printf("0. Wyjście\n");
    printf("Wybierz opcję: ");
}

int main() {
    int dane[] = {-1, 2, 6, 4, 15};
    int wybor;

    do {
        pokazMenu();
        scanf("%d", &wybor);
        switch (wybor) {
            case 0:
                break;
            case 1:
                wyswietl(dane, ROZMIAR);
                break;
            case 2:
                znajdzNajwieksza(dane, ROZMIAR);
                break;
            case 3:
                znajdzNajmniejsza(dane, ROZMIAR);
                break;
            case 4:
                liczSrednia(dane, ROZMIAR);
                break;
            case 5:
                liczMediane(dane, ROZMIAR);
                break;
            case 6:
                zapiszDoPliku(dane);
                break;
            case 7:
                wczytajZPliku(dane);
                break;
            case 8:
                zmienElement(dane, 2, 99);
                wprowadzRecznie(dane, ROZMIAR);
                break;
            default:
                printf("Nieprawidłowy wybór. Spróbuj ponownie.\n");
                break;
        }

    } while (wybor != 0);

    return 0;
}
