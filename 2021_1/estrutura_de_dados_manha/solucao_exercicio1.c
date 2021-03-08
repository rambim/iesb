#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct sanduiche
{
    char nome[30];
    double valor;
    float peso;
    int avaliacao;
}sanduiche;

sanduiche * aloca_vetor_sanduiches(int n);
void preenche_sanduiche(sanduiche * a);

int main()
{
    int n,i;
    sanduiche * sanduiches;
    int indice_melhor_avaliado=0;
    float som_peso=0,som_valor=0.0;

    printf("\n Digite a quantidade de sanduiches: ");
    scanf("%d",&n);

    sanduiches = aloca_vetor_sanduiches(n);

    for(i=0;i<n;i++)
    {
        preenche_sanduiche(&sanduiches[i]);

        if (sanduiches[i].nome[0]== 'a' || sanduiches[i].nome[0]=='A')
        {
            printf("\n%s comeca com a",sanduiches[i].nome);
        }

        if (sanduiches[i].avaliacao > sanduiches[indice_melhor_avaliado].avaliacao)
        {
            indice_melhor_avaliado = i;
        }

        som_peso = som_peso + sanduiches[i].peso;
        som_valor = som_valor + sanduiches[i].valor;
        printf("\n Somatorio ate o momento = %lf",som_valor);

    }

    printf("\n O sanduiche melhor avaliado e o %s com avaliacao %d",sanduiches[indice_melhor_avaliado].nome,sanduiches[indice_melhor_avaliado].avaliacao);
    printf("\n Peso medio sanduiches = %f",som_peso/n);
    printf("\n Valor total da compra: %lf",som_valor*3.0);

    printf("\n");
    return 0;
}

sanduiche * aloca_vetor_sanduiches(int n)
{
    int i;
    sanduiche * novo;

    // novo = (sanduiche*)calloc(n,sizeof(sanduiche));

    novo = (sanduiche*)malloc(sizeof(sanduiche)*n);

    for(i=0;i<n;i++)
    {
        strcpy(novo[i].nome,"\0");
        novo[i].peso =0;
        novo[i].valor=0;
        novo[i].avaliacao = 0;
    }


    
    return novo;
}

void preenche_sanduiche(sanduiche * a)
{
    printf("\n Digite o nome do sanduiche: ");
    // fflush(stdin); windows;
    __fpurge(stdin);
    fgets(a->nome,30,stdin);
    printf("\n Digite o valor do sanduiche: ");
    scanf("%lf",&a->valor);
    printf("\n Digite o peso do sanduiche: ");
    scanf("%f",&a->peso);
    printf("\n Digite a avaliacao do sanduiche: ");
    scanf("%d",&a->avaliacao);

}

