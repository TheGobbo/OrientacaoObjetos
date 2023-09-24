#include "ProfessorAdjunto.hpp"

void ProfessorAdjunto::setLinhaPesquisa(const std::string& linhaPesquisa) {
    this->linhaPesquisa = linhaPesquisa;
}

const std::string& ProfessorAdjunto::getLinhaPesquisa() const { return linhaPesquisa; }

unsigned int ProfessorAdjunto::getSalario() const {
    // return Professor::getCargaHoraria() * Professor::getValorHora() * 4.5 * 1.1;
    return Professor::getSalario() * 1.1;
}
