#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;

    printf("\n Digite A: ");
    scanf("%d",&a);
    printf("\n Digite B: ");
    scanf("%d",&b);

    if (a>b)
    {
        printf("\n O maior e %d",a);
    }
    else
    {
        if (b>a)
        {
            printf("\n O maior deles e %d",b);
        }
        else
        {
            printf("\n Os numeros sao iguais");
        }
    }

}