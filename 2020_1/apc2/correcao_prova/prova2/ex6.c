#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct igrediente
{
    char nome_igrediente[30];
    int qtd_do_igrediente;
} igrediente;

typedef struct receita
{
    char nome[25];
    int qtd_igredientes;
    igrediente *lista_igredientes;
} receita;

void mostrar_receita(receita r);
void preenche_receita(receita *r);
int buscar_receita(receita * receitas, char *  receita_procurada);

int main()
{
    int i,retorno;
    receita receitas[5];
    char receita_buscada[25];

    for (i = 0; i < 5; i++)
    {
        preenche_receita(&receitas[i]);
    }

    do
    {
        printf("\nQual receita deseja buscar? ");
        __fpurge(stdin);
        fgets(receita_buscada, 25, stdin);
        receita_buscada[strlen(receita_buscada) - 1] = '\0';
        retorno = buscar_receita(receitas,receita_buscada);
        if ( retorno == -1)
        {
            printf("\n receita nao encontrada");
        }
        else
        {
            mostrar_receita(receitas[retorno]);
        }
        

    } while (strlen(receita_buscada) != 0);
    printf("\n");
    return 0;
}

void preenche_receita(receita *r)
{
    int i;

    printf("\nDigite o nome da receita: ");
    __fpurge(stdin);
    fgets(r->nome, 25, stdin);
    r->nome[strlen(r->nome) - 1] = '\0';

    printf("\nQuantos igredientes? ");
    scanf("%d", &r->qtd_igredientes);

    r->lista_igredientes = (igrediente *)malloc(sizeof(igrediente) * r->qtd_igredientes);

    for (i = 0; i < r->qtd_igredientes; i++)
    {
        printf("\nDigite o %d igrediente: ", i + 1);
        __fpurge(stdin);
        fgets(r->lista_igredientes[i].nome_igrediente, 30, stdin);
        r->lista_igredientes[i].nome_igrediente[strlen(r->lista_igredientes[i].nome_igrediente) - 1] = '\0';
        printf("\nQuantidade do igrediente %s : ", r->lista_igredientes[i].nome_igrediente);
        scanf("%d", &r->lista_igredientes[i].qtd_do_igrediente);
    }
}

void mostrar_receita(receita r)
{
    int i;
    printf("\nNome da receita: %s ", r.nome);
    printf("\nLista de igredientes: ");
    printf("\nNome\t\tqtd");
    for (i = 0; i < r.qtd_igredientes; i++)
    {
        printf("\n%s\t\t%d", r.lista_igredientes[i].nome_igrediente, r.lista_igredientes[i].qtd_do_igrediente);
    }
}


// - 1 = se nao encontrar
// 0  - 4 = indice da receita encontrada
int buscar_receita(receita * receitas, char * receita_procurada)
{
    int i;
    for(i=0;i<5;i++)
    {
        if (strcmp(receitas[i].nome,receita_procurada)==0)
        {
            return i;
        }
    }
    return - 1;
}