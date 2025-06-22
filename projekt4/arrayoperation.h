#ifndef ARRAYOPERATION_H
#define ARRAYOPERATION_H

int porownaj(const void *a, const void *b);
void pokazTablice(int tablica[], int rozmiar);
void znajdzMax(int tablica[], int rozmiar);
void znajdzMin(int tablica[], int rozmiar);
void obliczSrednia(int tablica[], int rozmiar);
void obliczMediane(int tablica[], int rozmiar);
int zapiszDoPliku(int tablica[]);
int wczytajZPliku(int tablica[]);
void wprowadzLiczby(int tablica[], int rozmiar);
void zmienElement(int *tab, int indeks, int nowa_wartosc);

#endif
