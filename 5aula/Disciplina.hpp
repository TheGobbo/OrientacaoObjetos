#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

#include "Pessoa.hpp"

class Disciplina {
   public:
    Disciplina(std::string nomeDisciplina);
    Disciplina(std::string nomeDisciplina, Pessoa* prof);

    std::string getNome();
    void setNome(std::string novoNome);

    int getCargaHoraria();
    void setCargaHoraria(unsigned int novaCarga);

    void setProfessor(Pessoa* prof);
    Pessoa* getProfessor();

    std::string getNomeProfessor();
    unsigned short int getMatriculas();

    bool adicionarAluno(Pessoa* aluno);

    Pessoa** getVetorAlunos();
    bool removerAluno(Pessoa* aluno);
    bool removerAluno(uint64_t cpfAluno);

    void show();
    void showAlunos();

   private:
    std::string nome;
    unsigned short int cargaHoraria;
    Pessoa* professor;

    unsigned short int matriculas{0};
    Pessoa* alunos[50];  // ?
};
#endif
