#include <iostream>

#include "CPF.hpp"

void show(const ufpr::CPF& cpf) { std::cout << "CPF eh : " << cpf << '\n'; }

int main() {
    ufpr::CPF cpf{11111111111};
    uint64_t val{cpf};
    std::string str;

    str = static_cast<std::string>(cpf);

    std::cout << "uint: " << val << ", str: " + str << "\n";

    show(cpf);
    // show(22222222222);

    return 0;
}

// #include <iostream>
// #include <list>

// #include "Ementa.hpp"
// #include "Disciplina.hpp"
// #include "Console.hpp"

// int main(){
//     std::list<ufpr::Ementa> ementas;
//     ementas.push_back(ufpr::Ementa{"Ementa 1"});
//     ementas.push_back(ufpr::Ementa{"Ementa 2"});

//     ufpr::Ementa ementaDis{"Ementa Dis"};
//     ufpr::Disciplina disciplina{"C++"};
//     disciplina.setEmenta(ementaDis);

//     ementaDis = ufpr::Ementa{"Outra Ementa"};

//     std::list<ufpr::Ementa>::const_iterator it{ementas.begin()};
//     for( ; it != ementas.end(); ++it)
//         std::cout << it->getDescricao() << '\n';

//    return 0;
// }