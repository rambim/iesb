#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    int sum=0;
    int prd=1;
    int i=0;


    do
    {
        printf("\nDigite x: ");
        scanf("%d",&x);
        printf("\nDigite Y: ");
        scanf("%d",&y);

        if (x>y)
        {
            printf("\n X maior que Y, digite novamente");
        }
    } while (x>=y);

    for(i=x;i<=y;i++)
    {
        if (i%2==0)
        {
            sum = sum + i;
        }
        else
        {
            prd = prd * i;
        }
        
    }

    printf("\nSomatorio: %d",sum);
    printf("\nProduto  : %d",prd);
    printf("\n");

    

}