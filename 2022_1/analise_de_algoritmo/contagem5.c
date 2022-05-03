#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int n = 500;
    int count =0;

    for (i = n; i >= 1; i = i / 3)
    {
        for (j = n; j >=1; j=j/3)
        {
            count++;
        }
    }

    printf("\n %d",count);
}


int funcao(int * vet, int n)
{
    int i,j;
    int count=0;

    for(i=0;i<n;i++)
    {
        if (i%2==0)
        {
            for(j=0;j<n;j=j+2)
            {
                count++;
            }
        }
        else
        {
            for(j=0;j<n*3;j++)
            {
                count++;
            }
        }
    }
    return count;
}