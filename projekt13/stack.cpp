#include <iostream>
#include "stack.h"

typedef struct Wezel {
    int wartosc;
    struct Wezel* nastepny;
} wezel;

wezel* szczyt = NULL;
int ilosc = 0;

int push(int liczba) {
    wezel* nowy = (wezel*)malloc(sizeof(wezel));
    if (!nowy) return BLAD;
    nowy->wartosc = liczba;
    nowy->nastepny = szczyt;
    szczyt = nowy;
    ilosc++;
    return OK;
}

int pop() {
    if (!szczyt) return BLAD;
    wezel* temp = szczyt;
    szczyt = szczyt->nastepny;
    free(temp);
    ilosc--;
    return OK;
}

int peek() {
    if (!szczyt) return BLAD;
    return szczyt->wartosc;
}

void wyswietl() {
    wezel* temp = szczyt;
    while (temp) {
        printf("%d ", temp->wartosc);
        temp = temp->nastepny;
    }
}

int rozmiar() {
    return ilosc;
}

void wyczysc() {
    while (szczyt) pop();
}
