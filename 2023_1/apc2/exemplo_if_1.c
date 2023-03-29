#include <stdio.h>
int main()
{
    int x = 5;
    if (x < 5)
    {
        printf("O valor de x é menor que 5\n");
    }
    else
    {
        if (x > 5)
        {
            printf("O valor de x é maior que 5\n");
        }
        else
        {
            printf("O valor de x é igual a 5\n");
        }
    }
    return 0;
}
