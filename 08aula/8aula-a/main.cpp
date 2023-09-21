#include <iostream>
#include <list>
#include <string>

#include "Disciplina.hpp"
#include "Pessoa.hpp"
#include "SalaAula.hpp"

int main() {
    Pessoa prof1{"João", 11111111111, 40};
    Disciplina dis1{"Orientacao a Objetos"};
    dis1.setProfessor(&prof1);

    Pessoa prof2{"Maria", 22222222222, 30};
    Disciplina dis2{"Sistemas Operacionais"};
    dis2.setProfessor(&prof2);

    SalaAula sala{"Lab Info 1", 20};

    dis1.setSalaAula(&sala);
    sala.adicionaDisciplina(&dis2);

    dis2.setSalaAula(&sala);         // redundante
    sala.adicionaDisciplina(&dis1);  // redundante

    sala.show();

    dis1.show();
    dis2.show();

    std::cout << "REMOVENDO " << dis2.getNome() << '\n';

    sala.removeDisciplina(&dis2);

    dis2.show();
    sala.show();

    dis1.setSalaAula(nullptr);

    std::cout << "REMOVENDO " << dis1.getNome() << '\n';
    dis1.show();
    sala.show();

    return 0;
}
