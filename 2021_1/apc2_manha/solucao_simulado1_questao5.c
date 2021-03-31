// 14. Faça um procedimento que recebe, por parâmetro, a hora de inicio e a hora
// de término de um jogo, ambas subdivididas em 2 valores distintos: horas e
// minutos. O procedimento deve retornar, também por parâmetro, a duração do
// jogo em horas e minutos, considerando que o tempo máximo de duração de
// um jogo é de 24 horas e que o jogo pode começar em um dia e terminar no
// outro.

#include <stdio.h>
#include <stdlib.h>

typedef struct tempo
{
    int horas;
    int minutos;
} tempo;

tempo calcula_duracao(tempo inicial, tempo final);

int main()
{
    tempo inicial, final, duracao;

    printf("\n Digite no formato HH:MM o horario inicial: ");
    scanf("%d:%d", &inicial.horas, &inicial.minutos);
    printf("\n Digite no formato HH:MM o horario final: ");
    scanf("%d:%d", &final.horas, &final.minutos);

    duracao = calcula_duracao(inicial, final);

    printf("\n Duracao do evento: %d:%d",duracao.horas,duracao.minutos);

    printf("\n");
    return 0;
}

tempo calcula_duracao(tempo inicial, tempo final)
{
    tempo retorno;
    int total_inicial, total_final, duracao_minutos;

    total_inicial = (inicial.horas * 60) + inicial.minutos;
    total_final = (final.horas * 60) + final.minutos;

    if ((inicial.horas < final.horas) || (inicial.horas == final.horas && inicial.minutos < final.minutos))
    {
        duracao_minutos = total_final - total_inicial;
    }
    else
    {
        duracao_minutos = ((1440 - total_inicial) + total_final);
    }

    retorno.horas = duracao_minutos / 60;
    retorno.minutos = duracao_minutos - (retorno.horas * 60);

    return retorno;
}