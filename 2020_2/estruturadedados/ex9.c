#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x = 0;
    recursiva(x);
    return 0;
}

void recursiva(int x)
{
    if (x==3)
    {
        return;
    }

    recursiva(x+1);
    printf("%d",x);
}


push()
pop()
stackpop()
empty()


