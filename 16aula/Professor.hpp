#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Pessoa.hpp"
class Professor : virtual public Pessoa{
    public:
        Professor(const std::string& nome, const unsigned long cpf,
                const unsigned int salario, const unsigned short cargaHoraria);
        virtual ~Professor();

        void setValorHora(const int valorHora);
        int getValorHora() const;

        void setCargaHoraria(const short cargaHoraria);
        short getCargaHoraria() const;
        virtual unsigned int getSalario() const;

    private:
        unsigned int valorHora;
        unsigned short cargaHoraria;
};
#endif