#include <iostream>
#include "Dane.h"
#include <cmath>

int Dane::zlicz = 0;

Dane::Dane() {
    nazwa = "brak";
    wspX = 0;
    wspY = 0;
    zlicz++;
}

Dane::Dane(const std::string& etykieta, double a, double b) {
    nazwa = etykieta;
    wspX = a;
    wspY = b;
    zlicz++;
}

Dane::~Dane() {
    zlicz--;
}

void Dane::ustawNazwe(const std::string& etykieta) {
    nazwa = etykieta;
}

void Dane::ustawXY(double a, double b) {
    wspX = a;
    wspY = b;
}

double Dane::dajX() {
    return wspX;
}

double Dane::dajY() {
    return wspY;
}

void Dane::wypisz() const {
    std::cout << "Obiekt: " << nazwa << "(" << wspX << ", " << wspY << ")" << std::endl;
}

double Dane::odleglosc(const Dane& d) const {
    return sqrt((d.wspX - wspX) * (d.wspX - wspX) + (d.wspY - wspY) * (d.wspY - wspY));
}

const Dane& Dane::dalszy(const Dane& d) const {
    double dyst1 = sqrt(wspX * wspX + wspY * wspY);
    double dyst2 = sqrt(d.wspX * d.wspX + d.wspY * d.wspY);
    if (dyst1 > dyst2) return *this;
    return d;
}

int Dane::ileObiektow() {
    return zlicz;
}
