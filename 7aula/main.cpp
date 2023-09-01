#include <iostream>
#include <string>

#include "Disciplina.hpp"
#include "Pessoa.hpp"

int main() {
    Curso bcc{"Engenharia da Pedra", -2000, 10};
    Curso& ref_bcc{bcc};

    Pessoa* prof{new Pessoa{"Joao", 11144477735, 10}};
    Pessoa* a1{new Pessoa{"aluno 1", 0, 21}};
    Pessoa* a2{new Pessoa{"aluno 2", 1, 20}};
    Pessoa* a3{new Pessoa{"aluno 3", 11111111111, 23}};

    Disciplina d1{ref_bcc, "Placas Cuneiformes", prof};
    d1.adicionarAluno(a1);
    d1.adicionarAluno(a2);

    Disciplina d2{ref_bcc, "Tool crafting", prof};
    d2.adicionarAluno(a1);
    d2.adicionarAluno(a2);
    d2.adicionarAluno(a3);
    d2.adicionarAluno(a3);
    d2.adicionarAluno(a3);
    d2.adicionarAluno(a3);

    bcc.show();

    d1.show();
    d2.show();

    std::cout << "Removendo : ";
    a3->show();
    d2.removerAluno(11111111111);
    d2.removerAluno(a3);

    d2.show();

    // delete prof;
    // d1.show();

    return 0;
}