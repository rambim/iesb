/*

Faça um programa que gerencie o estoque de um mercado e:
•Crie e leia um vetor de 5 produtos, com os dados:  código (inteiro), preço e quantidade.
•Leia  um  pedido,  composto  por  um  código  de  produto  e  a  quantidade.   
Localizeeste  código  no  vetor  e,  se  houver  quantidade  suficiente  para  atender  ao  pedido
integralmente, atualize o estoque e informe o usuário. 
Repita este processo at ́e ler um código igual a zero.
Se por algum motivo nãoo for poss ́ıvel atender ao pedido, mostre uma mensagem informando 
qual erro ocorreu.

Os produtos devem ser amarmazenados em um vetor de structs
*/

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

void preenche_produtos(produto *produtos);
void mostrar_produtos(produto *p);
void confere_estoque(produto *produtos, pedido p);
pedido le_pedido();

int main()
{
    pedido p;
    produto produtos[5];
    preenche_produtos(produtos);

    do
    {
        mostrar_produtos(produtos);
        p = le_pedido();
        if (p.codigo != 0)
        {
            confere_estoque(produtos, p);
        }

    } while (p.codigo != 0);

    printf("\n");
    return 0;
}

void preenche_produtos(produto *produtos)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("\nDigite o codigo do produto: ");
        scanf("%d", &produtos[i].codigo);
        printf("\nDigite o preco do produto: ");
        scanf("%f", &produtos[i].preco);
        printf("\nDigite a quantidade do produto: ");
        scanf("%d", &produtos[i].qtd);
    }
}

void mostrar_produtos(produto *p)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("\nCodigo %d Preco: R$ %.2f\tQtd.: %d", p[i].codigo, p[i].preco, p[i].qtd);
    }
}

pedido le_pedido()
{
    pedido p;
    printf("\nDigite o codigo do produto desejado: ");
    scanf("%d", &p.codigo);
    if (p.codigo != 0)
    {
        printf("\nDigite a quantidade desejada do produto: ");
        scanf("%d", &p.qtd);
    }
    return p;
}

void confere_estoque(produto *produtos, pedido p)
{
    int i;
    float total;
    for (i = 0; i < 5; i++)
    {
        if (p.codigo == produtos[i].codigo)
        {
            if (p.qtd <= produtos[i].qtd)
            {
                total = produtos[i].preco * p.qtd;
                produtos[i].qtd = produtos[i].qtd - p.qtd;
                printf("\nTotal do pedido: %f", total);
                return;
            }
            else
            {
                printf("\nNao existe quantidade suficiente do produto de codigo %d", p.codigo);
                return;
            }
        }
    }
    printf("\n Produto nao disponivel");
    return;
}