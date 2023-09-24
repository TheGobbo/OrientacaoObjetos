#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Pessoa.hpp"

class Professor : public Pessoa {
   public:
    Professor(const std::string& nome, const uint64_t cpf, const unsigned int salario,
              const unsigned short cargaHoraria);
    ~Professor();

    void setValorHora(const unsigned int valorHora);
    unsigned int getValorHora() const;
    void setCargaHoraria(const unsigned short cargaHoraria);
    unsigned short getCargaHoraria() const;
    unsigned int getSalario() const;

   private:
    unsigned int valorHora;
    unsigned short cargaHoraria;
};
#endif
