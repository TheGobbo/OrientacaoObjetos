#include <iostream>

#include "Pessoa.hpp"
#include "Util.hpp"

int main() {
    std::list<int> valores;
    valores.push_back(1);
    valores.push_back(2);
    valores.push_back(3);

    std::list<double> doubl;
    doubl.push_back(1.1);
    doubl.push_back(1.2);
    doubl.push_back(1.3);

    std::list<std::string> lista;
    lista.push_back("abacate");
    lista.push_back("sushi");
    lista.push_back("risotto");

    std::cout << Util<int>::somar(valores) << '\n';
    std::cout << Util<double>::somar(doubl) << '\n';
    std::cout << Util<std::string>::somar(lista) << '\n';

    std::cout << "Fim!!!\n";
    return 0;
}
