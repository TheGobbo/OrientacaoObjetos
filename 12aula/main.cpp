#include <iostream>

#include "FilaCircular.hpp"
#include "Pilha.hpp"

int main() {
    FilaCircular<int, 2> fc;

    fc.enqueue(1);
    fc.enqueue(2);
    fc.enqueue(3);
    fc.dequeue();
    fc.enqueue(3);
    fc.dequeue();
    fc.dequeue();
    fc.dequeue();
    fc.enqueue(4);
    fc.enqueue(5);
    fc.dequeue();
    fc.show();

    int retorno;
    Pilha p;
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);

    while (!p.estaVazia()) {
        p.pop(&retorno);
        std::cout << retorno << "\n";
    }

    std::cout << "Fim\n";

    return 0;
}