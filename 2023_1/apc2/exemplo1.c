#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Pessoa
struct Pessoa {
    char nome[50];
    int idade;
};

// Função para preencher os dados de uma pessoa passando a estrutura por valor
void preencherPessoaVal(struct Pessoa pessoa, char *nome, int idade) {
    strcpy(pessoa->nome, nome);
    pessoa->idade = idade;
}

// Função para imprimir os dados de uma pessoa passando a estrutura por referência
void imprimirPessoaRef(struct Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
}

int main() {
    // Alocando a estrutura dinamicamente usando malloc
    struct Pessoa *pessoa1;
    pessoa1 = malloc(sizeof(struct Pessoa));
    preencherPessoaRef(pessoa1, "João", 20);
    imprimirPessoaRef(pessoa1);

    // Alocando a estrutura estaticamente
    struct Pessoa pessoa2;
    preencherPessoaVal(pessoa2, "Maria", 22);
    imprimirPessoaRef(&pessoa2);

    // Liberando a memória alocada com malloc
    free(pessoa1);

    return 0;
}
