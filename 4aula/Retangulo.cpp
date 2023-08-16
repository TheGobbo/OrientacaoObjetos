/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 10/08/2023 21h50
*/
#include "Retangulo.hpp"

Retangulo::Retangulo() : x{0}, y{0} {}

Retangulo::Retangulo(double largura, double altura) : x{largura}, y{altura} {}

double Retangulo::getLargura() { return x; }

void Retangulo::setLargura(double largura = 10) { x = largura; }

double Retangulo::getAltura() { return y; }

void Retangulo::setAltura(double altura = 10) { y = altura; }

bool Retangulo::isQuadrado() { return x == y; }

double Retangulo::getArea() { return x * y; }

double Retangulo::getPerimetro() { return 2 * x + 2 * y; };
