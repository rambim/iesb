#include <stdio.h>

int main(){
    int x=2,y=3;
    y = funcao1(x,y);
    printf("\n %d %d ",x,y);
}

int funcao1(int y, int x)
{
    y = y + 10;
    x = x + 30;
    funcao2(x,y);
    printf("\n %d %d",x,y);
    return (x*y);
}

void funcao2(int x , int y)
{
    y = 2;
    x = 3;
    printf("\n %d %d ",x,y );
}
