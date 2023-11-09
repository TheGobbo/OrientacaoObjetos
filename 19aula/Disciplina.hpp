#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <list>
#include <string>

#include "ConteudoMinistrado.hpp"
#include "Ementa.hpp"
#include "EnumTipoDisciplina.hpp"
#include "Pessoa.hpp"
#include "Professor.hpp"

namespace ufpr {
class SalaAula;  // Forward Declaration
class Disciplina {
   public:
    Disciplina(const std::string &nome);
    Disciplina(const std::string &nome, SalaAula *const sala);
    Disciplina(const std::string &nome, SalaAula *const sala,
               const EnumTipoDisciplina tipo);
    // Disciplina(const std::string &nome, SalaAula *const sala,
    //            const EnumTipoDisciplina tipo, const Ementa &ementa);

    Disciplina(const Disciplina &other);  // Copy constructor
    Disciplina(Disciplina &&other);       // Move constructor

    virtual ~Disciplina();

    const std::string &getNome() const;
    void setNome(const std::string &nome);

    int getCargaHoraria() const;
    void setCargaHoraria(const unsigned int carga);

    const Professor *getProfessor() const;
    void setProfessor(Professor *const prof);

    void setSalaAula(SalaAula *const sala);
    const SalaAula *getSalaAula() const;
    void anularSalaAula();

    void imprimirDados(const std::string &cabecalho,
                       const unsigned int cargaTotalCurso) const;

    void adicionarConteudoMinistrado(const std::string &conteudo,
                                     const unsigned short cargaHorariaConteudo);
    void adicionarConteudoMinistrado(ConteudoMinistrado *conteudo);

    void show() const;

    void imprimirConteudosMinistrados() const;
    const std::list<ConteudoMinistrado *> &getConteudos() const;

    void adicionarAluno(Pessoa *const aluno);
    void removerAluno(Pessoa *const aluno);
    void removerAluno(const unsigned long cpf);
    const std::list<Pessoa *> &getAlunos() const;

    // void setEmenta(const Ementa &ementa);
    // const Ementa &getEmenta() const;

    // - / + * nao faz sentido
    // <= >= < > nao faz sentido
    // (), [] nao faz sentido
    // == != faz sentido

    // Copy Assignment Operator
    Disciplina &operator=(const Disciplina &other);

    // Move Assignment Operator
    Disciplina &operator=(Disciplina &&other);

    // Equality Operator
    bool operator==(const Disciplina &other) const;

    // Inequality Operator
    bool operator!=(const Disciplina &other) const;

   private:
    std::string nome;
    unsigned short int cargaHoraria;
    Professor *professor;
    SalaAula *sala;
    EnumTipoDisciplina tipo;
    // Ementa ementa;

    std::list<ConteudoMinistrado *> conteudos;
    std::list<Pessoa *> alunos;
};
}  // namespace ufpr
#endif