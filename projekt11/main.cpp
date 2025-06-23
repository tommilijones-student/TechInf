#include <stdio.h>
#include <stdlib.h>
#include "Kolejka.h"

void pokazOpcje() {
    printf("\n");
    printf("1 - dodaj liczbe\n");
    printf("2 - podejrzyj pierwsza\n");
    printf("3 - usun pierwsza\n");
    printf("4 - czy pusta\n");
    printf("5 - czy pelna\n");
    printf("6 - wyjscie\n\n");
}

int main() {
    int wartosc = 0;
    int wybor = 0;
    printf("Symulacja kolejki\n");

    while (1) {
        pokazOpcje();
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                if (!czyPelna()) {
                    printf("Wprowadz liczbe: ");
                    scanf("%d", &wartosc);
                    dodaj(wartosc);
                } else {
                    printf("Brak miejsca!\n\n");
                }
                break;
            case 2:
                if (!czyPusta()) {
                    wartosc = pierwsza();
                    printf("Pierwsza liczba: %d\n", wartosc);
                } else {
                    printf("Brak elementow!\n\n");
                }
                break;
            case 3:
                if (!czyPusta()) {
                    wartosc = usun();
                    printf("Usunieto: %d\n", wartosc);
                } else {
                    printf("Brak elementow!\n\n");
                }
                break;
            case 4:
                if (czyPusta()) {
                    printf("Pusta.\n");
                } else {
                    printf("Niepusta.\n");
                }
                break;
            case 5:
                if (czyPelna()) {
                    printf("Pelna.\n");
                } else {
                    printf("Niepelna.\n");
                }
                break;
            case 6:
                return 0;
            default:
                printf("Zly wybor.\n\n");
        }
    }

    return 0;
}
