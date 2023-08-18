#include "Disciplina.hpp"

#include <iostream>

Disciplina::Disciplina(Curso& curso, std::string nome) : nome{nome} {
    this->curso = curso;
}

Disciplina::Disciplina(Curso& curso, std::string nome, Pessoa* professor)
    : nome{nome}, professor{professor} {
        this->curso = curso;
}

std::string Disciplina::getNome() { return this->nome; }

void Disciplina::setNome(std::string nome) { 
    this->nome = nome;
 }

int Disciplina::getCargaHoraria() { return this->cargaHoraria; }

void Disciplina::setCargaHoraria(unsigned int cargaHoraria) {
    this->cargaHoraria = cargaHoraria;
}

void Disciplina::setProfessor(Pessoa* professor) { this->professor = professor; }

Pessoa* Disciplina::getProfessor() { return this->professor; }

std::string Disciplina::getNomeProfessor() { return this->professor->getNome(); }

unsigned short int Disciplina::getMatriculas() { return this->matriculas; }

bool Disciplina::adicionarAluno(Pessoa* aluno) {
    if (this->matriculas >= 50) {
        return false;
    }

    this->alunos[matriculas] = aluno;
    this->matriculas++;
    return true;
}

Pessoa** Disciplina::getVetorAlunos() { return this->alunos; }

bool Disciplina::removerAluno(Pessoa* aluno) {
    if (this->matriculas == 0 || aluno == nullptr) {
        return false;
    }

    Pessoa* found{nullptr};

    for (int i = 0; i < this->matriculas; i++) {
        if (aluno == this->alunos[i]) {
            found = this->alunos[i];
            this->matriculas--;
        }

        if (found != nullptr && i + 1 < matriculas) {
            this->alunos[i] = this->alunos[i + 1];
        }
    }

    if (found != nullptr) {
        return true;
    }

    std::cout << "Aluno " << aluno->getNome()
              << " nao removido (nao encontrado)\n";
    return true;
}

bool Disciplina::removerAluno(uint64_t cpf) {
    if (this->matriculas == 0) {
        return false;
    }

    Pessoa* aluno{nullptr};

    for (int i = 0; i < this->matriculas; i++) {
        if (aluno == nullptr && this->alunos[i] != nullptr &&
            cpf == this->alunos[i]->getCpf()) {
            aluno = this->alunos[i];
            this->matriculas--;
        }

        if (aluno != nullptr && i + 1 < this->matriculas) {
            this->alunos[i] = this->alunos[i + 1];
        }
    }

    if (aluno != nullptr) {
        return true;
    }

    std::cout << "Aluno nao removido, cpf (" << cpf
              << ") nao encontrado\n";

    return false;
}

void Disciplina::show() {
    std::cout << "+------------------------------------+\n";
    std::cout << "| Disciplina : " << nome << '\n';
    std::cout << "| Professor  : " << getNomeProfessor() << '\n';
    std::cout << "| matriculas : " << matriculas << '\n';
    std::cout << "| Alunos : \n";
    showAlunos();
    std::cout << "+------------------------------------+\n";
    return;
}

void Disciplina::showAlunos() {
    for (short int i = 0; i < matriculas; i++) {
        std::cout << " - " << alunos[i]->getNome() << '\t'
                  << alunos[i]->getIdade() << '\t' << alunos[i]->getCpf()
                  << '\n';
    }
    return;
}