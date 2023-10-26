#include "Professor.hpp"
#include <stdexcept>

Professor::Professor(const std::string& nome, const unsigned long cpf,
               const unsigned int valorHora, const unsigned short cargaHoraria)
        :Pessoa(nome, cpf), valorHora(valorHora), cargaHoraria(cargaHoraria) {
}

Professor::~Professor(){
}

void Professor::setValorHora(const int valorHora){
    if(valorHora < 0) throw std::invalid_argument{"Valor hora deve ser positivo"};
    this->valorHora = valorHora;
}

int Professor::getValorHora() const{
    return this->valorHora;
}

void Professor::setCargaHoraria(const short cargaHoraria){
    if(cargaHoraria < 0) throw std::invalid_argument{"Carga horaria deve ser positiva"};
    this->cargaHoraria = cargaHoraria;
}

short Professor::getCargaHoraria() const{
    return this->cargaHoraria;
}

unsigned int Professor::getSalario() const{
    //assumindo que um mês tem aprox 4.5 semanas
    return valorHora * cargaHoraria * 4.5;
}