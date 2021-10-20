#include <stdio.h>
#include <stdlib.h>


int main()
{
    int qtd_total_segundos;
    int horas,minutos,segundos;

    scanf("%d",&qtd_total_segundos);

    horas = qtd_total_segundos / 3600;
    minutos = (qtd_total_segundos - (horas * 3600)) / 60;
    segundos = qtd_total_segundos -  (horas * 3600) - (minutos * 60);

    printf("%d:%d:%d",horas,minutos,segundos);

    printf("\n");
    return 0;
}


