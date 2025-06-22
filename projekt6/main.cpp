#include <iostream>

void wyswietlMenu() {
    std::cout << "\n";
    std::cout << "====== MENU ======\n";
    std::cout << "0 - Zakoncz program\n";
    std::cout << "1 - Dodaj\n";
    std::cout << "2 - Odejmij\n";
    std::cout << "3 - Pomnoz\n";
    std::cout << "4 - Podziel\n";
    std::cout << "Wybierz opcje: ";
}

void pobierzLiczby(int *pierwsza, int *druga) {
    std::cout << "Podaj pierwsza liczbe: ";
    std::cin >> *pierwsza;
    std::cout << "Podaj druga liczbe: ";
    std::cin >> *druga;
}

int main() {
    int wybor = -1;
    int a = 0, b = 0;
    float wynik = 0;

    std::cout << ">>> Kalkulator v2 <<<\n";

    do {
        wyswietlMenu();
        std::cin >> wybor;

        switch (wybor) {
            case 0:
                std::cout << "Zamykanie programu...\n";
                break;

            case 1:
                pobierzLiczby(&a, &b);
                wynik = a + b;
                std::cout << a << " + " << b << " = " << wynik << "\n";
                break;

            case 2:
                pobierzLiczby(&a, &b);
                wynik = a - b;
                std::cout << a << " - " << b << " = " << wynik << "\n";
                break;

            case 3:
                pobierzLiczby(&a, &b);
                wynik = a * b;
                std::cout << a << " * " << b << " = " << wynik << "\n";
                break;

            case 4:
                pobierzLiczby(&a, &b);
                if (b == 0) {
                    std::cout << "Blad: Nie mozna dzielic przez zero!\n";
                } else {
                    wynik = static_cast<float>(a) / b;
                    std::cout << a << " / " << b << " = " << wynik << "\n";
                }
                break;

            default:
                std::cout << "Nieprawidłowy wybor. Sprobuj ponownie.\n";
        }

    } while (wybor != 0);

    return 0;
}
