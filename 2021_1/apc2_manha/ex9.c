#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//strlen() : retorna quantos caracteres estão preenchidos até o \0;
//gets: serve pra ler string
//fgets: serve pra ler string especificando tamanho e origem da informação
//getc: serve para ler caracteres
//fgetc: serve para ler caracteres especificado a  origem da informação
int main()
{
    // int vet[10];
    // int i;
    // for(i=0;i<10;i++)
    // {
    //     scanf("%d",&vet[i]);
    // }

    char vet2[10];

    printf("\n Ex GETS: Digite seu nome: ");
    gets(vet2);
    // gets(&vet2[0]);

    printf("\nTexto lido : %s",vet2);

    printf("\n Ex FGETS: Digite seu nome: ");
    fgets(vet2,10,stdin);
    printf("\nTexto lido : %s",vet2);


}