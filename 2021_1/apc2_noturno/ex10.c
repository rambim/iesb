#include <stdio.h>
#include <stdlib.h>
int funcao1(int c, int b, int a);
int main()
{
    int a,b,c;

    a = 3;
    b = 4;
    c = 5;

    c = funcao1(b,a,c);

    printf("\n %d %d %d",a,b,c);
    return 0;
}

int funcao1(int c, int b, int a)
{
    int sum=0;
    sum = a + b + c;
    a = a + 10;
    b = b + 20;
    c = c + 30;
    printf("\n %d %d %d",a,b,c);
    return sum;
}