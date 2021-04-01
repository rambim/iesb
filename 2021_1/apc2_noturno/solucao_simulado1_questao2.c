// Faça uma função que recebe por parâmetro o tempo de duração de uma
// fábrica expressa em segundos e retorna também por parâmetro esse tempo
// em horas, minutos e segundos.

#include <stdio.h>
#include <stdlib.h>


typedef struct tempo
{
    int horas;
    int minutos;
    int segundos;
}tempo;


tempo converte_tempo(int total_segundos);

int main(int argc, char * argv[])
{
    tempo retorno;
    int segundos;
    segundos = atoi(argv[1]);
    retorno = converte_tempo(segundos);
    printf("%d segundos equivalem a %d horas %d minutos e %d segundos",segundos,retorno.horas,retorno.minutos,retorno.segundos);
    printf("\n");
    return 0;
}

tempo converte_tempo(int total_segundos)
{
    tempo a;
    a.horas = total_segundos/3600;
    a.minutos = (total_segundos - (a.horas*3600))/60;
    a.segundos = (total_segundos - (a.horas*3600) - (a.minutos *60));
    return a;
}




