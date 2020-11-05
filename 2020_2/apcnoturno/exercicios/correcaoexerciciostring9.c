#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    char c;
    int i;
    int j;
    int achou;

    printf("\n Digite uma string: ");
    __fpurge(stdin);
    fgets(s,100,stdin);
    printf("\n Digite um caracter: ");
    scanf("%c",&c);
    printf("\n Digite uma posicao: ");
    scanf("%d",&i);

    achou=0;
    for(j=i;j<strlen(s) && !achou ;j++)
    {
        if (s[j]==c)
        {
            printf("A primeira ocorrencia do caracter %c no texto e na posicao %d ",c,j);
            achou=1;
        }
    }

    return 0;
}