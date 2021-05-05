#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{
    int idade;
    char nome[50];
    int matricula;
    float peso;
}pessoa;

int main()
{
    int *x;

    
    x = malloc(4);

    *x = 10;

    printf("\n Numero armazenado = %d",*x);

    x = malloc(12);

    x[0] = 2;
    x[1] = 3;
    x[2] = 4;

    x = (int*)malloc(12);

    x[0] = 2;
    x[1] = 3;
    x[2] = 4;


    pessoa * vet_pessoas;
    
    vet_pessoas = (pessoa*)malloc(sizeof(pessoa)*10);

    vet_pessoas[2].idade = 10;
    free(vet_pessoas);

    return 0;

}