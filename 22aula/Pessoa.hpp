#ifndef PESSOA_H
#define PESSOA_H

#include <cstdint>
#include <string>

namespace ufpr {
class Pessoa {
   public:
    Pessoa();
    Pessoa(const std::string& nomePessoa);
    Pessoa(const std::string& nomePessoa, unsigned short idade);

    virtual ~Pessoa() = default;

    std::string getNome() const;
    void setNome(const std::string& novoNome);

    unsigned short int getIdade() const;
    void setIdade(const unsigned short novaIdade);

   private:
    std::string nome;
    uint8_t idade;
};
}  // namespace ufpr
#endif