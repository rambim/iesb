/*
Utilizando como base a estrutura acima:



a) Construa uma função que recebe por parâmetro o endereço de um funcionário e solicite ao usuário que preencha o conteúdo das variáveis matricula, salário_bruto e carga_horaria;



b) Na sua função principal:

Declare um funcionário de nome Jack e solicite o preenchimento de seus dados ao usuário utilizando a função criada na letra a).
Mostre na tela a matrícula, o salário bruto e a carga horário de Jack

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    long int matricula;
    float salario_bruto;
    int carga_horaria;
}funcionario;

void preenche_funcionario(funcionario * f);

int main()
{
    funcionario Jack;
    preenche_funcionario(&Jack);

    printf("\n Matricula do Jack    : %ld",Jack.matricula);
    printf("\n Salario bruto do Jack: %f",Jack.salario_bruto);
    printf("\n Carga horaria do Jack: %d",Jack.carga_horaria);
    return 0;
}

void preenche_funcionario(funcionario * f)
{
    printf("\nDigite a matricula do funcionario: ");
    scanf("%ld",&f->matricula);
    printf("\nDigite o salario bruto do funcionario: ");
    scanf("%f",&f->salario_bruto);
    printf("\nDigite a carga horaria do funcionario: ");
    scanf("%d",&f->carga_horaria);
}