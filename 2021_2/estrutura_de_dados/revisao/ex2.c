#include <stdio.h>
#include <stdlib.h>

int main()
{   

    int * ptr1;
    int * ptr2;

    ptr1 = (int*)malloc(sizeof(int));
    ptr2 = (int*)calloc(1,sizeof(int));

    printf("\n Conteudo de quem ptr1 aponta: %d",*ptr1);
    printf("\n Conteudo de quem ptr2 aponta: %d",*ptr2);

    free(ptr1);
    free(ptr2);

    ptr1 = (int*)malloc(sizeof(int)*10);
    ptr2 = (int*)calloc(10,sizeof(int));

    printf("\n");
    return 0;
}