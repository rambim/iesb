#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int main()
{
    char nome[3][30];
    int i;

    for(i=0;i<3;i++)
    {
        printf("\n Digite o %d nome: ",i+1);
        __fpurge(stdin);
        fgets(nome[i],28,stdin);
        nome[i][strlen(nome[i])-1] = '\0';
    }
    for(i=0;i<3;i++)
    {
        printf("\nNome %d = %s",i+1,nome[i]);
    }

    printf("\n");
    return 0;
}