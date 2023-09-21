#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <cstdint>
#include <string>

class Pessoa {
   public:
    Pessoa(std::string nome);
    Pessoa(std::string nome, uint64_t cpf, uint8_t idade);

    uint64_t getCpf();
    void setCpf(uint64_t cpf);

    std::string getNome();
    void setNome(std::string nome);

    unsigned short getIdade();
    void setIdade(unsigned short idade);

    void show();

   private:
    bool validarCPF(uint64_t cpf);

    std::string nome;
    uint64_t cpf = 0;
    uint8_t idade = 0;
};
#endif