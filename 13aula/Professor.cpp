#include "Professor.hpp"

#include <iostream>

#include "Pessoa.hpp"

Professor::Professor(const std::string& nome, const uint64_t cpf, const unsigned int valorHora,
                     const unsigned short cargaHoraria)
    : Pessoa{nome, cpf}, valorHora{valorHora}, cargaHoraria{cargaHoraria} {}

Professor::~Professor() {}

void Professor::setValorHora(const unsigned int valorHora) {
    if (valorHora > 0) {
        this->valorHora = valorHora;
    }
}

unsigned int Professor::getValorHora() const { return this->valorHora; }

void Professor::setCargaHoraria(const unsigned short cargaHoraria) {
    if (cargaHoraria > 0) {
        this->cargaHoraria = cargaHoraria;
    }
}

unsigned short Professor::getCargaHoraria() const { return this->cargaHoraria; }

unsigned int Professor::getSalario() const { return valorHora * cargaHoraria * 4.5; }