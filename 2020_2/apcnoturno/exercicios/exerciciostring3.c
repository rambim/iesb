/*

3) Faça um programa que diga a quantidade de digitos 1 que aparecem em uma string:
Ex: "0011001" -> 3

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char texto[50];
    int numero;

    int i;
    int count=0;
    

    printf("\nDigite uma sequencia de 0 e 1: ");
    fgets(texto,50,stdin);
    texto[strlen(texto)-1] = '\0';
    
    printf("\nNumero: %d",numero);



    for(i=0;i<strlen(texto);i++)
    {
        if (texto[i] == '1')
        {
            count++;
        }
    }

    printf("\n Existem %d valores 1",count);

    printf("\n");
    return 0;
}
