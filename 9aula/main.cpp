#include <iostream>

#include "Console.hpp"
#include "ConteudoMinistrado.hpp"
#include "Disciplina.hpp"
#include "Pessoa.hpp"
#include "Retangulo.hpp"

int main() {
    Pessoa prof1{"João", 11111111111, 40};
    Disciplina dis1{"C++", nullptr};
    dis1.setProfessor(&prof1);

    dis1.adicionarConteudoMinistrado("Ponteiros", 4);
    dis1.adicionarConteudoMinistrado("Referencias", 2);
    Console::imprimirDadosDisciplina(dis1);

    dis1.adicionarConteudoMinistrado("plot armor design", 2);
    dis1.adicionarConteudoMinistrado("op mc architecture", 2);

    dis1.removerConteudoMinistrado(0);

    Console::imprimirDadosDisciplina(dis1);

    dis1.limparConteudos();

    Retangulo r1{1, 11};
    r1.show();

    Retangulo r2, r3;

    r2.setLargura(2);
    r2.setAltura(2);
    r2.show();

    r3.setLargura();  // default arg = 123
    r3.show();

    std::cout << "Já foram criados " << Retangulo::getRetangulosCriados() << '\n';

    return 0;
}