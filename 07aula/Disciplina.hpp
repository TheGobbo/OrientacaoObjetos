#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <list>
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

    std::list<Pessoa*> getAlunos();
    bool removerAluno(Pessoa* aluno);
    bool removerAluno(uint64_t cpf);

    void show();
    void showAlunos();

   private:
    Curso& curso;
    std::string nome;
    unsigned short int cargaHoraria;
    Pessoa* professor;

    std::list<Pessoa*> alunos;
};
#endif
