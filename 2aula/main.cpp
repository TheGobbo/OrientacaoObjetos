/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 07/08/2023 21h50
*/
#include <iostream>

#include "Pessoa.hpp"
#include "Retangulo.hpp"

int main() {
    Pessoa p1, p2;

    p1.cadastrar(&p1);
    p1.show();

    p1.cadastrar("Eduardo", 21, 11111111111);
    p1.show();
    p1 = p2.cadastrar("João", 18, 11144477735);
    p1.show();
    p2.show();

    // return 0;
    // ##############################

    Retangulo r1, r2;
    r2.novoRetangulo(4.0, 4.0);
    std::cout << "-- Info r2\n";
    r2.show();
    std::cout << "Area r2 = " << r2.calcArea() << '\n'
              << (r2.isQuadrado() ? "Eh quadrado" : "Nn quadrado") << '\n';

    std::cout << "---- Input r2\n";
    r1.novoRetangulo(&r2);
    r2.show();
    std::cout << "Area r1 = " << r1.calcArea() << '\n';
    std::cout << "Area r2 = " << r2.calcArea() << '\n'
              << (r2.isQuadrado() ? "r2 Eh quadrado" : "r2 Nn quadrado")
              << '\n';

    std::cout << "---- Input r1\n";
    r2.novoRetangulo(&r1);
    r2.show();
    std::cout << "Area r1 = " << r1.calcArea() << '\n';
    std::cout << "Area r2 = " << r2.calcArea() << '\n'
              << (r2.isQuadrado() ? "r1 Eh quadrado" : "r1 Nn quadrado")
              << '\n';

    return 0;
}