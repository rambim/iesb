#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int procura(char *texto, int tam_texto, char *procurado, int tam_procurado);
int compara_strings(char *texto, char *procurado, int tam);
int main()
{

    int i, j;
    int qtd_testes;
    int qtd_subs;
    char texto[100000];
    char procurado[100000];
    int retorno;

    scanf("%d", &qtd_testes);

    for (i = 0; i < qtd_testes; i++)
    {
        
        scanf("%s",texto);
        scanf("%d", &qtd_subs);

        for (j = 0; j < qtd_subs; j++)
        {
            scanf("%s",procurado);
            retorno = procura(texto, strlen(texto), procurado, strlen(procurado));

            if (retorno == 1)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
}

int procura(char *texto, int tam_texto, char *procurado, int tam_procurado)
{
    int i;
    int j;
    int achou = 0;

//solução 1 - sem necessidade de ser junta

    j = 0;
    for (i = 0; i < tam_texto; i++)
    {
     
        if (texto[i] == procurado[j])
        {

            j++;
            if (j == tam_procurado)
                return 1;
        }
    }



//solução 1


//solucao 2 - com necessidade de ser junto

/*
    for(i=0;i<tam_texto - (tam_procurado-1);i++)
    {   
        
        achou = compara_strings(&texto[i],procurado,tam_procurado);

        if (achou)
        {
            return 1;
        }
        
    }
*/
//solução 2
    return 0;
}

int compara_strings(char *texto, char *procurado, int tam)
{
    int i, j;

    /*
    printf("\nCompara: ");
    for(i=0;i<tam;i++)
    {
        printf("%c",texto[i]);
    }

    printf(" com ");

    for(i=0;i<tam;i++)
    {
        printf("%c",procurado[i]);
    }
*/
    for (i = 0; i < tam; i++)
    {
        //  printf("\n Comparando %c com %c",texto[i],procurado[i]);
        if (texto[i] != procurado[i])
        {
            return 0;
        }
    }
    return 1;
}