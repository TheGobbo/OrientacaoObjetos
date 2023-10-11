#include "Retangulo.hpp"

#include <assert.h>

Retangulo::Retangulo(double altura, double largura)
    : altura{altura}, largura{largura} {
    assert(largura > 0);
    assert(altura > 0);
}

void Retangulo::setAltura(double altura) {
    if (altura <= 0) return;

    this->altura = altura;
}
double Retangulo::getAltura() const { return this->altura; }

void Retangulo::setLargura(double largura) {
    if (largura <= 0) return;

    this->largura = largura;
}
double Retangulo::getLargura() const { return this->largura; }

double Retangulo::calculaArea() const {
    double area = this->largura * this->altura;

    return area;
}