#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    int matricula;
    float salario;
    int cargo;
} funcionario;

void calcula_bonus(funcionario *vet, int tam);

int main()
{
    funcionario funcionarios[10];
    int i;

    for(i=0;i<10;i++)
    {
        printf("\n Digite a matricula: ");
        scanf("%d",&funcionarios[i].matricula);
        printf("\n Digite a salario: ");
        scanf("%f",&funcionarios[i].salario);
        printf("\n Digite o cargo: ");
        scanf("%d",&funcionarios[i].cargo);
    }

    calcula_bonus(funcionarios,10);

    for(i=0;i<10;i++)
    {
        printf("\nMatricula: %d Salario %f Cargo: %d",funcionarios[i].matricula,funcionarios[i].salario,funcionarios[i].cargo);
    }


    printf("\n");
    return 0;
}

void calcula_bonus(funcionario *vet, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        switch (vet[i].cargo)
        {
        case 1:
            vet[i].salario = vet[i].salario * 1.15;
            break;
        case 2:
            vet[i].salario = vet[i].salario * 1.10;
            break;
        case 3:
            vet[i].salario = vet[i].salario * 1.05;
            break;
        default:
            break;
        }
    }
}