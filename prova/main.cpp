#include <iostream>

#include "Circulo.hpp"
#include "Retangulo.hpp"
#include "TelaDesenho.hpp"

int main() {
    TelaDesenho td;

    Retangulo* r1{new Retangulo{10, 10}};
    Retangulo* r2{new Retangulo{4, 4}};
    Circulo* c1{new Circulo{1.69257}};

    td.adicionaForma(r1);
    td.adicionaForma(c1);

    std::cout << "Area total : " << td.calcularAreaTotal() << '\n';
    r1->setAltura(4.0);
    r1->setLargura(4.0);

    std::cout << "Area total : " << td.calcularAreaTotal() << '\n';
    td.adicionaForma(r2);

    std::cout << "Area total : " << td.calcularAreaTotal() << '\n';

    TelaDesenho* tv_globinho{new TelaDesenho{}};

    tv_globinho->adicionaForma(new Circulo{1.0});

    std::cout << tv_globinho->calcularAreaTotal() << '\n';

    delete tv_globinho;

    return 0;
}
