// Autor : Eduardo Gobbo Willi Vasconcellos Goncalves
// ultima modificacao : 03/08/2023
// UFPR - Orientacao a Objetos
// Exercicio semana 1

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

struct pessoa {
    char nome[201];
    uint8_t idade;  // 256 anos no maximo
    uint64_t cpf;   // cabem 19 digitos
};

bool validarCPF(uint64_t cpf) {
    uint8_t verificador2 = cpf % 10;
    cpf /= 10;

    uint8_t verificador1 = cpf % 10;
    cpf /= 10;

    uint8_t soma1 = 0;
    uint8_t soma2 = 0;

    uint32_t cpf1 = cpf;
    uint32_t cpf2 = cpf * 10;

    uint8_t mult = 2;
    while (cpf1 > 0) {
        soma1 += (cpf1 % 10) * mult++;
        cpf1 /= 10;
    }
    uint8_t resto1 = soma1 % 11 > 2 ? 11 - (soma1 % 11) : soma1 % 11;
    cpf2 += resto1;

    mult = 2;
    while (cpf2 > 0) {
        soma2 += (cpf2 % 10) * mult++;
        cpf2 /= 10;
    }
    uint8_t resto2 = soma2 % 11 > 2 ? 11 - (soma2 % 11) : soma2 % 11;

    // printf("resto1 : %u\n", resto1);
    // printf("verif1 : %u\n", verificador1);
    // printf("resto2 : %u\n", resto2);
    // printf("verif2 : %u\n", verificador2);

    return verificador1 == resto1 && verificador2 == resto2;
}

void cadastrar(struct pessoa* p) {
    printf("Digite um nome \t: ");
    scanf("%200s", p->nome);

    printf("Digite a idade \t: ");
    scanf("%hhd", &p->idade);

    bool valido = false;
    uint64_t cpf;

    while (!valido) {
        printf("Digite o cpf \t: ");
        scanf("%lu", &cpf);
        valido = validarCPF(cpf);

        if (!valido) {
            printf("CPF inválido!\n");
        } else {
            p->cpf = cpf;
        }
    }

    printf("Cadastro completo!\n");
}

int main() {
    struct pessoa cadastros[3];

    for (int i = 0; i < 3; i++) {
        cadastrar(&cadastros[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("Nome : %s\n", cadastros[i].nome);
        printf("\tIdade: %i\n", cadastros[i].idade);
        printf("\tCPF  : %li\n", cadastros[i].cpf);
        printf("------------------------------\n");
    }
    return 0;
}
