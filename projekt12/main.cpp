#include <iostream>
#include "lista.h"

void czysc() {
    while (getchar() != '\n');
}

void menu() {
    printf("LISTA JEDNOKIERUNKOWA\n");
    printf("1. Dodaj na poczatek\n2. Dodaj na koniec\n3. Dodaj po elemencie\n4. Usun pierwszy\n");
    printf("5. Usun ostatni\n6. Usun wybrany\n7. Pokaz liste\n8. Szukaj\n9. Wyczyść\n0. Wyjscie\n\n");
}

int main() {
    int liczba = 0, pozycja = 0, opcja = 0, kod = 0;

    while (1) {
        menu();
        while (!scanf("%d", &opcja)) {
            printf("To nie liczba. Podaj liczbe: ");
            czysc();
        }

        switch (opcja) {
            case 1:
                printf("Podaj liczbe: ");
                while (!scanf("%d", &liczba)) {
                    printf("To nie liczba. Podaj liczbe: ");
                    czysc();
                }
                kod = dodajPoczatek(liczba);
                !kod ? printf("Dodano.\n\n") : printf("Nie dodano.\n\n");
                break;

            case 2:
                printf("Podaj liczbe: ");
                while (!scanf("%d", &liczba)) {
                    printf("To nie liczba. Podaj liczbe: ");
                    czysc();
                }
                kod = dodajKoniec(liczba);
                !kod ? printf("Dodano.\n\n") : printf("Nie dodano.\n\n");
                break;

            case 3:
                printf("Po ktorym elemencie dodac: ");
                while (!scanf("%d", &pozycja)) {
                    printf("To nie liczba. Podaj liczbe: ");
                    czysc();
                }
                printf("Liczba do dodania: ");
                while (!scanf("%d", &liczba)) {
                    printf("To nie liczba. Podaj liczbe: ");
                    czysc();
                }
                kod = dodajPo(pozycja, liczba);
                !kod ? printf("Dodano.\n\n") : printf("Nie dodano.\n\n");
                break;

            case 4:
                kod = usunPoczatek();
                !kod ? printf("Usunieto pierwszy.\n\n") : printf("Brak elementow.\n\n");
                break;

            case 5:
                kod = usunKoniec();
                !kod ? printf("Usunieto ostatni.\n\n") : printf("Brak elementow.\n\n");
                break;

            case 6:
                if (licznik()) {
                    printf("Ktory element usunac: ");
                    while (!scanf("%d", &pozycja)) {
                        printf("To nie liczba. Podaj liczbe: ");
                        czysc();
                    }
                    kod = usunPozycje(pozycja);
                } else kod = 1;
                !kod ? printf("Usunieto nr %d.\n\n", pozycja) : printf("Nie usunieto.\n\n");
                break;

            case 7:
                printf("Lista: ");
                pokaz();
                printf("\nLiczba elementow: %d\n\n", licznik());
                break;

            case 8:
                printf("Szukana wartosc: ");
                while (!scanf("%d", &liczba)) {
                    printf("To nie liczba. Podaj liczbe: ");
                    czysc();
                }
                kod = szukaj(liczba);
                !kod ? printf("Znaleziono %d.\n\n", liczba) : printf("Brak %d.\n\n", liczba);
                break;

            case 9:
                wyczysc();
                printf("Lista wyczyszczona.\n");
                break;

            case 0:
                wyczysc();
                return 0;

            default:
                system("cls");
                printf("Zla opcja.\n\n");
        }
    }
    wyczysc();
    return 0;
}
