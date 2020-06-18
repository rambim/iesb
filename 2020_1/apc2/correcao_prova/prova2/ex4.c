/*


escolha um jogo de cartas, baseado  em um baralho tradicional ( cada carta tem seu naipe e seu valor) 
ou tipo super trunfo ( cada carta possui um conjunto de atributos).
implemente a parte de distribuição ( sorteio) de cartas para 2 jogadores, considerando que cada jogador
irá receber 5 cartas. Exiba na tela as cartas que cada um dos jogadores recebeu

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <time.h>

typedef struct carta
{
    int valor; // 1 a 13
    int naipe; // 1 4
} carta;


void mostra_carta(carta c);
void monta_baralho(carta *baralho);
void mostra_baralho(carta *baralho);
void emabaralha_baralho(carta * baralho);
void mostrar_mao (carta * mao);
int main()
{

    srand(time(NULL));
    carta baralho[52];
    carta cartas_p1[5], cartas_p2[5];
    monta_baralho(baralho);
    emabaralha_baralho(baralho);
    cartas_p1[0] = baralho[0];
    cartas_p2[0] = baralho[1];
    cartas_p1[1] = baralho[2];
    cartas_p2[1] = baralho[3];
    cartas_p1[2] = baralho[4];
    cartas_p2[2] = baralho[5];
    cartas_p1[3] = baralho[6];
    cartas_p2[3] = baralho[7];
    cartas_p1[4] = baralho[8];
    cartas_p2[4] = baralho[9];
    
    printf("\n Cartas do P1: ");
    mostrar_mao(cartas_p1);
    printf("\n Cartas do P2: ");
    mostrar_mao(cartas_p2);
    return 0;
}

void monta_baralho(carta *baralho)
{
    int i, j, x = 0;
    for (i = 1; i <= 13; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            baralho[x].valor = i;
            baralho[x].naipe = j;
            x++;
        }
    }
}

void mostra_baralho(carta *baralho)
{
    int i;

    for (i = 0; i < 52; i++)
    {
        mostra_carta(baralho[i]);
    }
}

void emabaralha_baralho(carta * baralho)
{
    int i=0;
    int aux;
    carta carta_aux;

    for(i=0;i<52;i++)
    {
        aux = rand() % 52;
        carta_aux = baralho[i];
        baralho[i] = baralho[aux];
        baralho[aux] = carta_aux;
    }
}

void mostra_carta(carta c)
{

    switch (c.naipe)
    {
    case 1:
        printf("\n");
        printf("\n ----------- ");
        if (c.valor == 1)
        {
            printf("\n |  A ouro   |");
        }
        else
        {
            printf("\n |  %d  ouro  |", c.valor);
        }

        printf("\n |           |");
        printf("\n |           |");
        printf("\n |           |");
        printf("\n  ----------- ");
        break;
    case 2:
        printf("\n");
        printf("\n  ----------- ");
        if (c.valor == 1)
        {
            printf("\n |  A espa   |");
        }
        else
        {
            printf("\n |  %d  espa  |", c.valor);
        }
        printf("\n |           |");
        printf("\n |           |");
        printf("\n |           |");
        printf("\n  ----------- ");
        break;
    case 3:
        printf("\n");
        printf("\n  ----------- ");
        if (c.valor == 1)
        {
            printf("\n |  A copas  |");
        }
        else
        {
            printf("\n |  %d  copas |", c.valor);
        }
        printf("\n |           |");
        printf("\n |           |");
        printf("\n |           |");
        printf("\n  ----------- ");
        break;
    case 4:
        printf("\n");
        printf("\n  ----------- ");
        if (c.valor == 1)
        {
            printf("\n |  A paus   |");
        }
        else
        {
            printf("\n |  %d  paus  |", c.valor);
        }
        printf("\n |           |");
        printf("\n |           |");
        printf("\n |           |");
        printf("\n  ----------- ");
        break;
    default:
        printf("\n Carta invalida");
        break;
    }
    printf("\n\n ");

}

void mostrar_mao (carta * mao)
{
    int i=0;
    for(i=0;i<5;i++)
    {
        mostra_carta(mao[i]);
    }
}
