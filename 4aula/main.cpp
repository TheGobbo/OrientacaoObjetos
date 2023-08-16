/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
<<<<<<< HEAD
ultima modificacao 10/08/2023 21h50
=======
ultima modificacao 11/08/2023 21h50
>>>>>>> d151d8ab5e49688ade58162c21fae59e3789b686
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
<<<<<<< HEAD
    std::cout << "|Dados do retangulo (X: " << x << ", Y: " << y << ")\n";
    std::cout << '|' << (isQuadrado() ? "Eh quadrado\t" : "Não eh quadrado")
              << "\t\t|\n";
    std::cout << "|Perimetro : " << getPerimetro() << "\t\t\t|\n";
    std::cout << "|Area : " << getArea() << "\t\t\t|\n";
=======
    std::cout << "| Dados do retangulo (X: " << x << ", Y: " << y << ")\n";
    std::cout << "| " << (isQuadrado() ? "Eh quadrado\n" : "Não eh quadrado\n");
    std::cout << "| Perimetro : " << getPerimetro() << "\n";
    std::cout << "| Area : " << getArea() << "\n";
>>>>>>> d151d8ab5e49688ade58162c21fae59e3789b686
    std::cout << "+-------------------------------+\n";
}

int main() {
    Pessoa p1{"Eduardo Gobbo W V G", 10, 11144477735};
<<<<<<< HEAD

    p1.show();

    // ########################################

    Retangulo r1{10, 11};
    Retangulo r2, r3;

    r2.setLargura(10);
    r2.setAltura(3);

    r3.setAltura();

    r1.show();
    r2.show();
=======
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
>>>>>>> d151d8ab5e49688ade58162c21fae59e3789b686
    r3.show();

    return 0;
}