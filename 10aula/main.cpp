#include <iostream>

#include "Console.hpp"
#include "ConteudoMinistrado.hpp"
#include "Disciplina.hpp"
#include "Pessoa.hpp"
#include "SalaAula.hpp"

int main() {
    Disciplina dis1{"C++", nullptr};
    Disciplina* dis2{new Disciplina{"Magic systems", nullptr}};

    SalaAula sala{"Lab5", 30};

    dis1.setSalaAula(&sala);
    dis2->setSalaAula(&sala);

    std::list<Disciplina*> disSala = sala.getDisciplinas();
    std::list<Disciplina*>::iterator it;
    for (it = disSala.begin(); it != disSala.end(); ++it) {
        std::cout << (*it)->getNome() << '\n';
    }

    dis1.adicionarConteudoMinistrado("Ponteiros", 4);
    dis1.adicionarConteudoMinistrado("Referencias", 2);
    Console::imprimirDadosDisciplina(dis1);

    delete dis2;

    std::cerr << "Fim do programa\n";

    return 0;
}