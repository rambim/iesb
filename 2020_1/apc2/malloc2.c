#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    long int idade;
    char nome[10];
    float salario;
} funcionario;

int main()
{
    funcionario *x;

    // forma 1
    int tamanho;
    tamanho = sizeof(funcionario);
    x = malloc(tamanho);
    (*x).idade = 20;
    printf("\n idade do funcionario = %ld", x->idade);

    // forma 2
    x = malloc(sizeof(funcionario));
    x->idade = 20;
    printf("\n idade do funcionario = %ld", x->idade);

    return 0;
}