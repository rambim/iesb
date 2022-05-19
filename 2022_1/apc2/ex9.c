#include <stdio.h>
#include <stdlib.h>

typedef struct arquivo
{
    int idade;
    float peso;
}arquivo;


int main()
{

    arquivo a;
    arquivo *b;


    a.idade = 10;
    b = &a;

    (*b).idade
 
    arquivo * x;

    x = malloc(sizeof(arquivo));

    x->idade = 10;
    x->peso = 1.5;

    printf("\n dentro de *x tem = %d",*x);
    printf("\n");
    return 0;
}