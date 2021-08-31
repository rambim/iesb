#include <stdio.h>
#include <stdlib.h>


int main()
{
    float peso;
    float altura;
    float imc;

    printf("\nDigite o seu peso: ");
    scanf("%f",&peso);
    printf("\nDigite o sua altura: ");
    scanf("%f",&altura);
    imc = peso/(altura*altura);
    altura=0;
    peso=0;
    printf("O IMC calculado e igual a %f ",imc);
    printf("\n");

    if (imc > 1) 
    {
        printf("\n Sua IMC é maior do que 1");

        if (altura > 2)
        {
            printf("\n E vc é bastante alto!");
        }

    }

    if (imc <= 1)
    {
        printf("\n Seu IMC é menor ou igual a  1");
    }
    else
    {
        printf("\n Seu IMC é maior que 1");
    }

    if (imc <= 1)
    {
        printf("\n Seu IMC é menor ou igual a  1");
        if (altura > 2)
        {
            printf("\n Muito alto!");
        }
    }
    else
    {
        printf("\n Seu IMC é maior que 1");
        if (peso<70)
        {
            printf("\n Peso muito baixo");
        }
        else
        {
            printf("\n Peso alto");
        }
    }

    return 0;

    


}
