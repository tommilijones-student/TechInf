#include <iostream>
#include <cstdio>
#include <cstdlib>

int porownaj(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void druk(int s[], int size) {
    printf("tablica:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", s[i]);
    }
}

int main() {
    const int SIZE = 10;
    int number[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    druk(number, SIZE);

    int maks = number[0], min = number[0];

    for (int i = 1; i < SIZE; i++) {
        if (number[i] > maks) {
            maks = number[i];
        }
        if (number[i] < min) {
            min = number[i];
        }
    }

    printf("\nNajwieksza wartosc to: %d\n", maks);
    printf("Najmniejsza wartosc to: %d\n\n", min);

    qsort(number, SIZE, sizeof(int), porownaj);
    druk(number, SIZE);

    printf("\nMediana = %d\n", number[SIZE / 2]);

    return 0;
}
