#if !defined(ALUNO_HPP)
#define ALUNO_HPP

#include <stdint.h>

#include <list>

// #include "Disciplina.hpp"
#include "Pessoa.hpp"

class Disciplina;

class Aluno : Pessoa {
    // friend void Disciplina::removerAluno(Aluno* const aluno);
    // friend void Disciplina::adicionarAluno(Aluno* const aluno);
    friend class Disciplina;

   public:
    using Pessoa::Pessoa;

    const int8_t getIra() const;
    const int32_t getGrr() const;
    const int8_t getSemestre() const;
    const std::list<Disciplina*>& getDisciplinas() const;

    void setIra(int8_t ira);
    void setGrr(int32_t grr);
    void setSemestre(int8_t semestre);
    void adicionaDisciplina(Disciplina* disciplina);
    void removerDisciplina(Disciplina* disciplina);

    void show() const;

   private:
    int32_t grr;
    int8_t semestre;
    int8_t ira;  // 0-100 / 100
                 // curso nao presente neste projeto
    std::list<Disciplina*> disciplinas;
    bool matriculadoEm(Disciplina* const disciplina) const;
};

#endif  // ALUNO_HPP
