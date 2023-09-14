#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,som=0,aux;
    int i;

    scanf("%d",&x);
    scanf("%d",&y);

    // x menor
    // y maior
    if (x > y ){
        aux = x;
        x = y;
        y = aux;
    }


    for(i= x + 1;i<y;i++)
    {
        if (i % 2 !=0){
            som = som + i;
        }
    }

    printf("%d\n",som);

}

