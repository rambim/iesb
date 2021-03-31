// 5. Faça uma função que recebe por parâmetro o tempo de duração de uma
// fábrica expressa em segundos e retorna também por parâmetro esse tempo
// em horas, minutos e segundos.

#include <stdio.h>
#include <stdlib.h>

typedef struct tempo
{
    int horas;
    int minutos;
    int segundos;
} tempo;

tempo calcula_tempo(int segundos);

int main()
{
    tempo a;

    a = calcula_tempo(3665);

    printf("\nHoras %d Minutos %d Segundos %d",a.horas,a.minutos,a.segundos);
    return 0;
}

tempo calcula_tempo(int segundos)
{
    tempo total;

    total.horas = segundos / 3600;
    total.minutos = (segundos - (total.horas * 3600)) / 60;
    total.segundos = (segundos - (total.horas * 3600) - (total.minutos * 60));

    return total;
}
