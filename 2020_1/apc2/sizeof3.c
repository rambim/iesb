#include <stdio.h>
#include <stdlib.h>

typedef struct registro1
{
    char a;
    int b;
    char c;
    int d;
}registro1;

typedef struct registro2
{
    char a;
    char c;
    int b;
    int d;
}registro2;

int main()
{
    int tamanho;
    registro1 r1;
    registro2 r2;

    tamanho = sizeof(r1);
    printf("\n O tamanho de r1 = %d bytes",tamanho);
    
    tamanho = sizeof(r2);
    printf("\n O tamanho de r2 = %d bytes",tamanho);

    printf("\n");
    return 0;

}