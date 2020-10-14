#include <stdio.h>
#include <stdlib.h>

typedef struct anuncio
{
    int cod_anuncio;
    char cidade[30];
    int qtd_quartos;
    float vlr_diaria;
    int ind_ocupacao;
} anuncio;

void preenche_anuncios(anuncio *anuncios);
void mostrar_anuncio(anuncio a);
void mostrar_anuncios(anuncio *anuncios);
int mostrar_menu();
void listar_por_quarto(anuncio *anuncios, int qtd_quartos);
void listar_por_valor(anuncio *anuncios, float vlr_maximo);
void checkout(anuncio *anuncios, int cod);
void checkin(anuncio *anuncios, int cod);
int main()
{

    anuncio anuncios[5];
    int opcao;
    int qtd_quartos;
    float vlr_maximo;
    int cod;
    preenche_anuncios(anuncios);
    mostrar_anuncios(anuncios);

    do
    {
        opcao = mostrar_menu();

        switch (opcao)
        {
        case 1:
            printf("\n Qual quantidade de quartos deseja? ");
            scanf("%d", &qtd_quartos);
            listar_por_quarto(anuncios, qtd_quartos);
            break;
        case 2:
            printf("\n Qual valor maximo deseja? ");
            scanf("%f", &vlr_maximo);
            listar_por_valor(anuncios, vlr_maximo);
            break;
        case 3:
            printf("\n Qual o codigo do anuncio deseja realizar checkin?");
            scanf("%d", &cod);
            checkin(anuncios, cod);
            break;
        case 4:
            printf("\n Qual o codigo do anuncio deseja realizar checkout?");
            scanf("%d", &cod);
            checkout(anuncios, cod);
            break;
        case 5:
            mostrar_anuncios(anuncios);
            break;
        case 6:
            printf("\n saindo do programa");
            break;
        default:
            printf("\nopcao invalida");
            break;
        }

    } while (opcao != 6);

    printf("\n");
    return 0;
}

void preenche_anuncios(anuncio *anuncios)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("\nDigite o codigo do anuncio");
        scanf("%d", &anuncios[i].cod_anuncio);
        printf("\nDIgite de qual cidade e o anuncio");
        // fgets(anuncios[i].cidade,30,stdin);
        scanf("%s", anuncios[i].cidade);
        printf("\nQual a quantidade de quartos? ");
        scanf("%d", &anuncios[i].qtd_quartos);
        printf("\nDigite o valor da diaria: ");
        scanf("%f", &anuncios[i].vlr_diaria);
        anuncios[i].ind_ocupacao = 0;
    }
}

void mostrar_anuncio(anuncio a)
{
    printf("\nCod.: %d Cidade: %s\t Qtd.Quartos = %d Vlr_Diaria: R$ %.2f Ind_ocupacao = %d", a.cod_anuncio, a.cidade, a.qtd_quartos, a.vlr_diaria, a.ind_ocupacao);
}

void mostrar_anuncios(anuncio *anuncios)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        mostrar_anuncio(anuncios[i]);
    }
}

int mostrar_menu()
{
    int opcao;
    printf("\n1- Listar anuncios por qtd de quartos: ");
    printf("\n2- Listar anuncios abaixo de um valor: ");
    printf("\n3- Realizar checkin");
    printf("\n4- Realizar Checkout");
    printf("\n5- Mostrar todos");
    printf("\n6- Sair");
    printf("\nOpcao: ");
    scanf("%d", &opcao);
    return opcao;
}

void listar_por_quarto(anuncio *anuncios, int qtd_quartos)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (anuncios[i].qtd_quartos == qtd_quartos && anuncios[i].ind_ocupacao == 0)
        {
            mostrar_anuncio(anuncios[i]);
        }
    }
}

void listar_por_valor(anuncio *anuncios, float vlr_maximo)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (anuncios[i].vlr_diaria <= vlr_maximo && anuncios[i].ind_ocupacao == 0)
        {
            mostrar_anuncio(anuncios[i]);
        }
    }
}

void checkin(anuncio *anuncios, int cod)
{
    int i;
    int flag = 0;
    for (i = 0; i < 5; i++)
    {
        if (anuncios[i].cod_anuncio == cod)
        {
            if (anuncios[i].ind_ocupacao == 0)
            {
                anuncios[i].ind_ocupacao = 1;
                flag = 1;
            }
            else
            {
                flag = 2;
            }
        }
    }

    switch (flag)
    {
    case 0:
        printf("\n Codigo de anuncio nao encontrado");
        break;
    case 1:
        printf("\n Checkin realizado com sucesso");
        break;
    case 2:
        printf("\n Anuncio ja esta ocupado");
        break;
    }
}

void checkout(anuncio *anuncios, int cod)
{
    int i;
    int flag = 0;
    for (i = 0; i < 5; i++)
    {
        if (anuncios[i].cod_anuncio == cod)
        {
            if (anuncios[i].ind_ocupacao == 1)
            {
                anuncios[i].ind_ocupacao = 0;
                flag = 1;
            }
            else
            {
                flag = 2;
            }
        }
    }

    switch (flag)
    {
    case 0:
        printf("\n Codigo de anuncio nao encontrado");
        break;
    case 1:
        printf("\n Checkout realizado com sucesso");
        break;
    case 2:
        printf("\n Anuncio nao esta ocupado");
        break;
    }
}