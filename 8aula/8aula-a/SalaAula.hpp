#ifndef SALA_AULA_H
#define SALA_AULA_H

#include <list>
#include <string>

#include "Disciplina.hpp"

class SalaAula {
   public:
    SalaAula(std::string nome, unsigned int capacidade);

    std::string getNome();
    void setNome(std::string nome);

    unsigned int getCapacidade();
    void setCapcidade(unsigned int capacidade);

    /* mantem consistencia com Disciplina*/
    void adicionaDisciplina(Disciplina* disciplina);
    void removeDisciplina(Disciplina* disciplina);

    /* realiza operacao somente em SalaAula (base) */
    void _adicionaDisciplina(Disciplina* disciplina);
    void _removeDisciplina(Disciplina* disciplina);

    void show();

   private:
    std::string nome;
    unsigned int capacidade;
    std::list<Disciplina*> disciplinasMinistradas;
};
#endif