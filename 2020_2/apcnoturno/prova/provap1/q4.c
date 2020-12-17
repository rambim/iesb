
/*
Utilizando como base a estrutura acima faça um programa que:



a) apresente o seguinte menu para o usuário:



1 - Incluir funcionario

2 - Remover funcionario

3 - Mostrar folha de pagamento

4 - Sair



b) Uma função que inclua um funcionário no vetor de funcionários e que seja invocada na opção 1 do menu;

c) Uma função que solicite ao usuário um número de matricula e remova um funcionário do vetor de funcionários que tenha a matricula igual a informada pelo usuário. Essa função deve ser invocada na opção 2 do menu;

d) Uma função que mostre na tela:


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    long int matricula;
    float salario_bruto;
    int carga_horaria;
} funcionario;

void incluir_funcionario(funcionario *vetor, int *qtd_funcionarios);
void remover_funcionario(funcionario *vetor, int *qtd_funcionarios, long int x);
void folha_de_pagamento(funcionario *f, int qtd_funcionarios);

int main()
{
    int opcao;
    int qtd_funcionarios;
    funcionario funcionarios[10];
    long int matricula;

    do
    {
        printf("\n1 - Incluir Funcionario");
        printf("\n2 - Remover Funcionario");
        printf("\n3 - Mostrar Folha de pagamento");
        printf("\n4 - Sair :");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            incluir_funcionario(funcionarios, &qtd_funcionarios);
            break;
        case 2:

            if (qtd_funcionarios > 0)
            {
                printf("\n Qual matricula deseja remover: ");
                scanf("%ld", &matricula);
                remover_funcionario(funcionarios, &qtd_funcionarios, matricula);
            }
            else
            {
                printf("\nNao existem funcionarios cadastrados");
            }

            break;
        case 3:
            folha_de_pagamento(funcionarios, qtd_funcionarios);
            break;
        case 4:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\nOpcao invalida");
            break;
        }

    } while (opcao != 4);
}

void incluir_funcionario(funcionario *vetor, int *qtd_funcionarios)
{
    if (*qtd_funcionarios >= 10)
    {
        printf("\nVetor de funcionarios esta cheio");
    }
    else
    {
        printf("\nDigite a Matricula do Funcionario:");
        scanf("%ld", &vetor[*qtd_funcionarios].matricula);
        printf("\nDigite o salario bruto do funcionario: ");
        scanf("%f", &vetor[*qtd_funcionarios].salario_bruto);
        printf("\nDigite a carga horaria do funcionario: ");
        scanf("%d", &vetor[*qtd_funcionarios].carga_horaria);
        (*qtd_funcionarios)++;
    }
}

void remover_funcionario(funcionario *vetor, int *qtd_funcionarios, long int x)
{
    int i, j;
    int apagou = 0;

    for (i = 0; i < *qtd_funcionarios && !apagou; i++)
    {
        if (vetor[i].matricula == x)
        {
            for (j = i; j < *qtd_funcionarios - 1; j++)
            {
                vetor[j] = vetor[j + 1];
            }
            apagou = 1;
            (*qtd_funcionarios)--;
        }
    }

    if (apagou)
    {
        printf("\n Elemento removido com sucesso");
    }
    else
    {
        printf("\n Elementro nao encontrado");
    }
}

void folha_de_pagamento(funcionario *f, int qtd_funcionarios)
{
    int i;
    float sum_salarios_brutos=0;
    float sum_valor_hora=0;

    printf("\nTotal de funcionarios: %d", qtd_funcionarios);
    for (i = 0; i < qtd_funcionarios; i++)
    {
        printf("\nMatricula do funcionario: %ld", f[i].matricula);
        printf("\nSalario bruto           : %f", f[i].salario_bruto);
        printf("\nCarga horarioa          : %d\n", f[i].carga_horaria);

        sum_salarios_brutos = sum_salarios_brutos + f[i].salario_bruto;
        sum_valor_hora = sum_valor_hora + (f[i].salario_bruto/f[i].carga_horaria);

    }

    printf("\nTotal de Salarios brutos: %f",sum_salarios_brutos);
    printf("\nValor medio da hora da empresa: %f",sum_valor_hora/qtd_funcionarios);

}


