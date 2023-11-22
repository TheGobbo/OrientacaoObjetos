#include "Pessoa.hpp"

#include <iostream>
#include <stdexcept>

using namespace ufpr;

Pessoa::Pessoa(const std::string& nome) : nome{nome} {}

Pessoa::Pessoa(const std::string& nome, const unsigned short int idade)
    : Pessoa{nome} {
    this->setIdade(idade);
}

std::string Pessoa::getNome() const { return this->nome; }

void Pessoa::setNome(const std::string& nome) { this->nome = nome; }

unsigned short int Pessoa::getIdade() const {
    return static_cast<unsigned short int>(idade);
}

void Pessoa::setIdade(const unsigned short int novaIdade) {
    if (novaIdade > 120) throw std::invalid_argument{"Idade Invalida."};
    idade = static_cast<uint8_t>(novaIdade);
}