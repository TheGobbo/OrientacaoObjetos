#include "Circulo.hpp"

#include <assert.h>

#include <numbers>

double Circulo::pi2{3.14159265359};

Circulo::Circulo(double raio) : raio{raio} { assert(raio > 0); }

void Circulo::setRaio(double raio) {
    if (raio <= 0) return;

    this->raio = raio;
}
double Circulo::getRaio() const { return this->raio; }

double Circulo::calculaArea() const {
    double area = Circulo::pi2 * this->raio * this->raio;
    return area;
}