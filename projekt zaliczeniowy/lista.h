#ifndef LISTA_H
#define LISTA_H

#define MAKS_POZYCJI 10

struct Pozycja {
    char opis[100];
    int zrobione; // 0 - nie, 1 - tak
};

void pokazListe(Pozycja lista[], int ilosc);
void zmienStan(Pozycja lista[], int* ilosc);
void dodajPozycje(Pozycja lista[], int max, int* ilosc);
void usunPozycje(Pozycja lista[], int* ilosc);
void zapiszDoPliku(Pozycja lista[], int ilosc);
void wczytajZPliku(Pozycja lista[], int max, int* ilosc);

#endif
