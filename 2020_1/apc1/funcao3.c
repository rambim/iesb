#include <stdio.h>
#include <stdlib.h>

int funcao1(int x, int y, int z);

int main()
{
    int a=2,b=3,c=4,d;

    while(b<10)
    {
        d = funcao1(a,b,c);
        b = b + d;
        printf("%d ",a);
    }
    printf("%d %d %d",a,b,c);
    return 0;
}

int funcao1(int x, int y, int z)
{
    int retorno;
    x = x + 1;
    y = y + 1;
    z = z + 1;
    retorno = x + y + z;
    printf("%d %d %d ",x,y,z);
    return retorno;

}





