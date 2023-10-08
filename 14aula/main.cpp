#include <iostream>

#include "Pessoa.hpp"
#include "Professor.hpp"
#include "ProfessorAdjunto.hpp"

int main() {
    // ProfessorAdjunto *p{new ProfessorAdjunto{"Joao", 11111111111, 8500, 40}};
    Professor *ptr{new ProfessorAdjunto{"Joao", 11111111111, 8500, 40}};

    // std::cout << p->getNome() << " " << p->getSalario() << '\n';
    std::cout << ptr->getNome() << " " << ptr->getSalario() << std::endl;

    delete ptr;

    return 0;
}
