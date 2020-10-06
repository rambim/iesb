#include <stdio.h>

__global__ void funcao1(int x) // global simboliza que essa função é uma Kernel ou seja
{                          // uma função que será executada por todas as threads de cada bloco 
                           // do grid da GPU é obrigatório o retorno VOID.
    
}

int main()
{
    int * x, * y
    funcao1<<<2,16>>>(x);

    printf("Hello world\n");
    return 0;
}