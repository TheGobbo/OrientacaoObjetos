#include "Ementa.hpp"

#include <iostream>

namespace ufpr {

Ementa::Ementa() : livros{new std::list<Livro>} {
    std::cerr << "Criei uma Nova Ementa()\n";
}

Ementa::Ementa(const std::string descricao)
    : descricao{descricao}, livros{new std::list<Livro>} {
    std::cerr << "Criei uma Nova Ementa()\n";
}

Ementa::Ementa(const Ementa& other)
    : descricao{other.descricao}, livros{new std::list<Livro>{*other.livros}} {
    std::cerr << "Copy Constructor (Deep)\n";
}

Ementa::Ementa(Ementa&& other)
    : descricao{other.descricao}, livros{other.livros} {
    std::cerr << "Move Constructor (Robei)\n";
    other.livros = nullptr;
}

Ementa& Ementa::operator=(Ementa&& other) {
    std::cerr << "Move Assignment (Robei)\n";
    if (this == &other) return *this;
    this->descricao = other.descricao;
    if (this->livros != nullptr) delete this->livros;
    this->livros = other.livros;
    other.livros = nullptr;

    return *this;
}

const Ementa& Ementa::operator=(const Ementa& other) {
    std::cerr << "Move Assignment (Deep)\n";
    if (this == &other) return *this;
    this->descricao = other.descricao;
    if (this->livros != nullptr) delete this->livros;
    this->livros = new std::list{*other.livros};

    return *this;
}

Ementa::~Ementa() {
    if (this->livros != nullptr) delete this->livros;
}

void Ementa::setDescricao(const std::string& descricao) {
    this->descricao = descricao;
}

const std::string& Ementa::getDescricao() const { return this->descricao; }

void Ementa::addLivro(const Livro& livro) { this->livros->push_back(livro); }

const std::list<Livro>* Ementa::getLivros() const { return this->livros; }
}  // namespace ufpr