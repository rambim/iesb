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
}produto;

void le_produto(produto * p);
void preenche_lista_produtos(produto * produtos);
void mostra_produto( produto p);



int main()
{
    int i;
    produto  produtos[5];

    preenche_lista_produtos(produtos);

    mostra_produto(produtos[0]);


    printf("\n");
    return 0;
}

void preenche_lista_produtos(produto * produtos)
{
    int i;
    for(i=0;i<5;i++)
    {
        le_produto(&produtos[i]);
    }
}

void le_produto(produto * p)
{
    printf("\n Digite o codigo do produto: ");
    scanf("%d",p->codigo);
    printf("\n Digite o preco do produto: ");
    scanf("%d",&p->preco);
    printf("\n Digite a quantide do produto: ");
    scanf("%d",&p->qtd);
}

void mostra_produto( produto p)
{
    printf("\n\tCod.: %d\tPreco.: %f\tQtd.: %d");
}

