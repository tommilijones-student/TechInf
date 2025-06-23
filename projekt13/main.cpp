#include <iostream>
#include "stack.h"

void czyscBufor() {
    while (getchar() != '\n');
}

void menu() {
    printf("STOS (LIFO)\n");
    printf("1. Dodaj (push)\n2. Usun (pop)\n3. Szczyt (peek)\n4. Pokaz stos\n5. Liczba elementow\n6. Wyczyść\n0. Wyjście\n\n");
}

int main() {
    int liczba = 0, opcja = 0, kod = 0;

    while (1) {
        menu();
        while (!scanf("%d", &opcja)) {
            printf("To nie liczba. Podaj liczbe: ");
            czyscBufor();
        }

        switch (opcja) {
            case 1:
                printf("Podaj liczbe: ");
                while (!scanf("%d", &liczba)) {
                    printf("To nie liczba. Podaj liczbe: ");
                    czyscBufor();
                }
                kod = push(liczba);
                !kod ? printf("Dodano na stos.\n\n") : printf("Blad dodawania.\n\n");
                break;

            case 2:
                kod = pop();
                !kod ? printf("Usunieto ze stosu.\n\n") : printf("Stos pusty.\n\n");
                break;

            case 3:
                kod = peek();
                kod != BLAD ? printf("Szczyt stosu: %d\n\n", kod) : printf("Stos pusty.\n\n");
                break;

            case 4:
                printf("Stos: ");
                wyswietl();
                printf("\n\n");
                break;

            case 5:
                printf("Liczba elementow: %d\n\n", rozmiar());
                break;

            case 6:
                wyczysc();
                printf("Stos wyczyszczony.\n\n");
                break;

            case 0:
                wyczysc();
                return 0;

            default:
                printf("Niepoprawna opcja.\n\n");
        }
    }
}
