#include <stdio.h>
#include <stdlib.h>



float recupera_valor_reajuste (float salario);


int main()
{

    float salario, novo_salario, valor_reajuste;
    scanf("%f",&salario);
    float p_reajuste = recupera_valor_reajuste(salario);

    valor_reajuste = p_reajuste/100 * salario;
    novo_salario = salario + valor_reajuste;

    printf("Novo salario: %.2f\n",novo_salario);
    printf("Reajuste ganho: %.2f\n",valor_reajuste);
    printf("Em percentual: %.0f %%\n",p_reajuste);

    return 0;
}


float recupera_valor_reajuste (float salario)
{
    if (salario >=0 && salario <= 400)
    {
        return 15;    
    }
    else
    {
        if (salario > 400 && salario <= 800)
        {
            return 12;
        }
        else
        {
            if (salario > 800 && salario <= 1200)
            {
                return 10;
            }
            else
            {
                if (salario > 1200 && salario <=2000)
                {
                    return 7;
                }
                else
                {
                    if (salario > 2000)
                    {
                        return 4;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
    }
}