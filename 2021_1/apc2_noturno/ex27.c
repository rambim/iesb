#include <stdio.h>
#include <stdlib.h>

typedef struct contato
{
    char l;
    int idade;
    int idade2;
    char l2;
}contato;

int main()
{
    int tamanho_em_bytes;

    tamanho_em_bytes = sizeof(int);
    printf("\n O tamanho de um inteiro em bytes = %d",tamanho_em_bytes);
    tamanho_em_bytes = sizeof(float);
    printf("\n O tamanho de um float em bytes = %d",tamanho_em_bytes);
    tamanho_em_bytes = sizeof(char);
    printf("\n O tamanho de um char em bytes = %d",tamanho_em_bytes);
    tamanho_em_bytes = sizeof(contato);
    printf("\n O tamanho de um contato em bytes = %d",tamanho_em_bytes);
    printf("\n");
    return 0;
}