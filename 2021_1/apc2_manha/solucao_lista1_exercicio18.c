#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

void substituir(char *texto, char l1, char l2);
int main()
{
    char texto[100];
    char l1,l2;

    printf("\n Digite o texto: ");
    __fpurge(stdin);
    fgets(texto,98,stdin);
    texto[strlen(texto)-1] = '\0';

    printf("\n Digite L1: ");
    __fpurge(stdin);
    scanf("%c",&l1);

    printf("\n Digite L2: ");
    __fpurge(stdin);
    scanf("%c",&l2);

    substituir(texto,l1,l2);

    printf("\n Texto depois da substituicao: %s",texto);
   

    printf("\n");
    return 0;
}

void substituir(char *texto, char l1, char l2)
{
    int i;

    for (i = 0; i < strlen(texto); i++)
    {
        if (texto[i] == l1)
            texto[i] = l2;
    }
}
