#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct teste
{
    char nome[30];
    long int matricula;
    float media;
}teste;


int main()
{
    
    FILE *arq;

    teste a,b;

    strcpy(a.nome,"Felippe");
    a.matricula = 123;
    a.media = 10;

    arq = fopen("teste1.txt", "w");

    fwrite(&a,sizeof(teste),1,arq);

    fclose(arq);

    arq = fopen("teste1.txt", "r");

    fread(&b,sizeof(teste),1,arq);

    printf("\n Nome: %s",b.nome);
    printf("\n matricula: %ld",b.matricula);
    printf("\n media    : %f",b.media);


    return 0;

}