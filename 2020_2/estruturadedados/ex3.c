#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * ptr;
    int x;

    ptr = malloc(4);

    printf("\n Digite um valor inteiro: ");
    scanf("%d",ptr);

    printf("\n O numero lido foi %d",*ptr);

    printf("\n");
    return 0;
}