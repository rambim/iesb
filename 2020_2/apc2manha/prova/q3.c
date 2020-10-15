#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    long int matricula;
    float salario_bruto;
    int carga_horaria;
} funcionario;

void incluir_funcionario(funcionario *funcinoarios, int *qtd_funcionarios);
void remover_funcionario(funcionario *funcionarios, int *qtd_funcionarios);
void preenche(funcionario *f);
void mostrar(funcionario *funcionarios, int qtd);
void folha_pagamento(funcionario *funcionarios, int qtd_funcionarios);

int main()
{
    int qtd_funcionarios;
    funcionario funcionarios[10];
    int opcao;

    do
    {
        printf("\n1 - Incluir funcionario");
        printf("\n2 - remover funcionario");
        printf("\n3 - mostrar folha de pagamento");
        printf("\n4 - sair :");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            incluir_funcionario(funcionarios, &qtd_funcionarios);
            break;
        case 2:
            remover_funcionario(funcionarios, &qtd_funcionarios);
            break;
        case 3:
            folha_pagamento(funcionarios, qtd_funcionarios);
            break;
        case 4:
            printf("\n Saindo do programa");
            break;
        case 5:
            mostrar(funcionarios, qtd_funcionarios);
            break;
        default:
            printf("\n opcao invalida");
            break;
        }

    } while (opcao != 4);

    printf("\n");
    return 0;
}

void incluir_funcionario(funcionario *funcionarios, int *qtd_funcionarios)
{
    if (*qtd_funcionarios >= 10)
    {
        printf("\n Vetor de funcionarios cheio");
    }
    else
    {
        preenche(&funcionarios[*qtd_funcionarios]);
        *qtd_funcionarios = *qtd_funcionarios + 1;
    }
}

void preenche(funcionario *f)
{
    printf("\nDigite a matricula do funcionario: ");
    scanf("%ld", &f->matricula);
    printf("\nDigite o salario bruto do funcionario: ");
    scanf("%f", &f->salario_bruto);
    printf("\nDigite a carga horaria do funcionario: ");
    scanf("%d", &f->carga_horaria);
}

void remover_funcionario(funcionario *funcionarios, int *qtd_funcionarios)
{
    long int matricula;
    int i, j;
    int encontrou = 0;
    if (*qtd_funcionarios == 0)
    {
        printf("\nNao existem funcionarios cadastrados");
    }
    else
    {
        printf("\nQual matricula deseja apagar");
        scanf("%ld", &matricula);

        for (i = 0; i < *qtd_funcionarios; i++)
        {
            if (funcionarios[i].matricula == matricula)
            {
                encontrou = 1;
                for (j = i; j < *qtd_funcionarios - 1; j++)
                {
                    funcionarios[j] = funcionarios[j + 1];
                }
                (*qtd_funcionarios)--;
            }
        }
    }

    if (encontrou)
    {
        printf("\n Apagado com sucesso");
    }
    else
    {
        printf("\n Funcionario nao encontrado");
    }
}

void mostrar(funcionario *funcionarios, int qtd)
{
    int i;
    printf("\n Total de funcionarios: %d", qtd);
    for (i = 0; i < qtd; i++)
    {
        printf("\n Matricula     : %ld", funcionarios[i].matricula);
        printf("\n Salario bruto : %f", funcionarios[i].salario_bruto);
        printf("\n Carga horaria : %d", funcionarios[i].carga_horaria);
    }
}

void folha_pagamento(funcionario *funcionarios, int qtd_funcionarios)
{
    float som_sal = 0;
    float som_vl_hora = 0;
    float vlr_medio_hora = 0;
    int i;

    mostrar(funcionarios, qtd_funcionarios);

    for (i = 0; i < qtd_funcionarios; i++)
    {
        som_sal = som_sal + funcionarios[i].salario_bruto;
        som_vl_hora = som_vl_hora + (funcionarios[i].salario_bruto / funcionarios[i].carga_horaria);
    }

    if (qtd_funcionarios > 0)
    {
        vlr_medio_hora = som_vl_hora / qtd_funcionarios;
    }

    printf("\n Somatorio de salarios : %f", som_sal);
    printf("\n Valor medio hora = %f", vlr_medio_hora);
}