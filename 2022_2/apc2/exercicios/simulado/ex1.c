/*

construa uma função que recebe por parÂmetro um número e retorne
1 caso ele seja perfeito ou zero caso ele não seja perfeito.

na sua função principal ,solicite 10 números ao usuário e após lido
os 10 números diga quantos e quais são perfeitos.

*/

#include <stdio.h>
#include <stdlib.h>

int perfeito(int numero);

int main()
{
    int i;
    int qtd_perfeitos=0;

    // versao com vetor
    // int numero[10];
    // for (i = 0; i < 10; i++)
    // {
    //     scanf("%d",&numero[i]);

    // }
    // for (i = 0; i < 10; i++)
    // {
    //     if(perfeito(numero[i]))
    //     {
    //         printf("%d e perfeito\n",numero[i]);
    //         qtd_perfeitos++;
    //     }
    // }

    //versao sem vetor
    int numero;
    for (i = 0; i < 10; i++)
    {
        scanf("%d",&numero);
        if(perfeito(numero))
        {
            printf("%d e perfeito\n",numero);
            qtd_perfeitos++;
        }
    }



    printf("\n Total de perfeitos: %d",qtd_perfeitos);
    
    perfeito(10);
    printf("\n");
    return 0;
}


int perfeito(int numero)
{

    int i;
    int som=0;

    for(i=1;i<numero;i++)
    {
        if (numero%i==0)
        {
            // printf("\n %d eh divisor de %d",i,numero);
            som = som + i;
        }
    }

    // printf("\n Somatorio dos divisores do numero %d = %d",numero,som);
    if (som==numero)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

