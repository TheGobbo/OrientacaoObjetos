#include "Disciplina.hpp"

#include <iostream>

#include "SalaAula.hpp"

Disciplina::Disciplina(std::string nome)
    : nome{nome}, professor{nullptr}, sala{nullptr} {}

std::string Disciplina::getNome() { return nome; }

void Disciplina::setNome(std::string nome) { this->nome = nome; }

int Disciplina::getCargaHoraria() { return this->cargaHoraria; }

void Disciplina::setCargaHoraria(unsigned int carga) {
    this->cargaHoraria = carga;
}

Pessoa* Disciplina::getProfessor() { return this->professor; }

void Disciplina::setProfessor(Pessoa* prof) { this->professor = prof; }

SalaAula* Disciplina::getSalaAula() { return this->sala; }

void Disciplina::setSalaAula(SalaAula* sala) {
    // precisariamos ainda verificar se sala nao eh nullptr
    // faremos isso no topico excecoes no futuro
    if (this->sala != nullptr) this->sala->disciplinasMinistradas.remove(this);

    this->sala = sala;

    if (sala != nullptr) {
        sala->disciplinasMinistradas.push_back(this);
    }
}

void Disciplina::imprimirDados(std::string& cabecalho,
                               unsigned int cargaTotalCurso) {
    double pctCurso = (double)this->cargaHoraria / cargaTotalCurso;
    pctCurso = pctCurso * 100;
    std::cout << cabecalho << std::endl;
    std::cout << "Disciplina: " << this->nome << std::endl;
    std::cout << "Carga: " << this->cargaHoraria << std::endl;
    std::cout << "Porcentagem do curso: " << pctCurso << "%" << std::endl;
    std::cout << "Professor: " << this->professor->getNome() << std::endl;
}