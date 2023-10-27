#include "Professor.hpp"
#include "NegativoInvalido.hpp"

#include <stdexcept>

using namespace ufpr;

Professor::Professor(const std::string& nome, const unsigned long cpfn,
               const unsigned int valorHora, const unsigned short cargaHoraria)
        :Pessoa(nome, cpf), valorHora(valorHora), cargaHoraria(cargaHoraria) {
}

Professor::~Professor(){
}

void Professor::setValorHora(const int valorHora){
    if(valorHora < 0) 
        throw NegativoInvalido(valorHora);
    this->valorHora = valorHora;
}

int Professor::getValorHora() const{
    return this->valorHora;
}

void Professor::setCargaHoraria(const short cargaHoraria){
    if(cargaHoraria < 0) 
        throw NegativoInvalido(cargaHoraria);
    this->cargaHoraria = cargaHoraria;
}

short Professor::getCargaHoraria() const{
    return this->cargaHoraria;
}

unsigned int Professor::getSalario() const{
    //assumindo que um mês tem aprox 4.5 semanas
    return valorHora * cargaHoraria * 4.5;
}