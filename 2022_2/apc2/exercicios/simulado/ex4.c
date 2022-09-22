#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int horas=0,minutos=0;

    scanf("%d",&n);

    horas = n / 3600;
    n = n - (horas * 3600);
    minutos = n /60;
    n = n - (minutos * 60);

    printf("\n %d:%d:%d",horas,minutos,n);

    return 0;
}