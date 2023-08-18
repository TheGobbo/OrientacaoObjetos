/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 11/08/2023 21h50
*/
#include "Retangulo.hpp"

Retangulo::Retangulo() : y{10} {}

Retangulo::Retangulo(double largura, double altura) : x{largura}, y{altura} {}

double Retangulo::getLargura() { return x; }

void Retangulo::setLargura(double largura) { x = largura > 0 ? largura : 1; }

double Retangulo::getAltura() { return y; }

void Retangulo::setAltura(double altura) { y = altura > 0 ? altura : 1; }

bool Retangulo::isQuadrado() { return x == y; }

double Retangulo::getArea() { return x * y; }

double Retangulo::getPerimetro() { return 2 * x + 2 * y; };
