#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=1,b=1,c=1,i;
    int n,t=0;
    a = b + c;
    for(i=0;i<10;i++)
    {
        if (i % a == 0)
        {
            printf("\n -> %d e par",i);
            t++;
        }
    }
    printf("\n : %d",t);
    return 0;
    
}