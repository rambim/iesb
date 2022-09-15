#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i;
    int qtd=0;

    for(i=10;i>1;i++)
    {
        printf("\n\n AMOR!\n\n");
        qtd++;
        i = i - 2;
    }

    printf("\n %d",qtd);
    return 0;
}