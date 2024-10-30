#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n=1;

    long int a = n*100;
    long int b = 3*n*n;

    do
    {
        n++;
        a = n*100;
        b = 3*n*n;
    }while(b<a);


    printf("%d ",n);

}


