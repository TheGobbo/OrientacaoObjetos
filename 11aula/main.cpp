#include <iostream>
#include <list>
#include <string>

#include "ConteudoMinistrado.hpp"
#include "Disciplina.hpp"
#include "SalaAula.hpp"

/*
2. Considere o protótipo da função membro a seguir e explique o objetivo de cada const na função:
    `const double* calcularImposto(const Investimento* const inv) const;`

Resposta:

O 1° const indica que o ponteiro retornado pela função não terá permissão para alterar os dados
sendo apontados.

No 2° é indicado que o ptr de objeto passado para a função não terá seus dados
alterados.

Já o 3° indica que o próprio ponteiro passado não será alterado, apontando sempre para o
mesmo objeto.

E por ultimo, o 4° const indica que a função atual não faz nenhuma alteração ao objeto
membro da classe.

*/

int main() {
    Disciplina dis1{"C++", nullptr};
    Disciplina* dis2{new Disciplina{"Java", nullptr}};

    SalaAula sala{"Lab Info 1", 40};
    dis1.setSalaAula(&sala);
    dis2->setSalaAula(&sala);

    std::list<Disciplina*> disSala = sala.getDisciplinas();
    std::list<Disciplina*>::iterator it;
    for (it = disSala.begin(); it != disSala.end(); it++)
        std::cout << (*it)->getNome() << std::endl;

    delete dis2;
    std::cout << "Fim do Programa" << std::endl;

    return 0;
}