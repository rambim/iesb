#include <stdio.h>
#include <stdlib.h>


int main()
{
    
    FILE * arq;
    int x = 10;

    arq = fopen("arquivo_teste_da_aula.txt","a");

    if (arq==NULL)
    {
        printf("\n Erro na abertura do arquivo");
    }
    else
    {
        fprintf(arq,"Hello World %d\n",x);
        fclose(arq);
    }

    

    printf("\n");
    return 0;
}
