#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct carro
{
    int ano;
    char modelo[30];
    char marca[30];
    int qtd_revisoes;
    data *revisoes;
} carro;

carro *aloca_vetor_carros(int qtd_carros);
void preenche_carro(carro *a);
void mostrar_dados_carro(carro a);

int main()
{
    carro *frota;
    int n, i;
    int qtd;

    printf("\n Digite a quantidade de carros: ");
    scanf("%d", &n);

    frota = aloca_vetor_carros(n);

    for (i = 0; i < n; i++)
    {
        preenche_carro(&frota[i]);
    }

    printf("\n Os veiculos com quantas revisoes deseja consultar?");
    scanf("%d", &qtd);

    for (i = 0; i < n; i++)
    {
        if (frota[i].qtd_revisoes == qtd)
        {
            mostrar_dados_carro(frota[i]);
        }
    }

    printf("\n");
    return 0;
}

carro *aloca_vetor_carros(int qtd_carros)
{
    int i;
    carro *novo;
    novo = (carro *)malloc(sizeof(carro) * qtd_carros);

    for (i = 0; i < qtd_carros; i++)
    {
        novo[i].ano = 0;
        novo[i].qtd_revisoes = 0;
        strcpy(novo[i].marca, "\0");
        strcpy(novo[i].modelo, "\0");
        novo[i].revisoes = NULL;
    }

    return novo;
}

void preenche_carro(carro *a)
{
    int i;
    printf("\nDigite o marca do carro: ");
    __fpurge(stdin);
    fgets(a->marca, 30, stdin);
    a->marca[strlen(a->marca) - 1] = '\0';

    printf("\nDigite o modelo do carro: ");
    __fpurge(stdin);
    fgets(a->modelo, 30, stdin);
    a->modelo[strlen(a->modelo) - 1] = '\0';

    printf("\nDigite o ano do carro: ");
    scanf("%d", &a->ano);

    printf("\n Digite a quantidade de revisoes: ") /
        scanf("%d", &a->qtd_revisoes);

    a->revisoes = (data *)malloc(sizeof(data) * a->qtd_revisoes);

    for (i = 0; i < a->qtd_revisoes; i++)
    {
        printf("\nDigite a data da %d revisao no formato DD/MM/YYYY: ", i + 1);
        scanf("%d/%d/%d", &a->revisoes[i].dia, &a->revisoes[i].mes, &a->revisoes[i].ano);
    }
}

void mostrar_dados_carro(carro a)
{
    int i;
    printf("\n Marca: %s Modelo: %s Ano: %d, Qtd.Revisoes: %d", a.marca, a.modelo, a.ano, a.qtd_revisoes);

    for (i = 0; i < a.qtd_revisoes; i++)
    {
        printf("\n%d revisao: %d/%d/%d", i + 1, a.revisoes[i].dia, a.revisoes[i].mes, a.revisoes[i].ano);
    }
}