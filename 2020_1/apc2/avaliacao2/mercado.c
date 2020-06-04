/*

Mercado
    Cadastrar produtos (limitado)
    realizar venda
    incluir no estoque
    relatório de vendas
    Envio de dados da compra por e-mail ( arquivo)

*/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto
{
    char nome[30];
    float valor;
    int qtd_em_estoque;
} produto;

typedef struct mercado
{
    produto *produtos;
    int qtd_produtos_cadastrados;
    int capacidade_de_produtos;
} mercado;

mercado *aloca_mercado();
produto *aloca_vetor_produtos(int n);
void menu(mercado *m);
int cadastrar_produto(mercado *m);
produto criar_produto();
void listar_produtos(produto *p, int qtd_de_produtos);
void incluir_no_estoque(mercado *m);
void realizar_venda(mercado *m);

int main()
{
    mercado * mercado1;

    mercado1 = aloca_mercado();

    menu(mercado1);

    return 0;
}

mercado *aloca_mercado()
{
    mercado *novo;
    int capacidade;
    novo = (mercado *)malloc(sizeof(mercado));
    printf("\n Qual a capacidade de produtos do mercado? ");
    scanf("%d", &novo->capacidade_de_produtos);

    novo->produtos = aloca_vetor_produtos(novo->capacidade_de_produtos);
    novo->qtd_produtos_cadastrados = 0;
    return novo;
}

produto * aloca_vetor_produtos(int n)
{
    produto *novo;
    int i;

    novo = (produto *)malloc(sizeof(produto) * n);

    for (i = 0; i < n; i++)
    {
        strcpy(novo[i].nome, " ");
        novo[i].valor = 0;
        novo[i].qtd_em_estoque = 0;
    }

    return novo;
}

void menu(mercado *m)
{
    int opcao;
    int retorno;

    do
    {
        printf("\n\n\n------------------------------------------------------------------------");
        printf("\n 1 - Cadastrar Produto");
        printf("\n 2 - Realizar venda");
        printf("\n 3 - Incluir produto no estoque");
        printf("\n 4 - Relatorio de Vendas");
        printf("\n 5 - Listar Produtos do mercado ");
        printf("\n Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            retorno = cadastrar_produto(m);

            switch (retorno)
            {
            case 1:
                printf("\n Produto cadastrado com sucesso");
                break;
            case -1:
                printf("\n Capacidade maxima de produtos do mercado atingido");
                break;
            default:
                printf("\n Retorno desconhecido");
            }

            break;
        case 2:
            realizar_venda(m);
            break;
        case 3:
            incluir_no_estoque(m);
            break;
        case 4:
            break;
        case 5:
            listar_produtos(m->produtos, m->qtd_produtos_cadastrados);
            break;
        case 10:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n Opcao invalida");
            break;
        }
    } while (opcao != 10);
}

// -1 = capacidade maxima de produtos atingido
//  1 = Cadastro de produto com sucesso;
int cadastrar_produto(mercado *m)
{

    if (m->qtd_produtos_cadastrados >= m->capacidade_de_produtos)
    {
        return -1;
    }

    m->produtos[m->qtd_produtos_cadastrados] = criar_produto();
    (m->qtd_produtos_cadastrados)++;

    return 1;
}

produto criar_produto()
{
    produto p;

    printf("\nDigite o nome do produto: ");
    __fpurge(stdin);
    fgets(p.nome, 30, stdin);
    p.nome[strlen(p.nome) - 1] = '\0';
    p.qtd_em_estoque = 0;
    printf("\nDigite o valor do produto: ");
    scanf("%f", &p.valor);
    return p;
}

void incluir_no_estoque(mercado *m)
{
    int opcao;
    int qtd_para_adicionar;
    if (m->qtd_produtos_cadastrados == 0)
    {
        printf("\nNenhum produto cadastrado");
        return;
    }

    printf("\nQual produto deseja adicionar no estoque: ");
    listar_produtos(m->produtos, m->qtd_produtos_cadastrados);

    do
    {
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        if ((opcao - 1) < 0 || (opcao - 1) >= m->qtd_produtos_cadastrados)
        {
            printf("\nDigite uma opcao valida");
        }

    } while ((opcao - 1) < 0 || (opcao - 1) >= m->qtd_produtos_cadastrados);

    printf("\nQuantas unidades?: ");
    scanf("%d", &qtd_para_adicionar);
    m->produtos[opcao - 1].qtd_em_estoque = m->produtos[opcao - 1].qtd_em_estoque + qtd_para_adicionar;
}

void listar_produtos(produto *p, int qtd_de_produtos)
{
    int i;
    if (qtd_de_produtos == 0)
    {
        printf("\n Nenhum produto cadastrado");
        return;
    }

    printf("\n\tNr.\t\tNome\t\tQtd\t\tVlr.Un.");
    for (i = 0; i < qtd_de_produtos; i++)
    {
        printf("\n\t%d\t\t%s\t\t%d\t\t%.2f", i + 1, p[i].nome, p[i].qtd_em_estoque, p[i].valor);
    }
}

void realizar_venda(mercado *m)
{
    float total_da_compra=0;
    int vender = 0;
    int opcao;
    int qtd_desejada;
    do
    {

        if (m->qtd_produtos_cadastrados <= 0)
        {
            printf("\nNao existem produtos cadastrados");
            return;
        }
        printf("\nDigite o numero do produto: ");
        listar_produtos(m->produtos, m->qtd_produtos_cadastrados);

        do
        {
            printf("\nOpcao: ");
            scanf("%d", &opcao);
            if ((opcao - 1) < 0 || (opcao - 1) >= m->qtd_produtos_cadastrados)
            {
                printf("\nDigite uma opcao valida");
            }

        } while ((opcao - 1) < 0 || (opcao - 1) >= m->qtd_produtos_cadastrados);

        printf("\nQuantas unidades deseja?: ");
        scanf("%d", &qtd_desejada);

        if (qtd_desejada <= 0)
        {
            printf("\nQuantidade invalida: ");
        }
        else
        {
            if (qtd_desejada > m->produtos[opcao - 1].qtd_em_estoque)
            {
                printf("\nQuantidade desejada nao disponivel, produto com %d unidades disponiveis", m->produtos[opcao - 1].qtd_em_estoque);
                printf("\nVenda nao realizada");
            }
            else
            {
                m->produtos[opcao - 1].qtd_em_estoque = m->produtos[opcao - 1].qtd_em_estoque - qtd_desejada;
                printf("\nVenda realizada com sucesso");
                total_da_compra = total_da_compra + (m->produtos[opcao-1].valor * qtd_desejada);
            }
        }
        printf("\n Total: %.2f",total_da_compra);
        printf("\n\nDeseja comprar outro produto? ");
        do
        {
            printf("\n1 - Sim");
            printf("\n2 - Nao");
            printf("\nOpcao: ");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 1:
                vender = 1;
                break;
            case 2:
                vender = 0;
                break;
            default:
                printf("\n Opcao invalida, digite novamente: ");
                break;
            }

        } while (opcao != 1 && opcao != 2);

    } while (vender==1);
    printf("\n TOTAL DA COMPRA = %.2f",total_da_compra);
}