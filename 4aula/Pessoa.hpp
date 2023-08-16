/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 10/08/2023 21h50
*/
#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <cstdint>
#include <string>

class Pessoa {
   public:
    Pessoa();  // padrao ou default, SEMPRE deve ter um na classe
    Pessoa(std::string novoNome);
    Pessoa(std::string novoNome, uint8_t novaIdade, uint64_t novoCpf);

    uint64_t getCpf();
    void setCpf(uint64_t novoCpf);

    std::string getNome();
    void setNome(std::string novoNome);
    void setNome();

    unsigned short getIdade();
    void setIdade(unsigned short novaIdade);

    void show();

   private:
    bool validarCPF(uint64_t cpfTeste);

    std::string nome;
    uint8_t idade;
    uint64_t cpf;
};

#endif
