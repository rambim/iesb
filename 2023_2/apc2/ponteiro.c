#include <stdio.h>
#include <stdlib.h>


// typedef struct contato
// {
//     long long int telefone;
//     char nome[50];
// }contato;

int main()
{
    int x,y;
    int *ptr;


    printf("\n Endereco de X: %d",&x);
    printf("\n Endereco de X: %d",&y);

    ptr = malloc(4);

    *ptr = 2;
    printf("\n Conteudo de ptr : %d",ptr);

        return 0;
}