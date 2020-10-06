/*

Faça um rotina que remova um caracter de uma string do tipo char Str[100], dada a posição do caracter.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

void remover_caracter(char * texto, int tam_texto, int posicao);

int main()
{
    char texto[30];
    int posicao;
    printf("\nDigite o texto: ");
    __fpurge(stdin);
    fgets(texto,30,stdin);
    texto[strlen(texto)-1] = '\0';

    printf("\nQual posicao do texto deseja remover? ");
    scanf("%d",&posicao);

    remover_caracter(texto,strlen(texto),posicao);

    printf("\nTexto final: %s",texto);

    printf("\n");

    

    return 0;
}

void remover_caracter(char * texto, int tam_texto, int posicao)
{
    int i;
    for(i=posicao;i<tam_texto-1;i++)
    {
        texto[i] = texto[i+1];
    }
    
}
