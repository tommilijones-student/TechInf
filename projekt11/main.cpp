#include "Stos.h"

#define ROZMIAR_STOSU 5

static int dane[ROZMIAR_STOSU];
static int indeks = -1;

int czyPusty() {
    return indeks == -1;
}

int czyPelny() {
    return indeks == ROZMIAR_STOSU - 1;
}

void wloz(int wartosc) {
    if (!czyPelny()) {
        indeks++;
        dane[indeks] = wartosc;
    }
}

int zdejmij() {
    if (!czyPusty()) {
        return dane[indeks--];
    }
    return -1;
}

int szczyt() {
    if (!czyPusty()) {
        return dane[indeks];
    }
    return -1;
}
