#include "stos.h"

#define ROZMIAR 5

static int dane[ROZMIAR];
static int poczatek = -1;
static int koniec = -1;

int czyPusta() {
    return (poczatek == -1);
}

int czyPelna() {
    return ((koniec + 1) % ROZMIAR == poczatek);
}

void dodaj(int x) {
    if (!czyPelna()) {
        if (poczatek == -1) {
            poczatek = 0;
        }
        koniec = (koniec + 1) % ROZMIAR;
        dane[koniec] = x;
    }
}

int usun() {
    if (!czyPusta()) {
        int temp = dane[poczatek];
        if (poczatek == koniec) {
            poczatek = -1;
            koniec = -1;
        } else {
            poczatek = (poczatek + 1) % ROZMIAR;
        }
        return temp;
    }
    return -1;
}

int pierwsza() {
    if (!czyPusta()) {
        return dane[poczatek];
    }
    return -1;
}
