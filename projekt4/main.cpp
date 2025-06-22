#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "arrayoperation.h"

#define DLUGOSC 5

void wyswietlMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Wyswietl tablice\n");
    printf("2. Najwieksza wartosc\n");
    printf("3. Najmniejsza wartosc\n");
    printf("4. Srednia\n");
    printf("5. Mediana\n");
    printf("6. Zapisz dane do pliku\n");
    printf("7. Wczytaj dane z pliku\n");
    printf("8. Zmien dane\n");
    printf("0. Zakoncz\n");
    printf("Wybor: ");
}

int main() {
    int liczby[DLUGOSC] = {-1, 2, 6, 4, 15};
    int wybor;

    do {
        wyswietlMenu();
        scanf("%d", &wybor);

        switch (wybor) {
            case 0: break;
            case 1:
                pokazTablice(liczby, DLUGOSC);
                break;
            case 2:
                znajdzMax(liczby, DLUGOSC);
                break;
            case 3:
                znajdzMin(liczby, DLUGOSC);
                break;
            case 4:
                obliczSrednia(liczby, DLUGOSC);
                break;
            case 5:
                obliczMediane(liczby, DLUGOSC);
                break;
            case 6:
                zapiszDoPliku(liczby);
                break;
            case 7:
                wczytajZPliku(liczby);
                break;
            case 8:
                zmienElement(liczby, 2, 99);
                wprowadzLiczby(liczby, DLUGOSC);
                break;
            default:
                printf("Niepoprawna opcja!\n");
        }

    } while (wybor != 0);

    return 0;
}
