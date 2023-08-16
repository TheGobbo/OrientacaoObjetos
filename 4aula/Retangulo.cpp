/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
<<<<<<< HEAD
ultima modificacao 10/08/2023 21h50
*/
#include "Retangulo.hpp"

Retangulo::Retangulo() : x{0}, y{0} {}
=======
ultima modificacao 11/08/2023 21h50
*/
#include "Retangulo.hpp"

Retangulo::Retangulo() : y{10} {}
>>>>>>> d151d8ab5e49688ade58162c21fae59e3789b686

Retangulo::Retangulo(double largura, double altura) : x{largura}, y{altura} {}

double Retangulo::getLargura() { return x; }

<<<<<<< HEAD
void Retangulo::setLargura(double largura = 10) { x = largura; }

double Retangulo::getAltura() { return y; }

void Retangulo::setAltura(double altura = 10) { y = altura; }
=======
void Retangulo::setLargura(double largura) { x = largura > 0 ? largura : 1; }

double Retangulo::getAltura() { return y; }

void Retangulo::setAltura(double altura) { y = altura > 0 ? altura : 1; }
>>>>>>> d151d8ab5e49688ade58162c21fae59e3789b686

bool Retangulo::isQuadrado() { return x == y; }

double Retangulo::getArea() { return x * y; }

double Retangulo::getPerimetro() { return 2 * x + 2 * y; };
