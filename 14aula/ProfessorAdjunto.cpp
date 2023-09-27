#include "ProfessorAdjunto.hpp"

#include <iostream>

ProfessorAdjunto::~ProfessorAdjunto() {
    std::cout << "Destroi professorAdjunto\n";
}

const std::string& ProfessorAdjunto::getLinhaPesquisa() const {
    return this->linhaPesquisa;
}

void ProfessorAdjunto::setLinhaPesquisa(const std::string& linhaPesquisa) {
    this->linhaPesquisa = linhaPesquisa;
}

unsigned int ProfessorAdjunto::getSalario() const {
    return Professor::getSalario() * 1.1;
}