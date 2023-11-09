#include <iostream>
#include <list>

#include "ConteudoMinistrado.hpp"
#include "Disciplina.hpp"
#include "Pessoa.hpp"
#include "Professor.hpp"
#include "SalaAula.hpp"

int main() {
    ufpr::Pessoa p1{"Pessoa 1 original", 11111111111, 21};
    ufpr::Pessoa p2{"Pessoa 2 original", 11111111111, 22};
    ufpr::Pessoa p3{"Pessoa 3 original", 11111111111, 23};
    ufpr::Professor prof1{"Professor Original", 11111111111, 2000, 50};

    ufpr::SalaAula s1{"Sala Original", 20};

    ufpr::Disciplina d1{"Sala Original", &s1};

    d1.adicionarAluno(&p1);
    d1.adicionarAluno(&p2);
    d1.adicionarAluno(&p3);

    d1.adicionarConteudoMinistrado("Conteudo Original 1", 100);

    d1.setSalaAula(&s1);
    d1.setProfessor(&prof1);
    d1.setCargaHoraria(500);

    d1.show();

    std::cerr << "begin copy\n";
    ufpr::Disciplina copia = d1;
    std::cerr << "made copy\n";

    copia.adicionarConteudoMinistrado("Conteudo Original 2", 200);
    copia.adicionarConteudoMinistrado("Conteudo Original 3", 300);
    copia.removerAluno(11111111111);
    std::cout << "Done\n";

    copia.show();
    d1.show();

    std::cout << p1.getNome() << '\n';

    return 0;
}