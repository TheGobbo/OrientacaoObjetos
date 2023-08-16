/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 13/08/2023 21h50
*/
#include "Pessoa.hpp"

Pessoa::Pessoa() : nome{"[ ]"}, idade{101}, cpf{101} {}

Pessoa::Pessoa(std::string novoNome) : nome{novoNome} {}

Pessoa::Pessoa(std::string novoNome, uint8_t novaIdade, uint64_t novoCpf)
    : Pessoa{novoNome}  // nao da pra fazer isso junto -> , idade{novaIdade}
{
    setIdade(novaIdade);
    setCpf(novoCpf);
}

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

void Pessoa::setNome(std::string novoNome) {
    if (novoNome.length() > 100) {
        novoNome = novoNome.substr(0, 100);
    }
    nome = novoNome;
}

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
