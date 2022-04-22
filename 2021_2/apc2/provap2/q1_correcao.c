#include <stdio.h>
#include <stdlib.h>

typedef struct contrato
{
    int qtd_parcelas;
    float *valor_parcela;
} contrato;

void preenche_contrato(contrato *c);
void mostrar_contrato(contrato c);
int main()
{
    int n, i;

    contrato *vetor_de_contratos;

    printf("\n Digite a quantidade de contratos do sistema: ");
    scanf("%d", &n);

    vetor_de_contratos = (contrato *)malloc(sizeof(contrato) * n);

    for (i = 0; i < n; i++)
    {
        preenche_contrato(&vetor_de_contratos[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("\n");
        mostrar_contrato(vetor_de_contratos[i]);
    }

    printf("\n");
    return 0;
}

void preenche_contrato(contrato *c)
{
    int i;
    printf("\n Digite a quantidade de parcelas: ");
    scanf("%d", &c->qtd_parcelas);

    c->valor_parcela = (float *)malloc(sizeof(float) * c->qtd_parcelas);

    for (i = 0; i < c->qtd_parcelas; i++)
    {
        printf("\n Digite o valor da %d parcela: ", i + 1);
        scanf("%f", &c->valor_parcela[i]);
    }
}

void mostrar_contrato(contrato c)
{
    int i;
    printf("\n Quantidade de parcelas: %d", c.qtd_parcelas);

    for (i = 0; i < c.qtd_parcelas; i++)
    {
        printf("\n Valor : %f", c.valor_parcela[i]);
    }
}