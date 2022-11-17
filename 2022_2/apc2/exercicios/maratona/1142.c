#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,x=1;
    scanf("%d",&n);

    // for(i=1;i<=n;i++)
    // {
    //     printf("%d %d %d PUM\n",x,x+1,x+2);
    //     x = x + 4;
    // }

    for(x=1;x<=n*4;x++)
    {
        if (x%4==0)
        {
            printf("PUM\n");
        }
        else
        {
            printf("%d ",x);
        }
    }


    // printf("\n");
    return 0;
}