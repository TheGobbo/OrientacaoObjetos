#ifndef EMENTA_HPP
#define EMENTA_HPP

#include <list>
#include <memory>
#include <string>

#include "Livro.hpp"

namespace ufpr {
class Ementa {
   public:
    Ementa();
    Ementa(const std::string descricao);
    Ementa(const Ementa& ementa);  // construtor de cópia
    Ementa(Ementa&& ementa);       // move constructor
    virtual ~Ementa();

    void setDescricao(const std::string& descricao);
    const std::string& getDescricao() const;

    void addLivro(std::shared_ptr<const Livro> livro);
    const std::unique_ptr<std::list<std::shared_ptr<const Livro>>> getLivros();

    Ementa& operator=(Ementa&& ementa);
    const Ementa& operator=(const Ementa& ementa);

   private:
    std::string descricao;
    std::unique_ptr<std::list<std::shared_ptr<const Livro>>> livros;
};
}  // namespace ufpr
#endif