#include <iostream>
#include <memory>

#include "Ementa.hpp"
#include "Livro.hpp"

/* nao substitui todos os ponteiros para smart pointers devido ao tempo
 * necessario
 */

int main() {
    ufpr::Ementa* ementa1{new ufpr::Ementa{"Paradigmas de programação"}};
    ufpr::Ementa* ementa2{new ufpr::Ementa{"Orientação a Objetos"}};
    ufpr::Ementa* ementa3{new ufpr::Ementa{"Prog. Em Java"}};

    ementa1->addLivro(ufpr::Livro::carregarLivro(1234));
    ementa1->addLivro(ufpr::Livro::carregarLivro(5678));

    ementa2->addLivro(ufpr::Livro::carregarLivro(1234));

    delete ementa1;
    std::cout << "Ementa 1 deletada, deletando ementa 2\n";
    delete ementa2;

    ementa3->addLivro(ufpr::Livro::carregarLivro(5678));

    delete ementa3;

    return 0;
}