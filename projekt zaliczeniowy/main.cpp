#include <stdio.h>
#include "lista.h"

int aktualnaIlosc = 0;
Pozycja rzeczy[MAKS_POZYCJI] = {};

void pokazMenu() {
    printf("\n======== Lista Zadan ========\n");
    printf("1. Wyswietl liste\n");
    printf("2. Zmien status zadania\n");
    printf("3. Dodaj zadanie do listy\n");
    printf("4. Usun zadanie z listy\n");
    printf("5. Zapisz liste do pliku\n");
    printf("6. Wczytaj liste z pliku\n\n");
    printf("0. Zamknij program\n\n");
    printf("Twoj wybor: ");
}

int main() {
    int wybor;

    do {
        pokazMenu();
        scanf("%d", &wybor);
        while (getchar() != '\n') {}

        switch (wybor) {
            case 0:
                printf("Zamykanie programu...\n");
                break;
            case 1:
                pokazListe(rzeczy, aktualnaIlosc);
                break;
            case 2:
                zmienStan(rzeczy, &aktualnaIlosc);
                break;
            case 3:
                dodajPozycje(rzeczy, MAKS_POZYCJI, &aktualnaIlosc);
                break;
            case 4:
                usunPozycje(rzeczy, &aktualnaIlosc);
                break;
            case 5:
                zapiszDoPliku(rzeczy, aktualnaIlosc);
                break;
            case 6:
                wczytajZPliku(rzeczy, MAKS_POZYCJI, &aktualnaIlosc);
                break;
            default:
                printf("BLAD!\n");
                break;
        }
    } while (wybor != 0);

    return 0;
}
