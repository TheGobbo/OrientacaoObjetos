#ifndef EMENTA_HPP
#define EMENTA_HPP

#include <list>
#include <string>

#include "Livro.hpp"

namespace ufpr {
class Ementa {
   public:
    Ementa();
    explicit Ementa(const std::string descricao);
    explicit Ementa(const Ementa& ementa);  // construtor de cópia
    Ementa(Ementa&& ementa);                // move constructor
    virtual ~Ementa();

    void setDescricao(const std::string& descricao);
    const std::string& getDescricao() const;

    void addLivro(const Livro& livro);
    const std::list<Livro>* getLivros() const;

    Ementa& operator=(Ementa&& ementa);
    const Ementa& operator=(const Ementa& ementa);

   private:
    std::string descricao;
    std::list<Livro>* livros;
};
}  // namespace ufpr
#endif