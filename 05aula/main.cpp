#include <iostream>
#include <string>

#include "Disciplina.hpp"
#include "Pessoa.hpp"

void Disciplina::show() {
    std::cout << "+------------------------------------+\n";
    std::cout << "| Disciplina : " << nome << '\n';
    std::cout << "| Professor  : " << getNomeProfessor() << '\n';
    std::cout << "| matriculas : " << matriculas << '\n';
    std::cout << "| Alunos : \n";
    showAlunos();
    std::cout << "+------------------------------------+\n";
    return;
}

void Disciplina::showAlunos() {
    for (short int i = 0; i < matriculas; i++) {
        std::cout << " - " << alunos[i]->getNome() << '\t'
                  << alunos[i]->getIdade() << '\t' << alunos[i]->getCpf()
                  << '\n';
    }
    return;
}

void Pessoa::show() {
    std::cout << nome << '\t' << idade << '\t' << cpf << '\n';
}

int main() {
    Pessoa p1{"Joao", 11111111111, 20};
    Pessoa p2{"Maria"};

    Disciplina d1{"Orientacao a Objetos"};
    d1.setProfessor(&p1);
    p1.setNome("Joao da Silva");

    p2.show();

    d1.show();

    Pessoa* ptr1{new Pessoa{"gobbo"}};
    ptr1->show();

    Disciplina* ptr2{new Disciplina{"Grandes Ideias", new Pessoa{"Vignatti"}}};
    ptr2->show();

    // SEG FAULT
    // Pessoa* vazio{nullptr};
    // std::cout << vazio->getNome() << '\n';

    Pessoa* prof = ptr2->getProfessor();

    delete ptr1;
    delete ptr2;

    prof->show();
    delete prof;

    Disciplina oo{"Orientacao Obj", new Pessoa{"Paulo"}};
    std::cout << oo.getMatriculas() << '\n';

    Pessoa* aluno1{new Pessoa{"Eduardo", 11111111111, 21}};
    Pessoa* aluno2{new Pessoa{"Anderson", 11144477735, 100}};

    oo.adicionarAluno(aluno1);
    oo.adicionarAluno(aluno2);
    oo.show();

    oo.removerAluno(aluno2);
    oo.show();

    for (int i = 0; i < 4; i++) {
        oo.adicionarAluno(aluno2);
    }
    oo.show();

    oo.removerAluno(12345678910);
    oo.removerAluno(11144477735);
    // oo.removerAluno(aluno1);

    oo.show();

    return 0;
}