#include <stdio.h>

int perfeito ( int x);
int main()
{
    int n,i,a;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a);

        if (perfeito(a))
        {
            printf("perfeito\n");
        }
        else{
            printf("nao perfeito\n");
        }
    }



    return 0;
}


int perfeito ( int x)
{
    int i,som=0;

    for(i=1;i<x;i++)
    {
        if (x%i==0)
        {
            som = som + i;
        }

    }

    if (som == x)
        return 1;
    else
        return 0;

}