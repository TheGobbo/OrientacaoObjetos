/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 10/08/2023 21h50
*/
#include "Retangulo.hpp"

double Retangulo::getX() { return x; }
void Retangulo::setX(double novoX) { x = novoX; }

double Retangulo::getY() { return y; }
void Retangulo::setY(double novoY) { y = novoY; }

bool Retangulo::isQuadrado() { return x == y; }

double Retangulo::getArea() { return x * y; }

double Retangulo::getPerimetro() { return 2 * x + 2 * y; };

void Retangulo::cadastrar() {
    std::cout << "Digite X : ";
    std::cin >> x;
    std::cout << "Digite Y : ";
    std::cin >> y;
    return;
}

void Retangulo::cadastrar(double novoX, double novoY) {
    x = novoX;
    y = novoY;
    return;
}

void Retangulo::show() {
    std::cout << "+-------------------------------+\n";
    std::cout << "|Dados do retangulo (X: " << x << ", Y: " << y << ")\n";
    std::cout << '|' << (isQuadrado() ? "Eh quadrado\t" : "Não eh quadrado")
              << "\t\t|\n";
    std::cout << "|Perimetro : " << getPerimetro() << "\t\t\t|\n";
    std::cout << "|Area : " << getArea() << "\t\t\t|\n";
    std::cout << "+-------------------------------+\n";
}