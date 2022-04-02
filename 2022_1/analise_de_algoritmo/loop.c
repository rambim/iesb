#include <stdio.h>
#include <stdlib.h>
#define n 3

void mostrar(int x);

int main()
{
    int i;

    mostrar(n);
    return 0;
}

void mostrar(int x)
{
    if (x == 0) // 1
        return ;
    printf("\n OI"); // 1+
    mostrar(x-1);  // f(n-1)
}

//f(n) = c + f(n-1)

//     = c + (c + f(n-2))
//     = c + (c + (c + f(n-3)))
//     = kc + f(n-k)
//    n-k = 1
//     k = n - 1;

//      = (n-1)c + 1
//      f(n)=  cn - c + 1;

        //    O(n) 