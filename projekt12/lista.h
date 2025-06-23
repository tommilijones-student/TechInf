#ifndef LISTA_H
#define LISTA_H

#define OK 0
#define BLAD 1

int dodajPoczatek(int liczba);
int dodajKoniec(int liczba);
int dodajPo(int indeks, int liczba);
int usunPoczatek();
int usunKoniec();
int usunPozycje(int indeks);
int szukaj(int liczba);
void pokaz();
int licznik();
void wyczysc();

#endif
