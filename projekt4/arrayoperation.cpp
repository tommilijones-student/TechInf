#include "arrayoperation.h"
#include <stdio.h>
#include <stdlib.h>

#define DLUGOSC 5

int porownaj(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void pokazTablice(int tablica[], int rozmiar) {
    printf("Zawartosc:\n");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", tablica[i]);
    }
    printf("\n");
}

void znajdzMax(int tablica[], int rozmiar) {
    int max = tablica[0];
    for (int i = 1; i < rozmiar; i++) {
        if (tablica[i] > max) max = tablica[i];
    }
    printf("Najwiekszy element: %d\n", max);
}

void znajdzMin(int tablica[], int rozmiar) {
    int min = tablica[0];
    for (int i = 1; i < rozmiar; i++) {
        if (tablica[i] < min) min = tablica[i];
    }
    printf("Najmniejszy element: %d\n", min);
}

void obliczSrednia(int tablica[], int rozmiar) {
    int suma = 0;
    for (int i = 0; i < rozmiar; i++) suma += tablica[i];
    printf("Srednia: %.2f\n", (float)suma / DLUGOSC);
}

void obliczMediane(int tablica[], int rozmiar) {
    qsort(tablica, rozmiar, sizeof(int), porownaj);
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", tablica[i]);
    }
    printf("\nMediana: %d\n", tablica[rozmiar / 2]);
}

int zapiszDoPliku(int tablica[]) {
    FILE *plik = fopen("../array.txt", "w");
    if (plik == NULL) {
        printf("Nie udalo sie zapisac pliku.\n");
        return 1;
    }
    for (int i = 0; i < DLUGOSC; i++) {
        fprintf(plik, "%d\n", tablica[i]);
    }
    fclose(plik);
    return 0;
}

int wczytajZPliku(int tablica[]) {
    FILE *plik = fopen("../array.txt", "r");
    if (plik == NULL) {
        printf("Blad otwarcia pliku.\n");
        return 1;
    }
    for (int i = 0; i < DLUGOSC; i++) {
        if (fscanf(plik, "%d", &tablica[i]) != 1) {
            fclose(plik);
            return 2;
        }
    }
    fclose(plik);
    return 0;
}

void wprowadzLiczby(int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        printf("Podaj wartosc [%d]: ", i + 1);
        scanf("%d", &tablica[i]);
    }
}

void zmienElement(int *tab, int indeks, int nowa_wartosc) {
    *(tab + indeks) = nowa_wartosc;
}
