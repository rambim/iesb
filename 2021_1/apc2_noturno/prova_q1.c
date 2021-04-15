#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    int matricula;
    int cargo;
    float salario;
} funcionario;

void calcula_bonus(funcionario *vet, int tam);

int main()
{
    funcionario vet[10];
    int i;
    for(i=0;i<10;i++)
    {
        printf("\n Digite a matricula: ");
        scanf("%d",&vet[i].matricula);
        printf("\n Digite o salario: ");
        scanf("%f",&vet[i].salario);
        printf("\n Digite o cargo: ");
        scanf("%d",&vet[i].cargo);
    }

    calcula_bonus(vet,10);

    for(i=0;i<10;i++)
    {
        printf("\nMatricula: %d\tSalario: %f\t Cargo: %d",vet[i].matricula,vet[i].salario,vet[i].cargo);
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