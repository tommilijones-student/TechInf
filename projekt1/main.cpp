#include <iostream>
#include <cstdio>

void druk(int s[]) {
    printf("tablica:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", s[i]);
    }
}

void sortuj(int s[], int rozmiar) {
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = i + 1; j < rozmiar; j++) {
            if (s[i] > s[j]) {
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    int number[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    druk(number);

    int maks = number[0], min = number[0];

    for (int i = 1; i < 10; i++) {
        if (number[i] > maks) {
            maks = number[i];
        }
        if (number[i] < min) {
            min = number[i];
        }
    }

    printf("\nNajwieksza wartosc to: %d\n", maks);
    printf("Najmniejsza wartosc to: %d\n\n", min);

    sortuj(number, 10);


    printf("mediana=%d\n", number[10/2]);

    return 0;
}