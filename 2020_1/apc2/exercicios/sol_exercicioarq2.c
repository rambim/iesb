#include <stdio.h>
#include <stdlib.h>


int primo(int x);

int main()
{
    int idade;
    FILE *arq;

    int i;
    printf("\n Digite sua idade: ");
    scanf("%d", &idade);

    arq = fopen("primos.txt", "w");

    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        for (i = 1; i <= idade; i++)
        {
            if (primo(i))
            {
                fprintf(arq,"%d\n", i);
            }
        }
        fclose(arq);

    }

    return 0;
}

int primo(int x)
{
    int divisor = 2;

    if (x < 0)
    {
        x = x * (-1);
    }

    if (x == 1)
    {
        return 0;
    }

    for (divisor = 2; divisor < x; divisor++)
    {
        if (x % divisor == 0)
        {
            return 0;
        }
    }

    return 1;
}