/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 11/08/2023 21h50
*/
#include <iostream>

#include "Pessoa.hpp"
#include "Retangulo.hpp"

void Pessoa::show() {
    std::cout << "+-------------------------------+\n";
    std::cout << "| Nome : " << getNome() << "\n";
    std::cout << "| Idade: " << getIdade() << "\n";
    std::cout << "| CPF  : " << getCpf() << "\n";
    std::cout << "+-------------------------------+\n";
}

void Retangulo::show() {
    std::cout << "+-------------------------------+\n";
    std::cout << "| Dados do retangulo (X: " << x << ", Y: " << y << ")\n";
    std::cout << "| " << (isQuadrado() ? "Eh quadrado\n" : "Não eh quadrado\n");
    std::cout << "| Perimetro : " << getPerimetro() << "\n";
    std::cout << "| Area : " << getArea() << "\n";
    std::cout << "+-------------------------------+\n";
}

int main() {
    Pessoa p1{"Eduardo Gobbo W V G", 10, 11144477735};
    p1.show();
    Pessoa p2{"Joao P C", 15, 0};
    p2.show();
    Pessoa p3{"Maria B"};
    p3.show();

    // ########################################

    Retangulo r1{1, 11};
    r1.show();

    Retangulo r2, r3;

    r2.setLargura(2);
    r2.setAltura(2);
    r2.show();

    r3.setLargura();  // default arg = 123
    r3.show();

    return 0;
}