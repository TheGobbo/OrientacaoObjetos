#include "SalaAula.hpp"

#include <iostream>

#define flags(STR) std::cerr << "\033[1;31m" << STR << "\033[0m\n"
#define flag std::cerr << "\033[1;31mFLAG\033[0m\n"

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
    : nome{nome}, capacidade{capacidade} {}

std::string SalaAula::getNome() { return this->nome; }

void SalaAula::setNome(std::string nome) { this->nome = nome; }

unsigned int SalaAula::getCapacidade() { return this->capacidade; }

void SalaAula::setCapcidade(unsigned int capacidade) { this->capacidade = capacidade; }

/*
add(sala)
        if(this->sala == sala) return
        if(this->sala != nullptr)
                this->sala->_removerDisciplina(this)
        this->sala = sala
        if(sala != nullptr)
                this->sala->_adicionarDisciplina(this)


add(disc)
        se essa sala tem essa disciplina, nao faz nada
        se essa disciplina tem outra sala diferente,
                remove disciplina da outra sala

        adiciona disciplina a esta sala
        atualiza sala da disciplina
*/

void SalaAula::adicionaDisciplina(Disciplina* disciplina) {
    if (disciplina == nullptr) return;
    if (disciplina->getSalaAula() == this) return;

    _adicionaDisciplina(disciplina);
    disciplina->_setSalaAula(this);
}

void SalaAula::removeDisciplina(Disciplina* disciplina) {
    _removeDisciplina(disciplina);
    disciplina->_setSalaAula(nullptr);
}

void SalaAula::_adicionaDisciplina(Disciplina* disciplina) {
    if (disciplina == nullptr) {
        return;
    }

    _removeDisciplina(disciplina);
    this->disciplinasMinistradas.push_back(disciplina);
}

void SalaAula::_removeDisciplina(Disciplina* disciplina) {
    if (disciplina == nullptr) return;

    std::list<Disciplina*>::iterator it;
    for (it = this->disciplinasMinistradas.begin(); it != this->disciplinasMinistradas.end();) {
        if (disciplina == (*it)) {
            it = this->disciplinasMinistradas.erase(it);
        } else {
            ++it;
        }
    }
}

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
