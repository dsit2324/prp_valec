//
// Created by dsofc on 03.02.2026.
//

#ifndef VALEC_VALEC_H
#define VALEC_VALEC_H

#include <ostream>
#include <math.h>


class Valec {
public:
    Valec();

    Valec(float polomer, float vyska);

    Valec(Valec const &kopirka);

    ~Valec();

    float getPolomer() const;
    float getVyska() const;
    bool setPolomer(float polomer);
    bool setVyska(float vyska);
    bool setValec(float polomer, float vyska);
    float objemValce() const; // funkce jsou bez parametru, protoze pracuji s promennymi tridy
    float povrchValce() const;
    float obsahPlaste() const;
    float obsahPodstavy() const;
    float vyskaVody(float objemVody); // ziskani vysky vody zadane uzivatelem
    bool vlezeSe(float objemVody) const; // jestli se voda vleze do valce
    bool jePlatnyObjem(float polomer, float vyska, float objemVody) const; // kdyby uzivatel zadal hodnotu mensi jak 0 nebo pismenka
private:
    float polomer;
    float vyska;
};

std::ostream& operator<<(std::ostream& os, const Valec& v);

#endif //VALEC_VALEC_H
