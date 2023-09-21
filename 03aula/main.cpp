/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 10/08/2023 21h50
*/
#include <iostream>

#include "Pessoa.hpp"
#include "Retangulo.hpp"

int main() {
    Pessoa p1, p2;

    // p1.cadastrar(&p1);
    // p1.show();

    // p1.cadastrar("Eduardo", 21, 11111111111);
    // p1.show();
    // p1 = p2.cadastrar("João", 18, 11144477735);
    // p1.show();
    // p2.show();
    // unsigned short idade{119};

    p1.setCpf(11111111110);
    p1.setNome(
        "Joao de Souza Coelho de Abraao 1 2 3 4 5 6 7 8 9 10 Joao de Souza "
        "Coelho de Abraao 1 2 3 4 5 6 7 8 9 10 Joao de Souza Coelho de Abraao "
        "1 2 3 4 5 6 7 8 9 10");
    p1.setIdade((unsigned short)119);
    p1.show();
    p1.setNome();
    p1.show();

    // p2.cadastrar();
    // p2.show();

    // ########################################

    Retangulo r1, r2;

    r1.setX(2);
    r1.setY(3);
    r1.show();

    r2.cadastrar(10, 10);
    r2.show();

    return 0;
}