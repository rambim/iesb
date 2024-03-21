#include <stdio.h>

void trocar(int * a, int * b);
int main()
{
    int a,b;

    printf("Digite o valor de a: \n");
    scanf("%d",&a);

    printf("Digite o valor de b: \n");
    scanf("%d",&b);

    trocar(&a,&b);

    printf("Valor de a: %d\n",a);
    printf("Valor de b: %d\n",b);
}



void trocar(int * a, int * b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
