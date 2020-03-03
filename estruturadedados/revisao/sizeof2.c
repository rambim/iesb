#include <stdio.h>
#include <stdlib.h>

typedef struct registro1
{
    char a;
    int b;
    char c;
}registro1;

typedef struct registro2
{
    int a;
    char b;
    char c;
}registro2;


int main()
{
    int tamanho1,tamanho2;
    registro1 r1;
    registro2 r2;

    tamanho1 = sizeof(registro1);
    tamanho2 = sizeof(registro2);

    printf("\n Tamanho Registro 1= %d",tamanho1);
    printf("\n Tamanho registro 2 = %d",tamanho2);
    printf("\n");
    
    return 0;
}