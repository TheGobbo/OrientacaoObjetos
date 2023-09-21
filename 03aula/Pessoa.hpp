/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 10/08/2023 21h50
*/
#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <cstdint>
#include <iostream>
#include <string>

class Pessoa {
   public:
    uint64_t getCpf();
    void setCpf(uint64_t novoCpf);

    std::string getNome();
    void setNome(std::string novoNome);
    void setNome();

    unsigned short getIdade();
    void setIdade(unsigned short novaIdade);

    Pessoa cadastrar(const char* nome, uint8_t idade, uint64_t cpf);
    Pessoa cadastrar();
    void show();

   private:
    bool validarCPF(uint64_t cpfTeste);

    std::string nome;
    uint8_t idade;
    uint64_t cpf;
};

#endif
