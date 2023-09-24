#include "Aluno.hpp"

// friend void Disciplina::removerAluno(Aluno* const aluno);
// friend void Disciplina::adicionarAluno(Aluno* const aluno);

#include <iostream>

#include "Disciplina.hpp"

// todo = calcular automaticamente
const int8_t Aluno::getIra() const { return this->ira; }

const int32_t Aluno::getGrr() const { return this->grr; }

const int8_t Aluno::getSemestre() const { return this->semestre; }

const std::list<Disciplina*>& Aluno::getDisciplinas() const { return this->disciplinas; }

void Aluno::setIra(int8_t ira) { this->ira = ira; }

void Aluno::setSemestre(int8_t semestre) { this->semestre = semestre; }

void Aluno::adicionaDisciplina(Disciplina* disciplina) {
    if (disciplina == nullptr || matriculadoEm(disciplina)) return;

    this->disciplinas.push_back(disciplina);
    std::cout << "Adicionou disciplina a aluno\n";
    disciplina->adicionarAluno(this);
}

void Aluno::removerDisciplina(Disciplina* disciplina) {
    if (disciplina == nullptr || !matriculadoEm(disciplina)) return;

    this->disciplinas.remove(disciplina);
    disciplina->removerAluno(this);
}

bool Aluno::matriculadoEm(Disciplina* const disciplina) const {
    if (disciplina == nullptr) return false;

    std::list<Disciplina*>::const_iterator it = this->disciplinas.begin();
    for (; it != this->disciplinas.end(); ++it) {
        if (disciplina == (*it)) {
            return true;
        }
    }

    return false;
}

void Aluno::show() const {
    std::cout << "ALUNO: \n";
    std::cout << "Nome: " << this->getNome() << '\n';
    std::cout << "Idade" << this->getIdade() << '\n';

    std::cout << "Matriculado em: \n";
    std::list<Disciplina*>::const_iterator it = this->disciplinas.begin();
    for (; it != this->disciplinas.end(); ++it) {
        std::cout << "- " << (*it)->getNome() << '\n';
    }
    std::cout << "-------------\n";
}