#include <stdio.h>
#include <stdlib.h>
#define tam 5

typedef struct produto
{
    int codigo;
    int qtd;
    float valor;
} produto;

typedef struct pedido
{
    int codigo;
    int qtd;
} pedido;

void preenche_vetor_produtos(produto *a, int qtd);
pedido ler_pedido();
void mostrar_estoque(produto *vetor, int qtd);
int main()
{
    produto vet_produtos[tam];
    pedido a;
    float total;
    int produto_encontrado = 0;
    int i;
    preenche_vetor_produtos(vet_produtos, tam);
    a.codigo = 1;
    while (a.codigo != 0)
    {
        mostrar_estoque(vet_produtos, tam);
        produto_encontrado = 0;
        a = ler_pedido();
        if (a.codigo != 0)
        {
            for (i = 0; i < tam && !produto_encontrado; i++)
            {
                if (vet_produtos[i].codigo == a.codigo)
                {
                    if (a.qtd <= vet_produtos[i].qtd)
                    {
                        total = a.qtd * vet_produtos[i].valor;
                        vet_produtos[i].qtd = vet_produtos[i].qtd - a.qtd;

                        printf("\n Pedido efetuado com sucesso! ");
                        printf("\n Codigo do produto: %d", a.codigo);
                        printf("\n Valor unitario   : %f", vet_produtos[i].valor);
                        printf("\n Qtd do pedido    : %d", a.qtd);
                        printf("\n total do pedido  : %f", total);
                    }
                    else
                    {
                        printf("\n Nao existe %d do produto %d no estoque", a.qtd, a.codigo);
                    }
                    produto_encontrado = 1;
                }
            }
            if (!produto_encontrado)
            {
                printf("\n Produto não encontrado");
            }
        }
    }
    return 0;
}

void preenche_vetor_produtos(produto *a, int qtd)
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        printf("\n Digite o codigo do produto: ");
        scanf("%d", &a[i].codigo);
        printf("\n Digite a quantidade do produto: ");
        scanf("%d", &a[i].qtd);
        printf("\n Digite o valor do produto: ");
        scanf("%f", &a[i].valor);
    }
}

pedido ler_pedido()
{
    pedido a;
    printf("\n Qual codigo do produto deseja? :");
    scanf("%d", &a.codigo);
    printf("\n Qual a quantidade que deseja?");
    scanf("%d", &a.qtd);
    return a;
}

void mostrar_estoque(produto *vetor, int qtd)
{
    int i;

    printf("\n ESTOQUE: ");
    for (i = 0; i < qtd; i++)
    {
        if (vetor[i].qtd > 0)
        {
            printf("\n produto: %d  Valor: %f  Qtd: %d", vetor[i].codigo, vetor[i].valor, vetor[i].qtd);
        }
    }
    printf("\n");
}