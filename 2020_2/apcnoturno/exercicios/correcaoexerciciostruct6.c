#include <stdio.h>
#include <stdlib.h>

typedef struct produto
{
    int codigo;
    float preco;
    int qtd;
} produto;

typedef struct pedido
{
    int codigo;
    int qtd;
} pedido;

void le_produto(produto *p);
void preenche_lista_produtos(produto *produtos);
void mostra_produtos(produto *p);
void le_pedido(pedido *p);
void verifica_estoque(produto *produtos, pedido p);

int main()
{
    int i;
    produto produtos[5];
    pedido p;

    preenche_lista_produtos(produtos);

    do
    {
        mostra_produtos(produtos);
        le_pedido(&p);
        verifica_estoque(produtos, p);
    } while (p.codigo != 0);

    printf("\n");
    return 0;
}

void preenche_lista_produtos(produto *produtos)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        le_produto(&produtos[i]);
    }
}

void le_produto(produto *p)
{
    printf("\n Digite o codigo do produto: ");
    scanf("%d", &p->codigo);
    printf("\n Digite o preco do produto: ");
    scanf("%f", &p->preco);
    printf("\n Digite a quantide do produto: ");
    scanf("%d", &p->qtd);
}

void mostra_produtos(produto *p)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("\nCod.: %d\tPreco.: R$%.2f\tQtd.: %d", p[i].codigo, p[i].preco, p[i].qtd);
    }
}

void le_pedido(pedido *p)
{
    printf("\n Qual o codigo do produto desejado?: ");
    scanf("%d", &p->codigo);
    if (p->codigo != 0)
    {
        printf("\n Quantas unidades do produto %d deseja: ", p->codigo);
        scanf("%d", &p->qtd);
    }
}

void verifica_estoque(produto *produtos, pedido p)
{
    int i;
    float total;
    int deu_certo = 0;
    for (i = 0; i < 5; i++)
    {
        if (produtos[i].codigo == p.codigo)
        {
            if (p.qtd <= produtos[i].qtd)
            {
                total = produtos[i].preco * p.qtd;
                produtos[i].qtd = produtos[i].qtd - p.qtd;
                printf("\n Total do pedido: R$ %.2f", total);
                deu_certo = 1;
            }
        }
    }

    if (deu_certo)
    {
        printf("\n Compra finalizada");
    }
    else
    {
        printf("\n Nao existe qtd suficiente do produto desejado");
    }
}