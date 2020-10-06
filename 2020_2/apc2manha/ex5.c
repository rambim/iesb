#include <stdio.h>

int funcao1( int x);
void funcao2(int * x);
int main()
{
    int x=2,resposta;

    resposta = funcao1(x);

    printf("\n %d",resposta);    
    printf("\n");
    return 0;

}
int funcao1( int x)
{
    int y;
    y = x + 3;
    funcao2(&x);
    printf("\n %d",x);
    return y;
}
void funcao2(int * x)
{
    *x = 20;
}

