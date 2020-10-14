#include <stdio.h>
#include <stdlib.h>

typedef struct registro
{
    int a;
    int b;
    char c;
    char d;
    char e;
    char f;
    // char g;
}registro;

int main()
{
    int tamanho;
    registro reg1;

    tamanho = sizeof(reg1.a);
    printf("\n O tamanho de reg1.a = %d bytes",tamanho);

    tamanho = sizeof(reg1.b);
    printf("\n O tamanho de reg1.b = %d bytes",tamanho);
    
    tamanho = sizeof(reg1.c);
    printf("\n O tamanho de reg1.c = %d bytes",tamanho);

    tamanho = sizeof(registro);
    printf("\n O tamanho de um registro = %d bytes",tamanho);

    tamanho = sizeof(reg1);
    printf("\n O tamanho de reg1 = %d bytes",tamanho);


    printf("\n");

    return 0;
}