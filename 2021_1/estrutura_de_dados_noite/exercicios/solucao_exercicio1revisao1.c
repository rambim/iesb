#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct cachorro
{
    char nome[30];
    int idade;
    char raca[30];
    char cor[30];
    double peso;
    double altura;
}cachorro;

void preenche_cachorro(cachorro * c);

int main()
{
    cachorro * cachorros;
    int n,i, indice_cachorro_alto=0,indice_cachorro_velho=0;
    int qtd_cachorros_30=0;
    double som_peso=0;
    double peso_medio;

    printf("\n Digite a quantidade de cachorros: ");
    scanf("%d",&n);

    cachorros= (cachorro*)calloc(n,sizeof(cachorro));

    for(i=0;i<n;i++)
        preenche_cachorro(&cachorros[i]);

    printf("\n Cachorros com a inicial M: ");
    for(i=0;i<n;i++)
    {
        if (cachorros[i].nome[0] == 'M' || cachorros[i].nome[0] == 'm')
        {
            printf("\n%s",cachorros[i].nome);
        }

        if (cachorros[i].altura > cachorros[indice_cachorro_alto].altura)
        {
            indice_cachorro_alto = i;
        }

        if (cachorros[i].idade > cachorros[indice_cachorro_velho].idade)
        {
            indice_cachorro_velho = i;
        }

        if (cachorros[i].altura > 30)
        {
            qtd_cachorros_30++;
        }

        som_peso = som_peso + cachorros[i].peso;
    }

    peso_medio = som_peso / (double)n;
    printf("\n O peso medio dos cachorros e de  %lf",peso_medio);
    printf("\n O cachorro mais alto e o %s",cachorros[indice_cachorro_alto].nome);
    printf("\n O cachorro mais velho e o %s",cachorros[indice_cachorro_velho].nome);
    printf("\n Qtd de cachorros superiores a 30 cm: %d",qtd_cachorros_30);

    printf("\n");
    return 0;
}

void preenche_cachorro(cachorro * c)
{
    // fflush(stdin); windows no lugar de __fpurge

    printf("\n Digite o nome do cachorro: ");
    __fpurge(stdin);
    fgets(c->nome,30,stdin);
    printf("\n Digite a idade do cachorro: ");
    scanf("%d",&c->idade);
    printf("\n Digite o raca do cachorro: ");
    __fpurge(stdin);
    fgets(c->raca,30,stdin);
    printf("\n Digite a cor do cachorro: ");
    __fpurge(stdin);
    fgets(c->cor,30,stdin);
    printf("\n Digite o peso do cachorro: ");
    scanf("%lf",&c->peso);
    printf("\n Digite a altura do cachorro: ");
    scanf("%lf",&c->altura);
    
}