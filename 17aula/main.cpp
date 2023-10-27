#include <iostream>
#include <stdexcept>

#include "ProfessorAdjunto.hpp"
#include "Pessoa.hpp"
#include "ProfessorEngenheiro.hpp"
#include "CPFInvalidoException.hpp"
#include "NegativoInvalido.hpp"
#include "SalaAula.hpp"

/*
TODOs:
- [x] Transfira o projeto completo para o namespace ufpr (todas as classes criadas até agora devem fazer parte desse namespace). Instancie alguns objetos de exemplo no main.
    v CPFInvalidoException
    v Console
    v ConteudoMinistrado
    v Disciplina
    v Engenheiro
    v EnumTipoDisciplina
    v NegativoInvalido
    v Pessoa
    v Professor
    v ProfessorAdjunto
    v ProfessorEngenheiro
    v SalaAula

- [ ] A classe disciplina não deve aceitar uma carga horária menor do que 30 horas para uma disciplina mandatória. Disciplinas optativas podem ter qualquer carga horária. Modifique esse comportamento na classe disciplina, lançando uma exceção caso um valor inválido seja passado.
*/


int main(){
    ufpr::SalaAula sala{"Lab info 1", 30};
    std::cout << sala.getNome() << "\n\n";

    ufpr::Disciplina d1{"Programacao", ufpr::EnumTipoDisciplina::MANDATORIA};

    try {
        d1.setCargaHoraria(20);
    } catch (const std::exception& e) {
        std::cerr << "Erro generico: " << e.what() << "\n\n";
    }

    std::cout << d1.getNome() << "\n\n";

    ufpr::ConteudoMinistrado c1{"Conteudo ministrado", 100};
    std::cout << c1.getDescricao() << "\n\n";

    ufpr::Engenheiro e1{"Engenheiro", 11111111111, 3};
    std::cout << e1.getNome() << "\n\n";

    ufpr::ProfessorAdjunto pf1{"Professor Adjunto", 11111111111, 15, 30};
    std::cout << "Salario prof adj: " << pf1.getSalario() << "\n\n";

    return 0;
}