#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main()
{
    int x;
    char nome[30];
    printf("\n Digite o valor de X: ");
    scanf("%d",&x);
    printf("\n digite seu nome: ");
    // fflush(stdin); windows
    __fpurge(stdin); // linux
    gets(nome);
    printf("\n");
    return 0;
}