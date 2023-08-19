#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

#include "Curso.hpp"
#include "Pessoa.hpp"

class Disciplina {
   public:
    Disciplina(Curso& curso, std::string nome);
    Disciplina(Curso& curso, std::string nome, Pessoa* professor);

    std::string getNome();
    void setNome(std::string novoNome);

    int getCargaHoraria();
    void setCargaHoraria(unsigned int cargaHoraria);

    void setProfessor(Pessoa* professor);
    Pessoa* getProfessor();

    std::string getNomeProfessor();
    std::string getNomeCurso();
    unsigned short int getMatriculas();

    bool adicionarAluno(Pessoa* aluno);

    Pessoa** getVetorAlunos();
    bool removerAluno(Pessoa* aluno);
    bool removerAluno(uint64_t cpf);

    void show();
    void showAlunos();

   private:
    Curso& curso;
    std::string nome;
    unsigned short int cargaHoraria;
    Pessoa* professor;

    unsigned short int matriculas{0};
    Pessoa* alunos[50];
};
#endif
