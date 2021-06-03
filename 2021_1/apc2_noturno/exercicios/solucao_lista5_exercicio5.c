// 5) Faça um programa que receba dois arquivos do usuario, e crie um terceiro arquivo com 
// o conteudo dos dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do segundo)


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

int  copia_arquivo(char * origem, char * destino);

int main()
{
    char arquivo1[50],arquivo2[50];

    FILE * leitura, *escrita;

    printf("\nDigite o nome do primeiro arquivo: ");
    __fpurge(stdin);
    fgets(arquivo1,40,stdin);
    arquivo1[strlen(arquivo1)-1] = '\0';

    copia_arquivo(arquivo1,"saida2.txt");

    printf("\nDigite o nome do segundo arquivo: ");
    __fpurge(stdin);
    fgets(arquivo2,40,stdin);
    arquivo2[strlen(arquivo2)-1] = '\0';

    copia_arquivo(arquivo2,"saida2.txt");

    printf("\n");
    return 0;
}


// 1 = Copia realizada com sucesso;
// 0 = problema na cópia
int  copia_arquivo(char * origem, char * destino)
{
    FILE * arquivo_origem, *arquivo_destino;
    char linha[999];

    arquivo_origem = fopen(origem,"r");
    arquivo_destino = fopen(destino,"a");

    if (arquivo_origem == NULL || arquivo_destino == NULL)
    {
        return 0;
    }
    else
    {
        while(fgets(linha,995,arquivo_origem)!=NULL)
        {
            fprintf(arquivo_destino,"%s",linha);
        }
        fprintf(arquivo_destino,"\n");

        fclose(arquivo_origem);
        fclose(arquivo_destino);
    }
    return 1;
}


