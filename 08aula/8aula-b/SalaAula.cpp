#include "SalaAula.hpp"

#include <iostream>

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
    : nome{nome}, capacidade{capacidade} {}

std::string SalaAula::getNome() { return this->nome; }

void SalaAula::setNome(std::string nome) { this->nome = nome; }

unsigned int SalaAula::getCapacidade() { return this->capacidade; }

void SalaAula::setCapcidade(unsigned int capacidade) { this->capacidade = capacidade; }

void SalaAula::adicionaDisciplina(Disciplina* disciplina) {
    if (disciplina == nullptr || disciplina->sala == this) return;

    if (disciplina->sala != nullptr) {
        disciplina->sala->removerDisciplina(disciplina);
    }
    this->disciplinasMinistradas.push_back(disciplina);
    disciplina->sala = this;
}

void SalaAula::removerDisciplina(Disciplina* disciplina) {
    if (disciplina == nullptr || this->disciplinasMinistradas.empty()) return;

    this->disciplinasMinistradas.remove(disciplina);
    disciplina->sala = nullptr;
}

std::list<Disciplina*>& SalaAula::getDisciplinas() { return this->disciplinasMinistradas; }

void SalaAula::show() {
    std::list<Disciplina*>::iterator it;

    std::cout << "Nome Sala: " << this->getNome() << '\n';
    std::cout << "Capacidade: " << this->getCapacidade() << '\n';
    std::cout << "Disciplinas ministradas: " << this->disciplinasMinistradas.size() << '\n';
    for (it = this->disciplinasMinistradas.begin(); it != this->disciplinasMinistradas.end();
         ++it) {
        std::cout << " - " << (*it)->getNome() << '\n';
    }
    std::cout << '\n';
}
