#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct agenda
{
    struct contato *contatos;
    int capacidade;
    int qtd_contatos;

} agenda;

typedef struct contato
{
    char nome[35];
    int idade;
    long int telefone;
    char email[50];
} contato;

agenda *cria_agenda(int capacidade_inicial);
int atualiza_capacidade_agenda(agenda *a);
contato solicitar_informacoes_contato();
void mostrar_contato(contato c);
void mostrar_agenda_completa(agenda *a);
void incluir_contato(agenda *a, contato c);
void menu(agenda *a);
contato * buscar_contato(agenda * a, char * nome_procurado);

int main()
{

    agenda *a1, *a2, *a3;
    int retorno;

    a1 = cria_agenda(2);

    menu(a1);

    printf("\n");
    return 0;
}

agenda *cria_agenda(int capacidade_inicial)
{
    agenda *nova_agenda;

    nova_agenda = (agenda *)malloc(sizeof(agenda));
    nova_agenda->qtd_contatos = 0;
    nova_agenda->capacidade = capacidade_inicial;
    nova_agenda->contatos = (contato *)malloc(sizeof(contato) * nova_agenda->capacidade);
    return nova_agenda;
}

// 1 - atualizou tamanho
// 0 - não atualizou tamanho
int atualiza_capacidade_agenda(agenda *a)
{
    float percentual;
    int nova_capacidade;

    percentual = (float)a->qtd_contatos / (float)a->capacidade;

    if (percentual >= 0.5)
    {
        nova_capacidade = a->capacidade * 2;
        a->contatos = (contato *)realloc(a->contatos, sizeof(contato) * nova_capacidade);
        a->capacidade = nova_capacidade;
        return 1;
    }

    if (percentual <= 0.2)
    {
        nova_capacidade = a->capacidade / 2;
        a->contatos = (contato *)realloc(a->contatos, sizeof(contato) * nova_capacidade);
        a->capacidade = nova_capacidade;
        return 1;
    }

    return 0;
}

void incluir_contato(agenda *a, contato c)
{
    (*a).contatos[a->qtd_contatos] = c;
    a->qtd_contatos++;
    if (atualiza_capacidade_agenda(a))
    {
        printf("\n Foi atualizado a capacidade da agenda");
    }
    else
    {
        printf("\n Nãoa Foi atualizada a capacidade da agenda");
    }
}

contato solicitar_informacoes_contato()
{
    contato c;
    printf("\n Digite o nome do contato: ");
    __fpurge(stdin); // wwindows fflush(stdin);
    fgets(c.nome, 35, stdin);
    c.nome[strlen(c.nome) - 1] = '\0';
    printf("\n Digite a idade do contato: ");
    scanf("%d", &c.idade);
    printf("\n Digite o telefone do contato: ");
    scanf("%ld", &c.telefone);
    printf("\n Digite o email do contato: ");
    __fpurge(stdin);
    fgets(c.email, 50, stdin);
    c.email[strlen(c.email) - 1] = '\0';
    return c;
}

void mostrar_contato(contato c)
{
    printf("\n Nome: %s Email: %s Idade: %d Telefone: %ld", c.nome, c.email, c.idade, c.telefone);
}

void mostrar_agenda_completa(agenda *a)
{
    int i;
    printf("\n ----- Agenda : ------- ");

    if (a->qtd_contatos == 0)
    {
        printf("\n Agenda  vazia");
    }
    else
    {
        for (i = 0; i < a->qtd_contatos; i++)
        {
            mostrar_contato(a->contatos[i]);
        }
    }
    printf("\n ------- fim de agenda ------\n");
}

void menu(agenda *a)
{
    int opcao;
    contato novo;
    contato * c;
    char procurado[50];

    do
    {
        printf("\n Capacidade da agenda: %d",a->capacidade);
        printf("\n 1 - Incluir um contato");
        printf("\n 2 - Buscar um contato");
        printf("\n 3 - Remover um contato");
        printf("\n 4 - Mostrar agenda completa");
        printf("\n Opcao: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            novo = solicitar_informacoes_contato();
            incluir_contato(a, novo);
            break;
        case 2:
            printf("\n Digite o nome que deseja procurar: ");
            __fpurge(stdin);
            fgets(procurado,50,stdin);
            procurado[strlen(procurado)-1] = '\0';

            c = buscar_contato(a,procurado);

            if (c==NULL)
            {
                printf("\n Nao existe %s na agenda",procurado);
            }
            else
            {
                mostrar_contato(*c);
            }
            break;
        case 3:
            break;
        case 4:
            mostrar_agenda_completa(a);
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 10);
}

contato * buscar_contato(agenda * a, char * nome_procurado)
{
    int i;
    for(i=0;i<a->qtd_contatos;i++)
    {
        if (strcmp(a->contatos[i].nome,nome_procurado)==0)
        {
            return &a->contatos[i];
        }
    }
    return NULL;
}