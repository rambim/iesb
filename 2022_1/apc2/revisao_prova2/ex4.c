#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    x = func1(3);
    printf("\n %d",x);
    return 0;
}

int func1(int a){
    int x = a + 2;
    func2(a);
    return x;
}
void func2(int x)
{
    x = x + 1;
}

