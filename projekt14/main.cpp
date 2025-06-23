#include <iostream>
#include "Dane.h"
using namespace std;

int main() {
    Dane obiekty[10] = {
        Dane("A1", 0, 0),
        Dane("A2", 10, 20),
        Dane("A3", 30, 40)
    };
    cout << "Istnieje " << Dane::ileObiektow() << " punktow." << endl;
    for (int i = 0; i < 10; i++) {
        obiekty[i].wypisz();
    }
    {
        Dane a, b, c;
        cout << endl;
        cout << "Teraz istnieje " << Dane::ileObiektow() << " punktow." << endl;
    }
    cout << "A teraz istnieje " << Dane::ileObiektow() << " punktow." << endl;
}
