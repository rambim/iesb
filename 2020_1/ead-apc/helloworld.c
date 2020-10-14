#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int valor;
    struct lista * ant;
    struct lista * prox;

}lista;



int main()
{

    int x;

    x = 3;

    printf("%d",x);

    x = "felippe";
    printf("%d",x);
    
}