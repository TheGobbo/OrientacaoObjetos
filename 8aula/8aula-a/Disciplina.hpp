#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

#include "Pessoa.hpp"

class SalaAula;

class Disciplina {
   public:
    Disciplina(std::string nome);

    std::string getNome();
    void setNome(std::string nome);

    int getCargaHoraria();
    void setCargaHoraria(unsigned int carga);

    Pessoa* getProfessor();
    void setProfessor(Pessoa* prof);

    /* mantem consistencia com SalaAula */
    void setSalaAula(SalaAula* sala);
    SalaAula* getSalaAula();

    /* realiza operacao somente em Disciplina (base) */
    void _setSalaAula(SalaAula* sala);

    void imprimirDados(std::string& cabecalho, unsigned int cargaTotalCurso);
    void show();

   private:
    std::string nome;
    unsigned short int cargaHoraria;
    Pessoa* professor;
    SalaAula* sala;
};
#endif