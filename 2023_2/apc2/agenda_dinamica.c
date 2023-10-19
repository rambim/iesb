#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct contato
{
    long long int telefone;
    char nome[50];
} contato;

typedef struct agenda
{
    int capacidade_agenda;
    int qtd_contatos_preenchidos;
    contato *contatos;
} agenda;

void mostrar_contato(contato *x);
agenda *cria_agenda(int capacidade_agenda);
void mostrar_agenda(agenda *a);
void preenche_agenda(contato *agenda, int capacidade_agenda);
void menu(agenda *a);
void incluir_contato(contato *novo);
int excluir_contato(agenda *a);
int buscar_contato(agenda *a);

int main()
{

    agenda *minha_agenda;

    minha_agenda = cria_agenda(2);
    menu(minha_agenda);

    printf("\n");
    return 0;
}

void menu(agenda *a)
{
    int opcao;

    do
    {

        printf("\n");
        printf("Quantidade de contatos na agenda: %d\n", a->qtd_contatos_preenchidos);
        printf("Capacidade da agenda: %d\n", a->capacidade_agenda);
        printf("1 - Incluir Contato\n");
        printf("2 - Buscar Contato\n");
        printf("3 - Excluir Contato\n");
        printf("4 - Mostrar Agenda Inteira\n");
        printf("5 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Incluindo contato...");
            incluir_contato(&a->contatos[a->qtd_contatos_preenchidos]);
            a->qtd_contatos_preenchidos++;
            if (a->capacidade_agenda * 0.8 <= a->qtd_contatos_preenchidos)
            {
                printf("Limite de 80 per atingido");
                a->contatos = (contato *)realloc(a->contatos, sizeof(contato) * a->capacidade_agenda * 2);
                a->capacidade_agenda *= 2;
            }
            break;
        case 2:
            printf("\n Buscar contato...");
            int busca = buscar_contato(a);
            if (busca == -1)
            {
                printf("\n Contato nao encontrado");
            }
            else
            {
                printf("\n Nome: %s", a->contatos[busca].nome);
                printf("\n Telefone: %lld", a->contatos[busca].telefone);
            }

            break;
        case 3:
            printf("\n Excluir contato...");
            excluir_contato(a);

            if (a->capacidade_agenda * 0.2 >= a->qtd_contatos_preenchidos)
            {
                a->contatos = (contato *)realloc(a->contatos, sizeof(contato) * a->capacidade_agenda / 2);
                a->capacidade_agenda /= 2;
            }
            break;
        case 4:
            mostrar_agenda(a);
            break;
        case 5:
            printf("\n Saind do programa..");
            break;

        default:
            printf("\n Opcao invalida");
            break;
        }

    } while (opcao != 5);
}

void incluir_contato(contato *novo)
{
    printf("\nDigite o nome do contato: ");
    // fflush(stdin);
    __fpurge(stdin);
    fgets(novo->nome, 40, stdin);
    novo->nome[strlen(novo->nome) - 1] = '\0';
    printf("\nDigite o telefone do contato");
    __fpurge(stdin);
    scanf("%lld", &novo->telefone);
}

int buscar_contato(agenda *a)
{
    char nome_de_busca[50];
    int i;

    printf("\nDigite o nome que deseja buscar: ");
    __fpurge(stdin);
    fgets(nome_de_busca, 48, stdin);
    nome_de_busca[strlen(nome_de_busca) - 1] = '\0';

    for (i = 0; i < a->qtd_contatos_preenchidos; i++)
    {
        if (strcmp(nome_de_busca, a->contatos[i].nome) == 0)
        {
            return i;
        }
    }

    return -1;
}

void mostrar_contato(contato *x)
{
    printf("Nome: %s\n", x->nome);
    printf("Telefone: %lld", x->telefone);
}

agenda *cria_agenda(int capacidade_agenda)
{
    agenda *nova;

    nova = (agenda *)malloc(sizeof(agenda));
    nova->contatos = (contato *)malloc(sizeof(contato) * capacidade_agenda);
    nova->capacidade_agenda = capacidade_agenda;
    nova->qtd_contatos_preenchidos = 0;
    return nova;
}

void mostrar_agenda(agenda *a)
{
    int i;

    if (a->qtd_contatos_preenchidos == 0)
    {
        printf("\n Agenda vazia");
    }
    else
    {
        for (i = 0; i < a->qtd_contatos_preenchidos; i++)
        {
            printf("\n Contato n %d", i + 1);
            printf("\n Nome: %s", a->contatos[i].nome);
            printf("\n Telefone: %lld", a->contatos[i].telefone);
            printf("\n");
        }
        printf("\n\n\n\n");
    }
}

int excluir_contato(agenda *a)
{
    int busca = buscar_contato(a);
    int i;

    if (busca == -1)
    {
        printf("\n Contato nao esta na agenda");
    }
    else
    {
        for (i = busca; i < a->qtd_contatos_preenchidos - 1; i++)
        {
            a->contatos[i] = a->contatos[i + 1];
        }
        a->qtd_contatos_preenchidos--;
    }
}