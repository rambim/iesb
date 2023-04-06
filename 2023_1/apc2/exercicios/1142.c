#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    scanf("%d",&n);

    for(i=1;i<=n*4;i++)
    {
        if (i%4==0)
        {
            printf("PUM\n");
        }
        else
        {
            printf("%d ",i);
        }
    }

    
}