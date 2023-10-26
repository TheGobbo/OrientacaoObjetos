#include <iostream>

#include "Engenheiro.hpp"
#include "Professor.hpp"
#include "ProfessorAdjunto.hpp"
#include "ProfessorEngenheiro.hpp"


/*

*/

int main() {
    ProfessorEngenheiro pe{"Maria", 1111, 85, 40, 1234};

    // pe.Engenheiro::setNome("Marcia");
    pe.Professor::setNome("Marcia Silva");
    // std::cout << e->getNome() << endl;
    // std::cout << p->getNome() << endl;

    std::cout << pe.Engenheiro::getNome() << " ";
    std::cout << pe.Engenheiro::getSalario() << std::endl;
    std::cout << pe.Professor::getNome() << " ";
    std::cout << pe.Professor::getSalario() << std::endl;

	std::cout << pe.getNome() << " " << pe.getSalario() << std::endl;


    return 0;
}
