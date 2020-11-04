#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * x;
    int * y;

    x = malloc(4);

    *x = 2; 

    y = malloc(12);

    y[0] = 1;
    y[1] = 2;
    y[2] = 3;


    return 0;


}


/*

malloc() : recebe por parâmetro a quantidade de memória que será alocada e retorna o endereço de 
onde foi alocado

*/