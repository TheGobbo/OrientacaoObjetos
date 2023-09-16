#include "SalaAula.hpp"

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
    : nome{nome}, capacidade{capacidade} {}

SalaAula::~SalaAula() {
    std::list<Disciplina*>::iterator it{disciplinasMinistradas.begin()};
    for (; it != disciplinasMinistradas.end(); it++) (*it)->anularSalaAula();
}

std::string SalaAula::getNome() const { return this->nome; }

void SalaAula::setNome(const std::string nome) { this->nome = nome; }

unsigned int SalaAula::getCapacidade() const { return this->capacidade; }

void SalaAula::setCapcidade(const unsigned int capacidade) { this->capacidade = capacidade; }

const std::list<Disciplina*>& SalaAula::getDisciplinas() const { return disciplinasMinistradas; }