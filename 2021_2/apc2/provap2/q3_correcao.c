// Faça um programa que receba do usuário um texto de até 300 caracteres composto apenas por
// vogais e diga se é uma sentença "dançante" ou não. Uma texto é considerado dançante se cada
// letra desse texto intercalar entre maiúscula e minúscula, ou seja, se sua primeira letra for
// maiúscula e cada letra subsequente for o oposto da letra anterior. Espaços devem ser ignorados.
// Ex: "A e Ai" é uma sentença dançante porque a primeira letra ('A') é maiúscula, a próxima letra ('e')
// é minúscula, a próxima letra ('A') é maiúscula, e a próxima letra ('i') é minúscula.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int vogal(char a);
int vogal_minuscula(char a);
int vogal_maiscula(char a);

int main()
{

    char texto[300];
    int i;
    int erro = 0;

    int valida_maiuscula = -33;

    printf("\n Digite o texto: ");
    __fpurge(stdin);
    fgets(texto, 300, stdin);
    texto[strlen(texto) - 1] = '\0';

    printf("\n Texto lido: %s", texto);

    for (i = 0; i < strlen(texto); i++)
    {
        if (texto[i] != ' ')
        {
            if (valida_maiuscula == -33)
            {
                if (vogal_maiscula(texto[i]))
                    valida_maiuscula = 0;
                else
                    valida_maiuscula = 1;
            }
            else
            {
                if (valida_maiuscula == 1)
                {
                    if (vogal_maiscula(texto[i]))
                        valida_maiuscula = 0;
                    else
                        erro = 1;
                }
                else
                {
                    if (vogal_minuscula(texto[i]))
                        valida_maiuscula = 1;
                    else
                        erro = 1;
                }
            }
        }
    }

    if(erro==1)
    {
        printf("\n palavra nao e dancante");
    }
    else
    {
        printf("\n palavra dancante");
    }
    printf("\n");
    return 0;
}

int vogal_minuscula(char a)
{
    char vogais[] = "aeiou";

    int i;

    for (i = 0; i < strlen(vogais); i++)
    {
        if (a == vogais[i])
            return 1;
    }

    return 0;
}

int vogal_maiscula(char a)
{
    char vogais[300] = "AEIOU";

    int i;

    for (i = 0; i < strlen(vogais); i++)
    {
        if (a == vogais[i])
            return 1;
    }

    return 0;
}