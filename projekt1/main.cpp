#include <iostream>
#include <cstdio>

void druk(int s[], int size) {
    printf("tablica:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", s[i]);
    }
}

void sortuj(int s[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (s[i] > s[j]) {
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

double liczMediane(int s[], int size) {
    if (size % 2 == 1) {

        return s[size / 2];
    } else {

        return (s[size / 2 - 1] + s[size / 2]) / 2.0;
    }
}

int main() {
    const int SIZE = 10;
    int number[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    druk(number, SIZE);

    int maks = number[0], min = number[0];

    for (int i = 1; i < SIZE; i++) {
        if (number[i] > maks) maks = number[i];
        if (number[i] < min) min = number[i];
    }

    printf("\nNajwieksza wartosc to: %d\n", maks);
    printf("Najmniejsza wartosc to: %d\n\n", min);

    sortuj(number, SIZE);
    druk(number, SIZE);

    double mediana = liczMediane(number, SIZE);
    printf("\nMediana = %.1f\n", mediana);

    return 0;
}