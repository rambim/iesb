#include <stdio.h>
#include <stdlib.h>

void funcao1(int a,int b, int c);
int main()
{
    int a,b,c;

    a = 2;
    b = a + 1;
    c = b + 2;

    funcao1(a,b,c);

    printf("\n%d %d %d",a,b,c);
    
    return 0;

}

void funcao1(int a,int b, int c)
{
    a = a * 2;
    b = b * 2;
    c = c * 2;
}