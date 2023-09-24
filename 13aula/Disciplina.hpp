#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <list>
#include <string>

#include "Aluno.hpp"
#include "ConteudoMinistrado.hpp"
#include "Professor.hpp"

class SalaAula;  // Forward Declaration

class Disciplina {
    friend void Aluno::adicionaDisciplina(Disciplina* Disciplina);
    friend void Aluno::removerDisciplina(Disciplina* Disciplina);

   public:
    Disciplina(const std::string& nome);
    Disciplina(const std::string& nome, SalaAula* const sala);

    ~Disciplina();

    const std::string& getNome() const;
    void setNome(const std::string& nome);

    int getCargaHoraria() const;
    void setCargaHoraria(const unsigned int carga);

    const Professor* getProfessor() const;
    void setProfessor(Professor* const prof);

    void setSalaAula(SalaAula* const sala);
    const SalaAula* getSalaAula() const;
    void anularSalaAula();

    void imprimirDados(const std::string& cabecalho, const unsigned int cargaTotalCurso) const;

    void adicionarConteudoMinistrado(const std::string& conteudo,
                                     const unsigned short cargaHorariaConteudo);
    void imprimirConteudosMinistrados() const;
    const std::list<ConteudoMinistrado*>& getConteudos() const;

    void adicionarAluno(Aluno* const aluno);
    void removerAluno(Aluno* const aluno);
    void removerAluno(const unsigned long cpf);
    const std::list<Aluno*>& getAlunos() const;

    const bool possuiMatricula(Aluno* const aluno) const;

    void show() const;

   private:
    std::string nome;
    unsigned short int cargaHoraria;
    Professor* professor;
    SalaAula* sala;

    std::list<ConteudoMinistrado*> conteudos;
    std::list<Aluno*> alunos;
};
#endif