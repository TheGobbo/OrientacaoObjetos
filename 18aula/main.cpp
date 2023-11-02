#include <iostream>
#include <string>

#include "CPF.hpp"
#include "Pessoa.hpp"

int main() {
    ufpr::CPF cpf1{11111111111};
    ufpr::CPF cpf2{11111111111};
    ufpr::CPF cpf3{10729451933};

    if (cpf1 == cpf2)
        std::cout << "Igual\n";
    else
        std::cout << "Diferente\n";

    if (cpf1 != cpf2)
        std::cout << "Nao Igual\n";
    else
        std::cout << "Nao Diferente\n";

    if (cpf1 <= cpf3)
        std::cout << "cpf1 <= cpf3\n";
    else
        std::cout << "NAO cpf1 <= cpf3\n";

    if (cpf1 > cpf3)
        std::cout << "CPF1 > CPF3\n";
    else
        std::cout << "NAO CPF1 > CPF3\n";

    cpf1 = cpf2 = 55555555555;

    std::cout << cpf1 << '\n' << cpf2 << '\n' << cpf3 << '\n';

    // std::cout << "Digite um cpf: ";
    // std::cin >> cpf1;

    std::cout << "Vc digitou: " << cpf1 << '\n';
    short idx = 2;
    std::cout << idx << "th digito de " << cpf3 << " eh " << cpf3[idx] << '\n';

    ufpr::Pessoa p1{"Pessoa1", cpf2, 13};
    ufpr::Pessoa p2{"Pessoa2", cpf2, 13};

    std::cout << p1.getNome() << " e " << p2.getNome() << " sao ";
    std::cout << ((p1 == p2) ? "Iguais" : "Diferentes") << '\n';

    std::cout << "get cpf(3, 3): " << cpf3(3, 3) << '\n';
    std::cout << "get cpf(8, 3): " << cpf3(8, 3) << '\n';

    return 0;
}