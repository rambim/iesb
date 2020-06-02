#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    char nome1[30];
    char nome2[30];

    printf("DIgite o primeiro nome: ");
    __fpurge(stdin); // fflush(stdin);
    fgets(nome1,30,stdin);
    printf("DIgite o segundo nome: ");
    __fpurge(stdin);
    fgets(nome2,30,stdin);


    int retorno;

    retorno = strcmp(nome1,nome2);

    if (retorno ==0)
    {
        printf("\nNomes iguais");
    }
    else
    {
        if (retorno <0)
        {
           printf("%s",nome1);
           printf("%s",nome2);
        }
        else
        {
           printf("%s",nome2);
           printf("%s",nome1);
           
        }
        
    }
    

    return 0;
}