#include <cstdio>
#include <cstdlib>

void pokazInstrukcje(const char *nazwa) {
    printf("Uzycie: %s \"wiadomosc\" <ile_razy>\n", nazwa);
    exit(EXIT_FAILURE);
}

int main(int ile, char const *dane[]) {
    if (ile != 3) {
        pokazInstrukcje(dane[0]);
    }

    int powtorzenia = std::atoi(dane[2]);
    const char *wiadomosc = dane[1];

    printf("Liczba podanych danych wejsciowych: %d\n", ile - 1);
    for (int indeks = 1; indeks < ile; ++indeks) {
        printf("Dany #%d:\t%s\n", indeks, dane[indeks]);
    }

    puts("Rozpoczynam powielanie tekstu...\n");

    for (int licznik = 1; licznik <= powtorzenia; ++licznik) {
        printf("[%02d] >> %s\n", licznik, wiadomosc);
    }

    return 0;
}
