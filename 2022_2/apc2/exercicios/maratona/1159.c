#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, som, qtd_pares;

    do
    {
        scanf("%d", &x);
        if (x != 0)
        {
            som = 0;
            qtd_pares = 0;
            while (qtd_pares < 5)
            {
                if (x % 2 == 0)
                {
                    som = som + x;
                    qtd_pares++;
                }
                x++;
            }
            printf("%d\n", som);
        }

    } while (x != 0);

    return 0;
}