#include <stdio.h>


void funcao1(int c, int *b, int a);
void funcao2(int *c,int b, int * a);

int main()
{
    int a=2,b=3,c=4;
    int i=0;

    while(i<5)
    {
        if (i%2==0)
        {
            funcao1(a,&b,c);
        }
        else
        {
            funcao2(&a,b,&c);
        }
        i++;
        
    }
    printf("\n %d \n",a+b+c);
    return 0;
}


void funcao1(int c, int *b, int a)
{
    c = c+ 1;
    a = c + 2;
    *b = *b +a+c;
}

void funcao2(int *c,int b, int * a)
{
    *c = *c + *a;
    *a = *a + 5;
    b = *a + *c;   

}

