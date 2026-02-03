//
// Created by dsofc on 03.02.2026.
//

#include "Valec.h"

Valec::Valec() : polomer(1), vyska(1) {
}

Valec::Valec(float polomer, float vyska) {
    if (this->polomer < 0 || this->vyska < 0) {
        this->polomer = 1;
        this->vyska = 1;
    } else {
        this->polomer = polomer;
        this->vyska = vyska;
    }
}

Valec::Valec(Valec const &kopirka) : polomer(kopirka.polomer), vyska(kopirka.vyska) {
}

Valec::~Valec() {
}

float Valec::getPolomer() const {
    return this->polomer;
}

float Valec::getVyska() const {
    return this->vyska;
}

bool Valec::setPolomer(float polomer) {
    if (this->polomer < 0) {
        return false;
    } else {
        this->polomer = polomer;
        return true;
    }
}

bool Valec::setVyska(float vyska) {
    if (this->vyska < 0) {
        return false;
    } else {
        this->vyska = vyska;
        return true;
    }
}

bool Valec::setValec(float polomer, float vyska) {
    if (this->polomer < 0 || this->vyska < 0) {
        return false;
    } else {
        this->polomer = polomer;
        this->vyska = vyska;
        return true;
    }
}

float Valec::objemValce() const {
    return M_PI * polomer * polomer * vyska;
}

float Valec::povrchValce() const {
    return M_PI * polomer * polomer * 2 + 2 * M_PI * polomer * vyska;
}

float Valec::obsahPlaste() const {
    return M_PI * polomer * vyska * 2;
}

float Valec::obsahPodstavy() const {
    return M_PI * polomer * polomer;
}

float Valec::vyskaVody(float objemVody) {
    return objemVody / (M_PI * polomer * polomer);
}

bool Valec::vlezeSe(float objemVody) const {
    if (objemVody > M_PI * polomer * polomer * vyska) {
        return false;
    } else {
        return true;
    }
}

bool Valec::jePlatnyObjem(float polomer, float vyska, float objemVody) const {
    if (this->polomer < 0 || this->vyska < 0) {
        return false;
    } else {
        return true;
    }
}

std::ostream & operator<<(std::ostream &os, const Valec &v) {
    os << v.getPolomer() << ", " << v.getVyska();
    return os;
}
