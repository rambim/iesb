#include  <stdio.h>
#include <stdio_ext.h>
#include  <stdlib.h>
#include  <string.h>


int main()
{
    char letra;
    char nome_completo[100];
    int i;
    int qtd;
    letra = 'a';
    // printf("\n Digite a letra: ");
    // scanf("%c",&letra);
    printf("\n");

    printf("\n Digite seu nome: ");

    // fflush(stdin); WINDOWS
    __fpurge(stdin); // linux bib: #include <stdio_ext.h>
    // gets(nome_completo);
    fgets(nome_completo,100,stdin);

    printf("\n Mostrando nome lido: ");

/*
    for(i=0;i<strlen(nome_completo);i++)
    {
        printf("\n Letra -> %c",nome_completo[i]);
    }
*/
    //printf("String: %s",nome_completo);]
    puts(nome_completo);

    qtd = strlen(nome_completo);
    printf("\nRetorno da strlen = %d",qtd);
    printf("\n");
    return 0;   
}