#include <stdio.h>
#include <stdlib.h>


int main()
{

    
    int *y;
    int tamanho_do_vetor;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d",&tamanho_do_vetor);

    y = malloc(sizeof(int)*tamanho_do_vetor);

    y[0] = 1;
    y[1] = 2;

    

    printf("\n Conteudo apontado por *y = %d",*y);
    printf("\n Conteudo apontado por *y = %d",*(y+1));
    printf("\n");
    return 0;
}