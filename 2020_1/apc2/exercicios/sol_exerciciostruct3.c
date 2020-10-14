//exerciciostruct3.c
/*

Faça um programa que armazene em um registro de dados (estrutura composta) os da-dos 
de um funcionario de uma empresa, compostos de: Matricula, Idade, Sexo (1 - M/2 - F), 
CPF,Data de Nascimento( outra struct), Codigo do Setor onde trabalha (0-99), 
 e Salário.  
 Os dados devem ser digitados pelo usuário, armazenadosna estrutura e exibidos na tela.

 */

#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct funcionario
{
    long int matricula;
    int idade;
    int sexo;
    long int cpf;
    struct data nascimento;
    int cod_setor;
    float salario;
} funcionario;

void preenche_funcionario1(funcionario *a);
funcionario preenche_funcionario2();
void mostrar_funcionario(funcionario a);
void preenche_vet_funcionarios( funcionario * vet, int qtd);

int main()
{
    int i;
    funcionario time[30];

    preenche_vet_funcionarios(time,10);

    for(i=0;i<10;i++)
    {
        preenche_funcionario1(&time[i]);
        time[i] = preenche_funcionario2();
    }



    





    return 0;
}

void preenche_funcionario1(funcionario *a)
{
    printf("\n Digite a matricula do funcionario: ");
    scanf("%ld", &a->matricula);
    printf("\n Digite a idade do funcionario: ");
    scanf("%d", &a->idade);
    printf("\n Digite o sexo 1 - Masculino 2 - Feminino: ");
    scanf("%d", &a->sexo);
    printf("\n Digite o cpf do funcionário: ");
    scanf("%ld", &a->cpf);
    printf("\n Digite a data de nascimento no formato (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &a->nascimento.dia, &a->nascimento.mes, &a->nascimento.ano);
    printf("\n Digite o codigo do setor: ");
    scanf("%d", &a->cod_setor);
    printf("\n Digite o salario: ");
    scanf("%f", &a->salario);
}

funcionario preenche_funcionario2()
{
    funcionario x;
    printf("\n Digite a matricula do funcionario: ");
    scanf("%ld", &x.matricula);
    printf("\n Digite a idade do funcionario: ");
    scanf("%d", &x.idade);
    printf("\n Digite o sexo 1 - Masculino 2 - Feminino: ");
    scanf("%d", &x.sexo);
    printf("\n Digite o cpf do funcionário: ");
    scanf("%ld", &x.cpf);
    printf("\n Digite a data de nascimento no formato (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &x.nascimento.dia, &x.nascimento.mes, &x.nascimento.ano);
    printf("\n Digite o codigo do setor: ");
    scanf("%d", &x.cod_setor);
    printf("\n Digite o salario: ");
    scanf("%f", &x.salario);

    return x;
}

void mostrar_funcionario(funcionario a)
{
    printf("\n Funcionario:");
    printf("\n Matricula: %ld", a.matricula);
    printf("\n Idade    : %d ", a.idade);
    printf("\n Sexo     : %d ", a.sexo);
    printf("\n CPF      : %ld", a.cpf);
    printf("\n Dt nasc. : %d/%d/%d", a.nascimento.dia, a.nascimento.mes, a.nascimento.ano);
    printf("\n Setor    : %d", a.cod_setor);
    printf("\n Salario  : %f", a.salario);
}

void preenche_vet_funcionarios( funcionario * vet, int qtd)
{
    int i;

    for(i=0;i<qtd;i++)
    {
        // preenche_funcionario1(&vet[i]);
        vet[i] = preenche_funcionario2();
    }

}