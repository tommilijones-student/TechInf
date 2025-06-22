#include <cstdio>

void zmienWielkoscLiter(char *napis)
{
    while (*napis)
    {
        if (*napis >= 'a' && *napis <= 'z')
        {
            *napis = *napis - 32;
        }
        else if (*napis >= 'A' && *napis <= 'Z')
        {
            *napis = *napis + 32;
        }
        napis++;
    }
}

int main()
{
    char bufor[256];

    printf("Wprowadz zdanie: ");
    fgets(bufor, sizeof(bufor), stdin);

    zmienWielkoscLiter(bufor);

    printf("Po konwersji: %s\n", bufor);

    return 0;
}
