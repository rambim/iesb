#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *arq;

    char linha[100];
    int esta_no_arquivo=0;

    arq = fopen("alunosdesesperados.txt", "r");

    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {

        while(fgets(linha,100,arq)!=NULL)
        {
            linha[strlen(linha)-1] = '\0';
            if (strcmp(linha,"Gustavo Passos")==0)
            {
                esta_no_arquivo=1;
            }
        }
        fclose(arq);

        if (esta_no_arquivo)
        {
            printf("Tem gustavo passos no arquivo");
        }
        else
        {
            printf("nao tem gustavo passos no arquivo");;
        }
        
    }
}