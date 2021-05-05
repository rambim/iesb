#include <stdio.h>
#include <stdlib.h>


typedef struct pessoa
{
    int idade;
    char letraa;
    int matricula;
    char letrab;
}pessoa;

int main()
{
    int tamanho;

    tamanho = sizeof(int);
    printf("\n O tamanho em bytes de um inteiro = %d",tamanho);
    tamanho = sizeof(float);
    printf("\n O tamanho em bytes de um float = %d",tamanho);
    tamanho = sizeof(char);
    printf("\n O tamanho em bytes de um char = %d",tamanho);
    tamanho = sizeof(double);
    printf("\n O tamanho em bytes de um double = %d",tamanho);
    tamanho = sizeof(long int);
    printf("\n O tamanho em bytes de um inteiro longo = %d",tamanho);
    tamanho = sizeof(long long int);
    printf("\n O tamanho em bytes de um inteiro longo longo = %d",tamanho);
    tamanho = sizeof(pessoa);
    printf("\n O tamanho em bytes de uma pessoa = %d",tamanho);
    printf("\n");
    return 0;
}