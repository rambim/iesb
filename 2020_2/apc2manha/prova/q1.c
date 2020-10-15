

#include <stdio.h>
#include <stdlib.h>

int menu();


int main()
{
    int opcao;

    opcao = menu();

    printf("\n Opcao escolhida: %d",opcao);
    printf("\n");
    return 0;
}



int menu()
{
    int opcao;
    printf("\n1 - opcao 1");
    printf("\n2 - opcao 2");
    printf("\n3 - opcao 3");
    printf("\n4 - opcao 4");
    scanf("%d",&opcao);

    return opcao;
}
