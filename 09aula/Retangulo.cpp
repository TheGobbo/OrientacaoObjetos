/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 11/08/2023 21h50
*/
#include "Retangulo.hpp"

#include <iostream>

unsigned int Retangulo::proxId{0};

Retangulo::Retangulo() : y{10}, id{Retangulo::proxId} { Retangulo::proxId++; }

Retangulo::Retangulo(double largura, double altura) : x{largura}, y{altura}, id{Retangulo::proxId} {
    Retangulo::proxId++;
}

double Retangulo::getLargura() { return x; }

void Retangulo::setLargura(double largura) { x = largura > 0 ? largura : 1; }

double Retangulo::getAltura() { return y; }

void Retangulo::setAltura(double altura) { y = altura > 0 ? altura : 1; }

bool Retangulo::isQuadrado() { return x == y; }

double Retangulo::getArea() { return x * y; }

double Retangulo::getPerimetro() { return 2 * x + 2 * y; };

int Retangulo::getRetangulosCriados() { return Retangulo::proxId - 1; }

void Retangulo::show() {
    std::cout << "(" << this->id << ") : altura,largura = (" << this->y << ", " << this->x << ")\n";
}
