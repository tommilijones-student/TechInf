#ifndef OPERACJE_H
#define OPERACJE_H

int porownaj(const void *a, const void *b);
void wyswietl(int tablica[], int rozmiar);
void znajdzNajwieksza(int tablica[], int rozmiar);
void znajdzNajmniejsza(int tablica[], int rozmiar);
void liczSrednia(int tablica[], int rozmiar);
void liczMediane(int tablica[], int rozmiar);
int zapiszDoPliku(int tablica[]);
int wczytajZPliku(int tablica[]);
void wprowadzRecznie(int tablica[], int rozmiar);
void zmienElement(int *tablica, int indeks, int nowaWartosc);

#endif
