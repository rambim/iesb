#include <stdio.h>

int main()
{
    int vet[] = {5, 2, 8, 1, -9, 0, 4, 2, 15, 7};

    int x,i;
    int encontrou=0;

    printf("\n Digite um numero a ser buscado: ");
    scanf("%d",&x);

    for(i=0;i<sizeof(vet)/sizeof(int) && !encontrou;i++)
    {
        if (* (vet + i) == x)
        {
            printf("\n Encontrei! = %d",vet + i);
            encontrou = 1;
            
        }
    }

    if (!encontrou)
    {
        printf("\n Nao encontrou");
    }

    return 0;
}