#include "operacje.h"
#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR 5

int porownaj(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void wyswietl(int tablica[], int rozmiar) {
    printf("Zawartość tablicy:\n");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", tablica[i]);
    }
    printf("\n");
}

void znajdzNajwieksza(int tablica[], int rozmiar) {
    int max = tablica[0];
    for (int i = 1; i < rozmiar; i++) {
        if (tablica[i] > max) {
            max = tablica[i];
        }
    }
    printf("Największa wartość: %d\n", max);
}

void znajdzNajmniejsza(int tablica[], int rozmiar) {
    int min = tablica[0];
    for (int i = 1; i < rozmiar; i++) {
        if (tablica[i] < min) {
            min = tablica[i];
        }
    }
    printf("Najmniejsza wartość: %d\n", min);
}

void liczSrednia(int tablica[], int rozmiar) {
    int suma = 0;
    for (int i = 0; i < rozmiar; i++) {
        suma += tablica[i];
    }
    float srednia = (float)suma / ROZMIAR;
    printf("Średnia: %.2f\n", srednia);
}

void liczMediane(int tablica[], int rozmiar) {
    qsort(tablica, rozmiar, sizeof(int), porownaj);
    printf("Posortowana tablica:\n");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", tablica[i]);
    }
    printf("\n");
    if (rozmiar % 2 == 1) {
        printf("Mediana: %d\n", tablica[rozmiar / 2]);
    } else {
        float mediana = (tablica[rozmiar / 2 - 1] + tablica[rozmiar / 2]) / 2.0;
        printf("Mediana: %.2f\n", mediana);
    }
}

int zapiszDoPliku(int tablica[]) {
    FILE *plik = fopen("../dane.txt", "w");
    if (plik == NULL) {
        printf("Błąd podczas zapisu do pliku.\n");
        return 1;
    }
    for (int i = 0; i < ROZMIAR; i++) {
        fprintf(plik, "%d\n", tablica[i]);
    }
    fclose(plik);
    return 0;
}

int wczytajZPliku(int tablica[]) {
    FILE *plik = fopen("../dane.txt", "r");
    if (plik == NULL) {
        printf("Błąd podczas odczytu z pliku.\n");
        return 1;
    }
    for (int i = 0; i < ROZMIAR; i++) {
        if (fscanf(plik, "%d", &tablica[i]) != 1) {
            fclose(plik);
            return 2;
        }
    }
    fclose(plik);
    return 0;
}

void wprowadzRecznie(int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        printf("Podaj liczbę nr %d: ", i + 1);
        scanf("%d", &tablica[i]);
    }
}

void zmienElement(int *tablica, int indeks, int nowaWartosc) {
    *(tablica + indeks) = nowaWartosc;
}
