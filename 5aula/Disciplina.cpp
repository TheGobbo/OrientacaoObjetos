#include "Disciplina.hpp"

Disciplina::Disciplina(std::string nomeDisciplina) : nome{nomeDisciplina} {}

Disciplina::Disciplina(std::string nomeDisciplina, Pessoa* prof)
    : nome{nomeDisciplina}, professor{prof} {}

std::string Disciplina::getNome() { return nome; }

void Disciplina::setNome(std::string novoNome) { nome = novoNome; }

int Disciplina::getCargaHoraria() { return cargaHoraria; }

void Disciplina::setCargaHoraria(unsigned int novaCarga) {
    cargaHoraria = novaCarga;
}

void Disciplina::setProfessor(Pessoa* prof) { professor = prof; }

Pessoa* Disciplina::getProfessor() { return professor; }

std::string Disciplina::getNomeProfessor() { return professor->getNome(); }

unsigned short int Disciplina::getMatriculas() { return matriculas; }

bool Disciplina::adicionarAluno(Pessoa* aluno) {
    if (matriculas >= 50) {
        return false;
    }

    alunos[matriculas] = aluno;
    matriculas++;
    return true;
}

Pessoa** Disciplina::getVetorAlunos() { return alunos; }

bool Disciplina::removerAluno(Pessoa* aluno) {
    if (matriculas == 0) {
        return false;
    }

    matriculas--;
    alunos[matriculas] = nullptr;
    return true;
}

bool Disciplina::removerAluno(uint64_t cpfAluno) {
    if (matriculas == 0) {
        return false;
    }

    Pessoa* aluno{nullptr};

    for (int i = 0; i < matriculas; i++) {
        if (cpfAluno == alunos[i]->getCpf()) {
            aluno = alunos[i];
            matriculas--;
        }

        if (aluno != nullptr && i + 1 < matriculas) {
            alunos[i] = alunos[i + 1];
            // alunos[i + 1] = nullptr;
        }
    }

    if (alunos != nullptr) {
        return true;
    }

    return false;
}
