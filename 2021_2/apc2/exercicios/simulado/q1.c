#include <stdio.h>
#include <stdlib.h>

float define_faixa(float salario);

int main()
{

    float salario,imposto;
    scanf("%f",&salario);

    imposto = define_faixa(salario);
    printf("R$ %.2f",imposto);
    printf("\n");
    return 0;
}

float define_faixa(float salario)
{
    float aux;
    if (salario<=2000)
        return 0;
    
    if (salario<=3000)
    {
        aux = salario - 2000;
        return aux * 0.08;
    }

    if (salario<=4500)
    {
        aux = salario - 3000;
        return (0.08 * 1000) + (aux * 0.18);
    }

    if (salario>4500)
    {
        aux = salario - 4500;
        return (0.08 * 1000) + (0.18 * 1500) + (aux * 0.28);
    }
    return 0;
}

