/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 07/08/2023 21h50
*/
#include "Pessoa.hpp"

bool Pessoa::validarCPF(uint64_t cpfTeste) {
    uint8_t verificador2{(uint8_t)(cpfTeste % 10)};
    cpfTeste /= 10;

    uint8_t verificador1{(uint8_t)(cpfTeste % 10)};
    cpfTeste /= 10;

    uint8_t soma1{0};
    uint8_t soma2{0};

    uint32_t cpf1{(uint32_t)cpfTeste};
    uint32_t cpf2{(uint32_t)(cpfTeste * 10)};

    uint8_t mult{2};
    while (cpf1 > 0) {
        soma1 += (cpf1 % 10) * mult++;
        cpf1 /= 10;
    }
    uint8_t resto1{(uint8_t)(soma1 % 11 > 2 ? 11 - (soma1 % 11) : soma1 % 11)};
    cpf2 += resto1;

    mult = 2;
    while (cpf2 > 0) {
        soma2 += (cpf2 % 10) * mult++;
        cpf2 /= 10;
    }
    uint8_t resto2{(uint8_t)(soma2 % 11 > 2 ? 11 - (soma2 % 11) : soma2 % 11)};

    return verificador1 == resto1 && verificador2 == resto2;
}

Pessoa Pessoa::cadastrar(Pessoa* p) {
    std::cout << "Digite um nome \t: ";
    std::cin >> p->nome;

    int idade;
    std::cout << "Digite a idade \t: ";
    std::cin >> idade;
    p->idade = idade;  // ler docs, como contornar

    bool valido = false;
    while (!valido) {
        std::cout << "Digite o cpf \t: ";
        std::cin >> p->cpf;
        valido = validarCPF(p->cpf);

        if (!valido) {
            printf("CPF inválido!\n");
        }
    }

    std::cout << "Cadastro completo!\n"
              << "Dados da pessoa: " << p->nome << "\t"
              << (unsigned short int)p->idade << "\t" << p->cpf << '\n';

    return *p;
}

Pessoa Pessoa::cadastrar(const char* nome, uint8_t idade, uint64_t cpf) {
    while (!validarCPF(cpf)) {
        // throw std::runtime_error("Cpf cadastrado inválido!\n");
        std::cerr << "Cpf " << cpf << " inválido, tente novamente : ";
        std::cin >> cpf;
    }

    this->cpf = cpf;
    strncpy(this->nome, nome, sizeof(this->nome) - 1);
    this->idade = (int)idade;

    return *this;
}

void Pessoa::show() {
    std::cout << "------------------------------\n";
    std::cout << "Nome : \t" << nome << '\n';
    std::cout << "Idade: \t" << static_cast<int>(idade) << '\n';
    std::cout << "CPF  : \t" << cpf << '\n';
}