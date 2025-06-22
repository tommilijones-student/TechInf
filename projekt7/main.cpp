#include <iostream>
#include <cstdio>

void zamienLitery(char *tekst)
{
    while (*tekst)
    {
        if ('a' <= *tekst && *tekst <= 'z')
        {
            *tekst = *tekst - ('a' - 'A'); // mała -> duża
        }
        else if ('A' <= *tekst && *tekst <= 'Z')
        {
            *tekst = *tekst + ('a' - 'A'); // duża -> mała
        }
        tekst++;
    }
}

int main()
{
    char tekst[256];

    printf("Podaj tekst: ");
    fgets(tekst, sizeof(tekst), stdin);

    zamienLitery(tekst);

    printf("Po zamianie liter: %s\n", tekst);

    return 0;
}
