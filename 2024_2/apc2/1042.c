#include <stdio.h>
#include <stdlib.h>


int main()
{
    
    int i,numeros[3];
    for(i=0;i<3;i++)
    {
        scanf("%d",&numeros[i]);
    }

    if (numeros[0] <= numeros[1]  && numeros[1] <= numeros[2])
    {
        printf("%d\n",numeros[0]);
        printf("%d\n",numeros[1]);
        printf("%d\n",numeros[2]);
    }

    if (numeros[0] <= numeros[2]  && numeros[2] <= numeros[1])
    {
        printf("%d\n",numeros[0]);
        printf("%d\n",numeros[2]);
        printf("%d\n",numeros[1]);
    }

    if (numeros[1] <= numeros[0]  && numeros[0] <= numeros[2])
    {
        printf("%d\n",numeros[1]);
        printf("%d\n",numeros[0]);
        printf("%d\n",numeros[2]);
    }

    if (numeros[1] <= numeros[2]  && numeros[2] <= numeros[0])
    {
        printf("%d\n",numeros[1]);
        printf("%d\n",numeros[2]);
        printf("%d\n",numeros[0]);
    }

    if (numeros[2] <= numeros[0]  && numeros[0] <= numeros[1])
    {
        printf("%d\n",numeros[2]);
        printf("%d\n",numeros[0]);
        printf("%d\n",numeros[1]);
    }

    if (numeros[2] <= numeros[1]  && numeros[1] <= numeros[0])
    {
        printf("%d\n",numeros[2]);
        printf("%d\n",numeros[1]);
        printf("%d\n",numeros[0]);
    }


    printf("\n");

    for(i=0;i<3;i++)
    {
        printf("%d\n",numeros[i]);
    }


    return 0;
}