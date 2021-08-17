// alocação dinâmica
// ponteiros
// arquivos
// struct
// função
// função com passagem de parâmetro por referência ( usando ponteiros )


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    x = 2;

    int *y;
    y = &x;

    printf("\n Conteudo de  X: %d",x);
    printf("\n Endereco de  X: %d",&x);
    printf("\n Conteudo de  Y: %d",y);
    printf("\n Endereco de  Y: %d",&y);
    printf("\n Apontado por Y: %d",*y);


    printf("\n");
    return 0;
}

