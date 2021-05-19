#include <stdio.h>
#include <stdlib.h>



int main()
{
    int * vet,i;

    // vet = (int*)malloc(sizeof(int)*100);

    // for(i=0;i<100;i++)
    // {
    //     vet[i]=0;
    // }

    vet  = (int*)calloc(100,sizeof(int));

    for(i=0;i<100;i++)
    {
        printf("%d ",vet[i]);
    }

    free(vet);

    printf("\n");
    return 0;
}

