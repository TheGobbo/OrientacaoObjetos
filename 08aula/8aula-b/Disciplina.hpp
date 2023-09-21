#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

#include "Pessoa.hpp"

class SalaAula;

class Disciplina {
    // impossivel sem declarar classe SalaAula acima de Disciplina
    // (funcao amiga definida com tipo incompleto -> compilation error)
    // friend void SalaAula::adicionaDisciplina(Disciplina* disciplina);
    // friend void SalaAula::removerDisciplina(Disciplina* disciplina);
    friend class SalaAula;

   public:
    Disciplina(std::string nome);

    std::string getNome();
    void setNome(std::string nome);

    int getCargaHoraria();
    void setCargaHoraria(unsigned int carga);

    Pessoa* getProfessor();
    void setProfessor(Pessoa* prof);

    void setSalaAula(SalaAula* sala);
    SalaAula* getSalaAula();

    void imprimirDados(std::string& cabecalho, unsigned int cargaTotalCurso);
    void show();

   private:
    std::string nome;
    unsigned short int cargaHoraria;
    Pessoa* professor;
    SalaAula* sala;
};
#endif