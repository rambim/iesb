#include <stdio.h>

int primo(int x);
int main()
{
    int n,i,j,a,b,cont;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        cont=0;
        scanf("%d",&a);
        scanf("%d",&b);

        for (j = a; j <= b; j++)
        {
            if (primo(j))
                cont++;
        }

        printf("%d\n",cont);
        
    }

    return 0;
}


int primo(int x)
{
    if (x==1 || x == 0)
        return 0;
    int divisor = 2;
    for(divisor=2;divisor<x;divisor++)
    {
        if (x%divisor==0)
        return 0;
    }
    return 1;
}