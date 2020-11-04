#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    char nome[50];
    int idade;
    float n1,n2,media;


}aluno;

int main()
{
    int x;

    int tamanho_de_x;
    int tamanho_de_inteiro;
    int tamanho_de_aluno;

    tamanho_de_x = sizeof(x);
    tamanho_de_inteiro = sizeof(int);
    tamanho_de_aluno = sizeof(aluno);

    printf("\n O tamanho de x e          : %d ",tamanho_de_x);
    printf("\n O tamanho de um inteiro  e: %d ", tamanho_de_inteiro);
    printf("\n O tamanho de um aluno e de: %d ",tamanho_de_aluno);

    return 0;

    
}


/*

    sizeof() = Retornar o tamanho em bytes de alguma estrutura.

*/