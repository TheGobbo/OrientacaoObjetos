/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 07/08/2023 21h50
*/
#include "Retangulo.hpp"

void setX(double novoX) { x = novoX; }
void setY(double novoY) { y = novoY; }
double getX() { return x; }
double getY() { return y; }

bool Retangulo::isQuadrado() { return x == y; }

double Retangulo::getArea() { return x * y; }

void Retangulo::novoRetangulo() {
    std::cout << "Digite X : ";
    std::cin >> x;
    std::cout << "Digite Y : ";
    std::cin >> y;
    return;
}

void Retangulo::novoRetangulo(double novoX, double novoY) {
    x = novoX;
    y = novoY;
    return;
}

void Retangulo::show() {
    std::cout << "Dados do retangulo: (X, Y) -> (" << x << ", " << y << ")\n";
}