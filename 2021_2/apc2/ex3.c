#include  <stdio.h>
#include <stdlib.h>


int main()
{
    int tipo_cliente;
    printf("\n");

    if (tipo_cliente == 1 || tipo_cliente == 2)
    {
        printf("\n Esse tipo de cliente nao pode acessar o menu privado");
    }
    else
    {
        printf("\n ACESSO LIBERADO");
    }
    
    return 0;
}


/*
1 - cliente simples
2 - cliente plus
3 - administradores
4 - diretores
5 - cliente renda alta
*/


