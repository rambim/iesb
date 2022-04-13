#include <stdio.h>
#include <stdlib.h>
#define n 2
void mostrar(int x);

int main()
{
    mostrar(n);
    return 0;
}

void mostrar(int x)
{
    if (x==0)  // 1
        return;
    int i;
    for(i=0;i<n;i++) // 1 + (n+1) + n
    {
        printf("\n OI"); // n * 1
    }
    mostrar(x-1); //1
}


// f(n) = c*n + f(n-1)
// 