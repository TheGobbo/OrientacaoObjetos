#ifndef EMENTA_HPP
#define EMENTA_HPP

#include <list>
#include <string>

#include "Livro.hpp"

namespace ufpr {
class Ementa {
   public:
    Ementa();
    Ementa(const std::string descricao);
    Ementa(const Ementa& ementa);  // COPY CONSTRUCTOR
    Ementa(Ementa&& ementa);       //  MOVE CONSTRUCTOR
    virtual ~Ementa();

    void setDescricao(const std::string& descricao);
    const std::string& getDescricao() const;

    void addLivro(const Livro& livro);
    const std::list<Livro>* getLivros() const;

    Ementa& operator=(Ementa&& other);
    const Ementa& operator=(const Ementa& other);

   private:
    std::string descricao;
    std::list<Livro>* livros;
};
}  // namespace ufpr
#endif