#include <stdio.h>
#include <stdlib.h>


int main()
{

    
    int *y;

    int tamanho_inteiro;

    tamanho_inteiro = sizeof(int);

    y = malloc(tamanho_inteiro);

    *y = 2;

    printf("\n Conteudo apontado por *y = %d",*y);
    printf("\n");
    return 0;
}