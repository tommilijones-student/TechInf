#include <iostream>

void naDuzeLitery(char *tekst)
{
    while (*tekst)
    {
        if (*tekst >= 'a' && *tekst <= 'z')
        {
            *tekst = *tekst - 32;
        }
        tekst++;
    }
}

int main()
{
    char dane[256];

    std::cout << "Wpisz tekst: ";
    std::cin.getline(dane, 256);

    naDuzeLitery(dane);

    std::cout << "Zamieniony tekst: " << dane << std::endl;

    return 0;
}
