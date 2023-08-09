/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 07/08/2023 21h50
*/
#include "Pessoa.hpp"

uint64_t Pessoa::getCpf() { return cpf; }
void Pessoa::setCpf(uint64_t novoCpf) {
    if (validarCPF(novoCpf)) {
        cpf = novoCpf;
        return;
    }
    cpf = 0;
    return;
}

std::string Pessoa::getNome() { return nome; }
void Pessoa::setNome(std::string novoNome) { nome = novoNome; }

unsigned short Pessoa::getIdade() { return idade; }
void Pessoa::setIdade(unsigned short novaIdade) {
    if (novaIdade < 120)
        idade = (uint8_t)novaIdade;
    else
        idade = 0;
}

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

Pessoa Pessoa::cadastrar() {
    std::cout << "Digite um nome \t: ";
    std::cin >> nome;

    int novaIdade;
    std::cout << "Digite a idade \t: ";
    std::cin >> novaIdade;
    idade = novaIdade;  // ler docs, como contornar

    bool valido = false;
    while (!valido) {
        std::cout << "Digite o cpf \t: ";
        std::cin >> cpf;
        valido = validarCPF(cpf);

        if (!valido) {
            printf("CPF inválido!\n");
        }
    }

    std::cout << "Cadastro completo!\n"
              << "Dados da pessoa: " << nome << "\t" << idade << "\t" << cpf
              << '\n';

    return *this;
}

Pessoa Pessoa::cadastrar(const char* nome, uint8_t idade, uint64_t cpf) {
    // while (!validarCPF(cpf)) {
    //     // throw std::runtime_error("Cpf cadastrado inválido!\n");
    //     std::cerr << "Cpf " << cpf << " inválido, tente novamente : ";
    //     std::cin >> cpf;
    // }

    setIdade(idade);
    setNome(nome);
    setCpf(cpf);

    return *this;
}

void Pessoa::show() {
    std::cout << "------------------------------\n";
    std::cout << "Nome : \t" << getNome() << '\n';
    std::cout << "Idade: \t" << getIdade() << '\n';
    std::cout << "CPF  : \t" << getCpf() << '\n';
}