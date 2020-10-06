#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro_endereco
{
    char rua[30];
    int numero;
    char complemento[30];
    char bairro[30];
    char cep[30];
    char cidade[30];
    char estado[30];
    char pais[30];
} registro_endereco;

typedef struct data
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct pessoa
{
    char nome[30];
    char email[30];
    registro_endereco endereco;
    long int telefone;
    data data_nascimento;
    char observacoes[200];

} pessoa;

char *recupera_primeiro_nome(char *nome_completo);
void listar_por_nome(pessoa *agenda, char *primeiro_nome);
void mostrar_pessoa(pessoa p);
void listar_por_mes_aniversario(pessoa *agenda, int mes);
void listar_por_dia_mes_aniversario(pessoa *agenda, int dia, int mes);

int main()
{
    int i;
    pessoa agenda[100];
    int qtd=0;

    strcpy(agenda[0].nome,"Felippe Giuliani1");
    strcpy(agenda[1].nome,"Felippe Giuliani2");
    strcpy(agenda[2].nome,"Felippe Giuliani3");
    strcpy(agenda[3].nome,"Felippe Giuliani4");
    strcpy(agenda[4].nome,"Felippe Giuliani5");
    strcpy(agenda[5].nome,"teste teste1");
    strcpy(agenda[6].nome,"teste teste2");
    strcpy(agenda[7].nome,"teste teste3");
    strcpy(agenda[8].nome,"teste teste4");
    listar_por_nome(agenda,"jose");



    printf("\n");
    return 0;
}

void listar_por_nome(pessoa *agenda, char *primeiro_nome)
{
    char nome_aux[30];
    int i,j;

    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < strlen(agenda[i].nome) && agenda[i].nome[j] != ' '; j++)
        {
            nome_aux[j] = agenda[i].nome[j];
        }
        nome_aux[j] = '\0';

        if (strcmp(primeiro_nome,nome_aux)==0)
        {
            mostrar_pessoa(agenda[i]);
        }
    }
}
void listar_por_mes_aniversario(pessoa *agenda, int mes)
{
    int i;

    for (i = 0; i < 100; i++)
    {
        if (agenda[i].data_nascimento.mes == mes)
        {
            mostrar_pessoa(agenda[i]);
        }
    }
}
void listar_por_dia_mes_aniversario(pessoa *agenda, int dia, int mes)
{
    int i;

    for (i = 0; i < 100; i++)
    {
        if (agenda[i].data_nascimento.dia == dia && agenda[i].data_nascimento.mes == mes)
        {
            mostrar_pessoa(agenda[i]);
        }
    }
}

void incluir_ordenado(pessoa * agenda, int qtd_registros,pessoa p )
{
    int i;
    while

}

void mostrar_pessoa(pessoa p)
{
    int i;
    printf("\nNome: %s",p.nome);
}
