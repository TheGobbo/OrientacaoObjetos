#include <iostream>
#include <string>

#include "Disciplina.hpp"
#include "Pessoa.hpp"

int main() {
    
    Curso bcc{"Engenharia da Pedra", 0, 10};
    Curso& ref_bcc{bcc};

    Pessoa joao{"Joao", 11144477735, 10};

    Disciplina d1{ref_bcc, "Placas Cuneiformes", &joao}

    return 0;
}