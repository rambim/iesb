// Faça um procedimento que recebe, por parâmetro, a hora de inicio e a hora
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
}tempo;

tempo verifica_duracao(tempo inicial, tempo final);

int main()
{
    tempo inicial,final, duracao;

    printf("\n Digite o horario inicial do evento no formato HH:MM: ");
    scanf("%d:%d",&inicial.horas,&inicial.minutos);
    printf("\n Digite o horario final do evento no formato HH:MM: ");
    scanf("%d:%d",&final.horas,&final.minutos);

    duracao = verifica_duracao(inicial,final);

    printf("a duracao do evento foi de %d:%d ",duracao.horas,duracao.minutos);
    printf("\n");
    return 0;
}

tempo verifica_duracao(tempo inicial, tempo final)
{
    int minutos_inicial, minutos_final, minutos_duracao;
    tempo duracao;

    minutos_inicial = inicial.horas * 60 + inicial.minutos;
    minutos_final = final.horas * 60 + final.minutos;

    if (minutos_inicial <= minutos_final)
    {
        minutos_duracao = minutos_final - minutos_inicial;
    }
    else
    {
        minutos_duracao = ((24*60) - minutos_inicial) + minutos_final;
    }

    duracao.horas = (minutos_duracao /60 );
    duracao.minutos = minutos_duracao - (duracao.horas * 60) ;

    return duracao;

}