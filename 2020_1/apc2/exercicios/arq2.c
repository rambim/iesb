#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

/*

Faça um programa que leia o nome do usuário, crie um arquivo com o mesmo
nome do usuário e armazene dentro desse arquivo
a quantidade de vogais e de consoantes do nome do usuario:

Ex:

Nome do usuario: felippe
arquivo a ser criado: felippe.txt
conteudo do arquivo: 

consoantes: 4
vogais: 3
*/

int * verifica_vogal_consoante( char * texto, int tam);

int main()
{
    char nome[50];
    char nome_do_arquivo[60];
    int * retorno;

    FILE * arq;

    printf("\n DIgite seu nome: ");
    __fpurge(stdin);
    fgets(nome,50,stdin);
    nome[strlen(nome)-1]= '\0';

    printf("\n Nome lido: %s",nome);
    strcpy(nome_do_arquivo,nome);
    strcat(nome_do_arquivo,".txt");

    printf("\n Nome do arquivo: %s",nome_do_arquivo);

    arq = fopen(nome_do_arquivo,"w");

    if (arq==NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        retorno = verifica_vogal_consoante(nome,strlen(nome));
        fprintf(arq,"Consoantes: %d\n",retorno[1]);
        fprintf(arq,"Vogais: %d\n",retorno[0]);
        fclose(arq);
    }
    

    printf("\n");

    return 0;
}

/* retorna um vetor de 2 posicoes com
[0] = quantidade de vogais
[1] = quantidade de consoantes
*/


int * verifica_vogal_consoante( char * texto, int tam)
{
    int i;
    int * retorno;

    retorno = (int*)malloc(sizeof(int)*2);
    retorno[0] =0;
    retorno[1] =0;

    for(i=0;i<tam;i++)
    {
        if ((texto[i] == 'a') || (texto[i] == 'A') ||
        (texto[i] == 'e') || (texto[i] == 'E') ||
        (texto[i] == 'i') || (texto[i] == 'I') ||
        (texto[i] == 'o') || (texto[i] == 'O') ||
        (texto[i] == 'u') || (texto[i] == 'U'))
        {
            retorno[0]++;
        }

    }
    retorno[1] = tam - retorno[0];

    return retorno;
    
}

