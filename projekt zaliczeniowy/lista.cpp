#include "lista.h"
#include <stdio.h>
#include <string.h>

void pokazListe(Pozycja lista[], int ilosc) {
    if (ilosc == 0) {
        printf("Lista jest pusta.\n");
        return;
    }

    for (int i = 0; i < ilosc; ++i) {
        printf("%d. [%c] %s\n", i + 1, lista[i].zrobione ? 'X' : ' ', lista[i].opis);
    }
}

void zmienStan(Pozycja lista[], int* ilosc) {
    int nr;
    if (*ilosc == 0) {
        printf("Brak pozycji do zmiany.\n");
        return;
    }

    printf("Podaj numer pozycji do zmiany stanu (1-%d): ", *ilosc);
    scanf("%d", &nr);
    while (getchar() != '\n') {}

    if (nr < 1 || nr > *ilosc) {
        printf("Niepoprawny numer.\n");
        return;
    }

    lista[nr - 1].zrobione = !lista[nr - 1].zrobione;
    printf("Zmieniono stan zadania.\n");
}

void dodajPozycje(Pozycja lista[], int max, int* ilosc) {
    if (*ilosc >= max) {
        printf("Lista jest pelna.\n");
        return;
    }

    printf("Podaj opis nowej pozycji: ");
    fgets(lista[*ilosc].opis, sizeof(lista[*ilosc].opis), stdin);
    lista[*ilosc].opis[strcspn(lista[*ilosc].opis, "\n")] = 0;

    lista[*ilosc].zrobione = 0;
    (*ilosc)++;
    printf("Dodano nowa pozycje.\n");
}

void usunPozycje(Pozycja lista[], int* ilosc) {
    int nr;
    if (*ilosc == 0) {
        printf("Brak pozycji do usuniecia.\n");
        return;
    }

    printf("Podaj numer pozycji do usuniecia (1-%d): ", *ilosc);
    scanf("%d", &nr);
    while (getchar() != '\n') {}

    if (nr < 1 || nr > *ilosc) {
        printf("Niepoprawny numer.\n");
        return;
    }

    for (int i = nr - 1; i < *ilosc - 1; ++i) {
        lista[i] = lista[i + 1];
    }

    (*ilosc)--;
    printf("Usunieto pozycje.\n");
}

void zapiszDoPliku(Pozycja lista[], int ilosc) {
    FILE* plik = fopen("../zadania.txt", "w");
    if (!plik) {
        printf("Nie mozna zapisac pliku.\n");
        return;
    }

    for (int i = 0; i < ilosc; ++i) {
        fprintf(plik, "%d;%s\n", lista[i].zrobione, lista[i].opis);
    }

    fclose(plik);
    printf("Zapisano liste do pliku.\n");
}

void wczytajZPliku(Pozycja lista[], int max, int* ilosc) {
    FILE* plik = fopen("../zadania.txt", "r");
    if (!plik) {
        printf("Nie znaleziono pliku z lista.\n");
        return;
    }

    *ilosc = 0;
    while (*ilosc < max && fscanf(plik, "%d;%[^\n]\n", &lista[*ilosc].zrobione, lista[*ilosc].opis) == 2) {
        (*ilosc)++;
    }

    fclose(plik);
    printf("Wczytano %d pozycji z pliku.\n", *ilosc);
}
