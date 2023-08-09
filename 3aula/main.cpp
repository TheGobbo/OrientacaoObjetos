/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 07/08/2023 21h50
*/
#include <iostream>

#include "Pessoa.hpp"

int main() {
    Pessoa p1, p2;

    // p1.cadastrar(&p1);
    // p1.show();

    // p1.cadastrar("Eduardo", 21, 11111111111);
    // p1.show();
    // p1 = p2.cadastrar("João", 18, 11144477735);
    // p1.show();
    // p2.show();
    unsigned short idade = 119;
    p1.setCpf(11111111110);
    p1.setNome("Joao");
    p1.setIdade(idade);
    p1.show();

    // p2.cadastrar();
    // p2.show();

    return 0;
}