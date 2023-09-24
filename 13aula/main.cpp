#include <iostream>
#include <list>

#include "Disciplina.hpp"
#include "Pessoa.hpp"
#include "Professor.hpp"
#include "ProfessorAdjunto.hpp"

int main() {
    ProfessorAdjunto p{"Joao", 0, 100, 20};
    Professor p2{"Maria", 1, 100, 20};
    Aluno a1{"Aluno1", 12345678900, 21};
    Aluno a2{"Aluno2", 12345678900, 21};

    std::cout << "Professores:\n";
    std::cout << p2.getNome() << " -> " << p2.getSalario() << std::endl;
    std::cout << p.getNome() << " -> " << p.getSalario() << std::endl;

    Disciplina d1{"OO"};

    d1.setProfessor(&p2);

    d1.adicionarAluno(&a1);
    d1.adicionarAluno(&a1);
    a1.adicionaDisciplina(&d1);
    a1.adicionaDisciplina(&d1);

    d1.adicionarAluno(&a2);
    d1.adicionarAluno(&a2);
    a2.adicionaDisciplina(&d1);
    a2.adicionaDisciplina(&d1);

    d1.show();
    a1.show();
    a2.show();
    std::cout << "###########\n";

    d1.removerAluno(&a1);
    d1.removerAluno(&a1);
    // d1.removerAluno(&a2);
    // a1.removerDisciplina(&d1);

    d1.show();
    a1.show();
    a2.show();

    return 0;
}