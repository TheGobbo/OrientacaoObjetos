/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 07/08/2023 21h50
*/
#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <cstdint>
#include <cstring>
#include <iostream>

class Pessoa {
   public:
    bool validarCPF(uint64_t cpfTeste);  // nao escreve a funcao aki
    Pessoa cadastrar(const char* nome, uint8_t idade, uint64_t cpf);
    Pessoa cadastrar(Pessoa* p);

    void show();

    char nome[100];
    uint8_t idade;
    uint64_t cpf;
};

#endif
