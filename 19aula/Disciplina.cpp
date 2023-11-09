#include "Disciplina.hpp"

#include <iostream>

#include "SalaAula.hpp"

namespace ufpr {

Disciplina::Disciplina(const std::string& nome)
    : nome{nome}, sala{nullptr}, tipo{EnumTipoDisciplina::MANDATORIA} {}

Disciplina::Disciplina(const std::string& nome, SalaAula* const sala)
    : Disciplina{nome} {
    this->setSalaAula(sala);
}

Disciplina::Disciplina(const std::string& nome, SalaAula* const sala,
                       const EnumTipoDisciplina tipo)
    : nome{nome}, sala{nullptr}, tipo{EnumTipoDisciplina::MANDATORIA} {
    this->setSalaAula(sala);
}

// Disciplina::Disciplina(const std::string& nome, SalaAula* const sala,
//                        const EnumTipoDisciplina tipo, const Ementa& ementa)
//     : nome{nome},
//       sala{nullptr},
//       tipo{EnumTipoDisciplina::MANDATORIA},
//       ementa{ementa} {
//     this->setSalaAula(sala);
// }

Disciplina::~Disciplina() {
    // o setSalaAula vai remover a disciplina da sala de aula antiga, caso ela
    // exista
    std::cerr << "Deletando pessoa\n";

    this->setSalaAula(nullptr);
    std::list<ConteudoMinistrado*>::iterator it;
    for (it = conteudos.begin(); it != conteudos.end(); it++)
        delete *it;  // liberando a memória de cada conteúdo
}

/*
   private:
    std::string nome;
    unsigned short int cargaHoraria;
    Professor *professor;
    SalaAula *sala;
    EnumTipoDisciplina tipo;
    Ementa ementa;

    std::list<ConteudoMinistrado *> conteudos;
    std::list<Pessoa *> alunos;
*/

// (Deep) Copy constructor
Disciplina::Disciplina(const Disciplina& other)
    : nome{other.nome},
      cargaHoraria{other.cargaHoraria},
      tipo{other.tipo}  //   ,ementa{other.ementa}
{
    // clang-format off
    this->professor = (other.professor != nullptr) ? new Professor(*other.professor) : nullptr;
    this->sala = (other.sala != nullptr) ? new SalaAula(*other.sala) : nullptr;
    // clang-format on

    // copy list of conteudos
    this->conteudos.clear();
    std::list<ConteudoMinistrado*>::const_iterator it{other.conteudos.begin()};
    for (; it != other.conteudos.end(); ++it) {
        if (*it)
            this->adicionarConteudoMinistrado((*it)->getDescricao(),
                                              (*it)->getCargaHorariaConteudo());
    }

    // std::cout << "OTHER SIZE : " << other.conteudos.size() << '\n';
    // std::cout << "THIS SIZE : " << this->conteudos.size() << '\n';

    // copy list of students
    this->alunos.clear();
    std::list<Pessoa*>::const_iterator itp{other.alunos.begin()};
    for (; itp != other.alunos.end(); ++itp) {
        if (*itp)
            this->alunos.push_back(
                new Pessoa{(*itp)->getNome(), (*itp)->getCpf()});
    }

    std::cerr << "End call Disciplina copy constructor\n";
}

// Move constructor
Disciplina::Disciplina(Disciplina&& other) { std::cerr << "Move constr\n"; }

// Move Assignment
Disciplina& Disciplina::operator=(Disciplina&& other) {
    std::cerr << "operator=&&\n";

    this->nome = other.nome;
    this->cargaHoraria = other.cargaHoraria;
    this->tipo = other.tipo;
    // this->ementa = other.ementa;

    this->professor = other.professor;
    other.professor = nullptr;

    this->sala = other.sala;
    other.sala = nullptr;

    // copy list of conteudos
    this->conteudos = other.conteudos;
    other.conteudos.clear();

    // copy list of students
    this->alunos = other.alunos;
    other.alunos.clear();

    return *this;
}

// Move Assignment
Disciplina& Disciplina::operator=(const Disciplina& other) {
    std::cerr << "oper=\n";
    *this = other;
    return *this;
}

bool Disciplina::operator==(const Disciplina& other) const {
    return this->nome == other.nome && this->cargaHoraria == other.cargaHoraria;
}

bool Disciplina::operator!=(const Disciplina& other) const {
    return !(*this == other);
}

/* */

const std::string& Disciplina::getNome() const { return nome; }

void Disciplina::setNome(const std::string& nome) { this->nome = nome; }

int Disciplina::getCargaHoraria() const { return this->cargaHoraria; }

void Disciplina::setCargaHoraria(const unsigned int carga) {
    this->cargaHoraria = carga;
}

const Professor* Disciplina::getProfessor() const { return this->professor; }

void Disciplina::setProfessor(Professor* const prof) { this->professor = prof; }

void Disciplina::setSalaAula(SalaAula* const sala) {
    if (this->sala !=
        nullptr)  // se já existia uma sala, remover a disciplina dessa sala
        this->sala->disciplinasMinistradas.remove(this);
    this->sala = sala;
    if (this->sala != nullptr)
        this->sala->disciplinasMinistradas.push_back(
            this);  // adicionar a disciplina na nova sala
}

void Disciplina::anularSalaAula() { this->sala = nullptr; }

const SalaAula* Disciplina::getSalaAula() const { return this->sala; }

void Disciplina::imprimirDados(const std::string& cabecalho,
                               const unsigned int cargaTotalCurso) const {
    double pctCurso = (double)this->cargaHoraria / cargaTotalCurso;
    pctCurso = pctCurso * 100;
    std::cout << cabecalho << std::endl;
    std::cout << "Disciplina: " << this->nome << std::endl;
    std::cout << "Carga: " << this->cargaHoraria << std::endl;
    std::cout << "Porcentagem do curso: " << pctCurso << "%" << std::endl;
    std::cout << "Professor: " << this->professor->getNome() << std::endl;
}

void Disciplina::adicionarConteudoMinistrado(
    const std::string& conteudo, const unsigned short cargaHorariaConteudo) {
    this->conteudos.push_back(
        new ConteudoMinistrado{conteudo, cargaHorariaConteudo});
}

void Disciplina::adicionarConteudoMinistrado(ConteudoMinistrado* conteudo) {
    this->conteudos.push_back(conteudo);
}

void Disciplina::imprimirConteudosMinistrados() const {
    // std::cout << "Conteudos ministrados\n";

    std::list<ConteudoMinistrado*>::const_iterator it;
    for (it = conteudos.begin(); it != conteudos.end(); it++) {
        std::cout << "Id: " << (*it)->getId() << std::endl
                  << "Conteudo: " << (*it)->getDescricao() << std::endl
                  << "Carga: " << (*it)->getCargaHorariaConteudo() << std::endl
                  << std::endl;
    }
}

const std::list<ConteudoMinistrado*>& Disciplina::getConteudos() const {
    return this->conteudos;
}

void Disciplina::adicionarAluno(Pessoa* const aluno) {
    this->alunos.push_back(aluno);
}

void Disciplina::removerAluno(Pessoa* const aluno) {
    this->alunos.remove(aluno);
}

void Disciplina::removerAluno(const unsigned long cpf) {
    std::list<Pessoa*>::iterator it;

    for (it = this->alunos.begin(); it != this->alunos.end(); it++)
        if ((*it)->getCpf().getNumero() == cpf) break;
    if (it != this->alunos.end()) this->alunos.erase(it);
}

const std::list<Pessoa*>& Disciplina::getAlunos()
    const {  // retornamos uma referência para a lista, o que custa mais barato
    return this->alunos;
}

// void Disciplina::setEmenta(const Ementa& ementa) { this->ementa = ementa; }

// const Ementa& Disciplina::getEmenta() const { return this->ementa; }

void Disciplina::show() const {
    this->imprimirDados("~~~~~~~~~~~", 2000);
    this->imprimirConteudosMinistrados();

    std::cout << "Alunos: \n";
    std::list<Pessoa*>::const_iterator it{this->alunos.begin()};
    for (; it != this->alunos.end(); ++it) {
        std::cout << (*it)->getNome() << '\n';
    }
    std::cout << "\n";
}

}  // namespace ufpr