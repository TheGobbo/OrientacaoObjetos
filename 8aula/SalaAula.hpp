#ifndef SALA_AULA_H
#define SALA_AULA_H

#include <list>
#include <string>

#include "Disciplina.hpp"

class SalaAula {
    friend void Disciplina::setSalaAula(SalaAula* sala);

   public:
    SalaAula(std::string nome, unsigned int capacidade);

    std::string getNome();
    void setNome(std::string nome);

    unsigned int getCapacidade();
    void setCapcidade(unsigned int capacidade);

    std::list<Disciplina*>& getDisciplinas();
    void adicionaDisciplina(Disciplina* disciplina);
    void imprimirDisciplinas();

   private:
    std::string nome;
    unsigned int capacidade;
    std::list<Disciplina*> disciplinasMinistradas;
};
#endif