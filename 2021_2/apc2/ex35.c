#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct registro
{
    int valor;
    char nome[50];
    int idade;
}registro;

void preenche_registro ( registro * r);
void mostrar_registro( registro r);

int main()
{

    srand(time(NULL));

    registro * registros, *registros2;

    registros = (registro*)calloc(10,sizeof(registro));
    registros2 = (registro*)calloc(10,sizeof(registro));
    

    int i;

    for(i=0;i<10;i++)
    {
        preenche_registro(&registros[i]);
        // mostrar_registro(registros[i]);
    }

    FILE * arq;

    arq = fopen("teste2.bin","wb");

    if (arq==NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        fwrite(registros,sizeof(registro),10,arq);
        fclose(arq);
    }

    arq = fopen("teste2.bin","rb");

    if ( arq==NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        fread (registros2,sizeof(registro),10,arq);
    }


    printf("\n Mostrando conteudo de Registros 2: \n\n");

    registros2[0].idade = 10;
    for(i=0;i<10;i++)
    {
        mostrar_registro(registros2[i]);
    }


    printf("\n");
    return 0;
}

void preenche_registro ( registro * r)
{
    r->idade = rand() % 80;
    strcpy(r->nome,"Felippe");
    r->valor = rand() % 10;
}

void mostrar_registro( registro r)
{
    printf("\n Nome: %s",r.nome);
    printf("\n Idade: %d",r.idade);
    printf("\n Valor: %d",r.valor);
}