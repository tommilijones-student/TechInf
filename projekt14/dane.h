#pragma once
#include <string>

class Dane {
private:
    static int zlicz;
    std::string nazwa;
    double wspX;
    double wspY;

public:
    static int ileObiektow();
    Dane();
    Dane(const std::string& etykieta, double a = 0, double b = 0);
    ~Dane();
    void ustawNazwe(const std::string& etykieta);
    void ustawXY(double a, double b);
    double dajX();
    double dajY();
    void wypisz() const;
    double odleglosc(const Dane& d) const;
    const Dane& dalszy(const Dane& d) const;
};
