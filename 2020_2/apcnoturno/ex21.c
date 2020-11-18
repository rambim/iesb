

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct pessoa
{
    char nome[30];
    int idade;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;

}pessoa;



int main()
{

    FILE * arq;
    pessoa p,q;
    char nome_do_arquivo[50];

    printf("\n Digite o nome da pessoa: ");
    __fpurge(stdin);
    fgets(p.nome,30,stdin);
    p.nome[strlen(p.nome)-1] = '\0';

    printf("\n Digite a idade da pessoa: ");
    scanf("%d",&p.idade);

    // printf("\n Qual o nome do arquivo deseja?");
    // __fpurge(stdin);
    // fgets(nome_do_arquivo,50,stdin);
    // strcat(nome_do_arquivo,".txt");


    arq = fopen("teste123.txt","w");

    if (arq==NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    
    }
    else
    {
        fprintf(arq,"Nome da pessoa: %s Idade da pessoa: %d\n",p.nome,p.idade);

        // fwrite(&p,sizeof(p),1,arq);
        fclose(arq);

        
    }

    arq = fopen("teste123.txt","r");

    if ( arq==NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        // fread(&q,sizeof(p),1,arq);
        fscanf(arq,"Nome da pessoa: %s Idade da pessoa: %d\n",q.nome,&q.idade);
        printf("\n Pessoa Q -> Nome: %s Idade %d",q.nome,q.idade);
        fclose(arq);
    }



    

    return 0;

}