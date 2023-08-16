/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
<<<<<<< HEAD
ultima modificacao 10/08/2023 21h50
=======
ultima modificacao 13/08/2023 21h50
>>>>>>> d151d8ab5e49688ade58162c21fae59e3789b686
*/
#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <cstdint>
#include <string>

class Pessoa {
   public:
<<<<<<< HEAD
    Pessoa();  // padrao ou default, SEMPRE deve ter um na classe
=======
    Pessoa();  // padrao ou default, SEMPRE vai ter um na classe
>>>>>>> d151d8ab5e49688ade58162c21fae59e3789b686
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
<<<<<<< HEAD
    uint8_t idade;
    uint64_t cpf;
=======
    uint8_t idade = 0;
    uint64_t cpf = 0;
>>>>>>> d151d8ab5e49688ade58162c21fae59e3789b686
};

#endif
