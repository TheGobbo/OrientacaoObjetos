#include "SalaAula.hpp"

#include <iostream>

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
    : nome{nome}, capacidade{capacidade} {}

std::string SalaAula::getNome() { return this->nome; }

void SalaAula::setNome(std::string nome) { this->nome = nome; }

unsigned int SalaAula::getCapacidade() { return this->capacidade; }

void SalaAula::setCapcidade(unsigned int capacidade) {
    this->capacidade = capacidade;
}

std::list<Disciplina*>& SalaAula::getDisciplinas() {
    return this->disciplinasMinistradas;
}

void SalaAula::adicionaDisciplina(Disciplina* disciplina) {
    disciplina->sala = this;
}

void SalaAula::imprimirDisciplinas() {
    std::cout << "Sala: " << this->nome << std::endl;
    std::cout << "Capacidade: " << this->capacidade << std::endl;
    std::cout << "Disciplinas misnistradas:\n";

    std::list<Disciplina*>::iterator it;
    for (it = this->disciplinasMinistradas.begin();
         it != this->disciplinasMinistradas.end(); ++it) {
        std::cout << " - " << (*it)->getNome() << '\n';
    }
}