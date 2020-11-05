#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    int i,j;
    
    printf("\nDigite a string: ");
    __fpurge(stdin); // linux
    // fflush(stdin); windows
    fgets(s,100,stdin);
    s[strlen(s)-1]= '\0';

    printf("%s",s);
    
    do
    {
        printf("\n Digite I: ");
        scanf("%d",&i);
        printf("\n Digite J: ");
        scanf("%d",&j);

        if (i<=0 || j<=0)
        {
            printf("Numeros invalidos, digite novamente");
        }
    } while (i<=0 || j<=0 || i>strlen(s) || j>strlen(s));

    int aux;

    if (i>j)
    {
        aux = i;
        i=j;
        j=aux;
    }

    for(aux=i;aux<=j;aux++)
    {
        printf("%c",s[aux]);
    }

    




}