#include <stdio.h>
#include <stdlib.h>


int main()
{

    FILE * arq;
    int x;

    arq = fopen("arquivo_teste_da_aula.txt","r");

    if ( arq== NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        fscanf(arq,"Hello World %d\n",&x);
        printf("\n numero que estava dentro do arquivo: %d",x);
        fclose(arq);
    }
    printf("\n");
    return 0;
}