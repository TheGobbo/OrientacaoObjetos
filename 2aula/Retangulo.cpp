/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 07/08/2023 21h50
*/
#include "Retangulo.hpp"

bool Retangulo::isQuadrado() { return this->x == this->y; }

double Retangulo::calcArea() { return this->x * this->y; }

Retangulo Retangulo::novoRetangulo(Retangulo *novoRetangulo) {
    std::cout << "Digite X : ";
    std::cin >> novoRetangulo->x;
    std::cout << "Digite Y : ";
    std::cin >> novoRetangulo->y;
    return *novoRetangulo;
}

Retangulo Retangulo::novoRetangulo(double x, double y) {
    this->x = x;
    this->y = y;
    return *this;
}

void Retangulo::show() {
    std::cout << "Dados do retangulo: (X, Y) -> (" << x << ", " << y << ")\n";
}