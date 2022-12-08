#include <stdio.h>
#include <stdlib.h>

void troca(int * x, int * y);
int main()
{
    int m=23423, n=10;
    int som=0,i;

    while(n > 0 && m > 0)
    {
        scanf("%d %d",&n,&m);
        troca(&n,&m);
        som=0;

        if ((m >0 ) && (n > 0))
        {
            for(i = n ; i<=m;i++)
                {
                    printf("%d ",i);
                    som = som + i;
                }
                printf("Sum=%d\n",som);
           
        }

    }

    return 0;
}

void troca(int * x, int * y)
{
    int aux;
    if ( *x > *y)
    {
        aux = *x;
        *x = *y;
        *y = aux;
    }
}