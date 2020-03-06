#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;

    printf("\n Digite o valor de X: ");
    scanf("%d", &x);

    if (x % 2 == 0)
    {
        printf("\n O numero eh par ");
    }

    if (x % 2 != 0)
    {

        printf("\n o numero eh impar");
    }

    printf("\n");
    return 0;
}