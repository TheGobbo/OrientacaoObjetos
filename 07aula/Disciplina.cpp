#include "Disciplina.hpp"

#include <iostream>

Disciplina::Disciplina(Curso& curso, std::string nome) : curso{curso}, nome{nome} {}

Disciplina::Disciplina(Curso& curso, std::string nome, Pessoa* professor)
    : curso{curso}, nome{nome} {
    this->professor = professor;
}

std::string Disciplina::getNome() { return this->nome; }

void Disciplina::setNome(std::string nome) { this->nome = nome; }

int Disciplina::getCargaHoraria() { return this->cargaHoraria; }

void Disciplina::setCargaHoraria(unsigned int cargaHoraria) { this->cargaHoraria = cargaHoraria; }

void Disciplina::setProfessor(Pessoa* professor) { this->professor = professor; }

Pessoa* Disciplina::getProfessor() { return this->professor; }

std::string Disciplina::getNomeProfessor() { return this->professor->getNome(); }

std::string Disciplina::getNomeCurso() { return this->curso.getNome(); }

unsigned short int Disciplina::getMatriculas() { return this->alunos.size(); }

bool Disciplina::adicionarAluno(Pessoa* aluno) {
    if (this->alunos.size() >= 50) {
        return false;
    }

    this->alunos.push_back(aluno);
    return true;
}

std::list<Pessoa*> Disciplina::getAlunos() { return this->alunos; }

bool Disciplina::removerAluno(Pessoa* aluno) {
    if (this->alunos.empty() || aluno == nullptr) {
        return false;
    }

    Pessoa* found{nullptr};

    std::list<Pessoa*>::iterator it;

    for (it = this->alunos.begin(); it != this->alunos.end(); /* remove */) {
        if (aluno == *it) {
            found = *it;
            it = this->alunos.erase(it);
        } else
            ++it;
    }

    if (found != nullptr) {
        return true;
    }

    std::cout << "Aluno " << aluno->getNome() << " nao removido (nao encontrado)\n";
    return true;
}

bool Disciplina::removerAluno(uint64_t cpf) {
    if (this->alunos.empty()) {
        return false;
    }

    Pessoa* found{nullptr};

    std::list<Pessoa*>::iterator it;

    for (it = this->alunos.begin(); it != this->alunos.end(); /* remove */) {
        if (cpf == (*it)->getCpf()) {
            found = *it;
            it = this->alunos.erase(it);
        } else
            ++it;
    }

    if (found != nullptr) {
        return true;
    }

    std::cout << "Aluno nao removido, cpf (" << cpf << ") nao encontrado\n";

    return false;
}

void Disciplina::show() {
    std::cout << "+------------------------------------+\n";
    std::cout << "| Disciplina : " << this->nome << '\n';
    std::cout << "| Professor  : " << this->getNomeProfessor() << '\n';
    std::cout << "| Curso      : " << this->getNomeCurso() << '\n';
    std::cout << "| matriculas : " << this->getMatriculas() << '\n';
    std::cout << "| Alunos : \n";
    showAlunos();
    std::cout << "+------------------------------------+\n";
    return;
}

void Disciplina::showAlunos() {
    std::list<Pessoa*>::iterator aluno;
    for (aluno = this->alunos.begin(); aluno != this->alunos.end(); ++aluno) {
        std::cout << " - " << (*aluno)->getNome() << '\t' << (*aluno)->getIdade() << '\t'
                  << (*aluno)->getCpf() << '\n';
    }
    return;
}