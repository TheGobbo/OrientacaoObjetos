#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <cstdint>
#include <string>

class Pessoa {
   public:
    Pessoa(std::string nomePessoa);
    Pessoa(std::string nomePessoa, uint64_t cpfPessoa, uint8_t idade);

    uint64_t getCpf();
    void setCpf(uint64_t novoCpf);

    std::string getNome();
    void setNome(std::string novoNome);

    unsigned short getIdade();
    void setIdade(unsigned short novaIdade);

    void show();

   private:
    bool validarCPF(uint64_t cpfTeste);

    std::string nome;
    uint64_t cpf = 0;
    uint8_t idade = 0;
};
#endif