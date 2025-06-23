#include <iostream>
#include "lista.h"

typedef struct Wezel {
    int wartosc;
    struct Wezel* nastepny;
} wezel;

wezel* glowa = NULL;
int ilosc = 0;

int dodajPoczatek(int liczba) {
    wezel* nowy = (wezel*)malloc(sizeof(wezel));
    if (nowy) {
        nowy->wartosc = liczba;
        nowy->nastepny = glowa;
        glowa = nowy;
        ilosc++;
        return OK;
    }
    return BLAD;
}

int dodajKoniec(int liczba) {
    wezel* nowy = (wezel*)malloc(sizeof(wezel));
    if (!nowy) return BLAD;
    nowy->wartosc = liczba;
    nowy->nastepny = NULL;
    if (!glowa) glowa = nowy;
    else {
        wezel* temp = glowa;
        while (temp->nastepny) temp = temp->nastepny;
        temp->nastepny = nowy;
    }
    ilosc++;
    return OK;
}

int dodajPo(int indeks, int liczba) {
    if (indeks < 0) return BLAD;
    if (indeks == 0) return dodajPoczatek(liczba);
    wezel* temp = glowa;
    for (int i = 0; i < indeks; i++) {
        if (!temp) return BLAD;
        temp = temp->nastepny;
    }
    wezel* nowy = (wezel*)malloc(sizeof(wezel));
    if (!nowy) return BLAD;
    nowy->wartosc = liczba;
    nowy->nastepny = temp->nastepny;
    temp->nastepny = nowy;
    ilosc++;
    return OK;
}

int usunPoczatek() {
    if (!glowa) return BLAD;
    wezel* temp = glowa;
    glowa = glowa->nastepny;
    free(temp);
    ilosc--;
    return OK;
}

int usunKoniec() {
    if (ilosc == 1) return usunPoczatek();
    wezel* poprzedni = NULL;
    wezel* temp = glowa;
    if (!temp) return BLAD;
    while (temp->nastepny) {
        poprzedni = temp;
        temp = temp->nastepny;
    }
    if (!poprzedni) return BLAD;
    poprzedni->nastepny = NULL;
    ilosc--;
    free(temp);
    return OK;
}

int usunPozycje(int indeks) {
    if (indeks > ilosc || indeks <= 0) return BLAD;
    if (indeks == 1) return usunPoczatek();
    wezel* poprzedni = NULL;
    wezel* temp = glowa;
    for (int i = 0; i < indeks - 1; i++) {
        poprzedni = temp;
        temp = temp->nastepny;
    }
    if (!poprzedni) return BLAD;
    poprzedni->nastepny = temp->nastepny;
    ilosc--;
    free(temp);
    return OK;
}

int szukaj(int liczba) {
    wezel* temp = glowa;
    while (temp) {
        if (temp->wartosc == liczba) return OK;
        temp = temp->nastepny;
    }
    return BLAD;
}

void pokaz() {
    wezel* temp = glowa;
    while (temp) {
        printf("%d ", temp->wartosc);
        temp = temp->nastepny;
    }
}

int licznik() {
    return ilosc;
}

void wyczysc() {
    while (ilosc) usunPoczatek();
    glowa = NULL;
}
