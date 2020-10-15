#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    long int matricula;
    float salario_bruto;
    int carga_horaria;
}funcionario;

void preenche(funcionario * f);

int main()
{
    funcionario Jack;
    preenche(&Jack);
    printf("\n Matricula do Jack    : %ld",Jack.matricula);
    printf("\n Salario bruto do Jack: %f",Jack.salario_bruto);
    printf("\n Carga horaria do Jack: %d",Jack.carga_horaria);
    printf("\n");
    return 0;
}


void preenche(funcionario * f)
{
    printf("\nDigite a matricula do funcionario: ");
    scanf("%ld",&f->matricula);
    printf("\nDigite o salario bruto do funcionario: ");
    scanf("%f",&f->salario_bruto);
    printf("\nDigite a carga horaria do funcionario: ");
    scanf("%d",&f->carga_horaria);
}