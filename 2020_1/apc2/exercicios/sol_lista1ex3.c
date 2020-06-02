#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i, j;

    printf("\nDigite N: ");
    scanf("%d", &n);

    for (j = 1; j <= (n / 2 + 1); j++)
    {
        for(i=1;i<j;i++)
        {
            printf("  ");
        }
        
        for (i = i; i <= n-(j-1); i++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
}