#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <list>
#include <string>

#include "ConteudoMinistrado.hpp"
#include "Pessoa.hpp"

class SalaAula;  // Forward Declaration

class Disciplina {
   public:
    Disciplina(std::string nome);
    Disciplina(std::string nome, SalaAula* sala);

    ~Disciplina();

    std::string getNome() const;
    void setNome(const std::string& nome);

    int getCargaHoraria() const;
    void setCargaHoraria(const unsigned int carga);

    Pessoa* getProfessor() const;
    void setProfessor(Pessoa* prof);

    void setSalaAula(SalaAula* sala);
    SalaAula* getSalaAula() const;
    void anularSalaAula();

    void imprimirDados(const std::string& cabecalho, unsigned int cargaTotalCurso);

    void adicionarConteudoMinistrado(std::string conteudo, unsigned short cargaHorariaConteudo);
    void imprimirConteudosMinistrados();
    const std::list<ConteudoMinistrado*>& getConteudos() const;

    void adicionarAluno(Pessoa* aluno);
    void removerAluno(Pessoa* aluno);
    void removerAluno(unsigned long cpf);
    const std::list<Pessoa*>& getAlunos() const;

   private:
    std::string nome;
    unsigned short int cargaHoraria;
    Pessoa* professor;
    SalaAula* sala;

    std::list<ConteudoMinistrado*> conteudos;
    std::list<Pessoa*> alunos;
};
#endif