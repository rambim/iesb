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
