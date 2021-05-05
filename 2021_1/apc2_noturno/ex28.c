#include <stdio.h>
#include <stdlib.h>


typedef struct registro
{
    int x;
    double y;
    char nome[52];
    float media;
    float peso;
    long long int matricula;
}registro;

int main()
{

    int *x;
    char *l;
    registro * ptr;


    x = malloc(4);
    l = malloc(1);
    ptr = (registro*)malloc(sizeof(registro));

    *x = 2;

    printf("\n Valores de ponteiro X = %d",*x);
    free(x);
    free(l);

    printf("\n");
    return 0;
}