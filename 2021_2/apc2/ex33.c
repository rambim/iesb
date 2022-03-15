#include <stdio.h>
#include <stdlib.h>

int main()
{


    FILE * arq;

    arq = fopen("/home/rambim/pessoal/iesb/teste_de_arquivo/teste.txt","w");
    // arq = fopen("C:/Users/W1nd0w5-10/OneDrive/Desktop/arquivoteste2.txt","w");

    if ( arq == NULL)
    {
        printf("\n Problemas na criação do arquivo");
    }
    else
    {
        fprintf(arq,"\n Arquivo de teste");
        fclose(arq);
    }



    printf("\n");
    return 0;
}