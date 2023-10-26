#include "TelaDesenho.hpp"

size_t TelaDesenho::num_formas{0};

TelaDesenho::TelaDesenho() {}

TelaDesenho::~TelaDesenho() {
    std::list<Forma*>::const_iterator forma{this->formas.begin()};

    for (; forma != this->formas.end(); ++forma) {
        if (*forma) delete (*forma);
    }
}

void TelaDesenho::adicionaForma(Forma* forma) {
    if (forma == nullptr) return;
    this->formas.push_back(forma);
    TelaDesenho::num_formas++;
}

double TelaDesenho::calcularAreaTotal() const {
    if (TelaDesenho::num_formas == 0) {
        return 0;
    }

    double soma = 0;
    std::list<Forma*>::const_iterator forma{this->formas.begin()};

    for (; forma != this->formas.end(); ++forma) {
        soma += (*forma)->calculaArea();
    }

    return soma;
}