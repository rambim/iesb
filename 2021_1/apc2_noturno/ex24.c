#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>


int main()
{
    char nome_do_arquivo[30];

    printf("\n Digite o nome do arquivo: ");
    __fpurge(stdin);
    fgets(nome_do_arquivo,28,stdin);
    nome_do_arquivo[strlen(nome_do_arquivo)-1] = '\0';


    // nome_do_arquivo[strlen(nome_do_arquivo)] = '.';
    // nome_do_arquivo[strlen(nome_do_arquivo)+1] = 't';
    // nome_do_arquivo[strlen(nome_do_arquivo)+2] = 'x';
    // nome_do_arquivo[strlen(nome_do_arquivo)+3] = 't';
    // nome_do_arquivo[strlen(nome_do_arquivo)+4] = '\0';

    strcat(nome_do_arquivo,".txt");
    
    printf("\n Nome do arquivo: %s",nome_do_arquivo);

    return 0;
}