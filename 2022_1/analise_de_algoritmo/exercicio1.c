// Diga qual será a quantidade de operações realizadas para as seguintes instâncias do problema:



#include <stdio.h>
#include <stdlib.h>
#define TAM1 10
#define TAM2 10
// a) vet[1,2,3,4,5,6,7,8,9,10]
// b) vet[10,20,30,40,50,60,70]
// c) vet[1,3,5,7,9,11,13,15,17]
int main()
{
    int i,j,x; // 0
    int vet[]=x; // 1

    for(i=0;i<TAM1;i++) // 1 + (TAM1+1) + TAM1
    {
        if (vet[i]%3==0) // TAM1
        {
            for(j=0;j<TAM2;j++) // (1 + (TAM2 + 1) + TAM2) * QTD_M3
            {
                printf("\n Senhor"); //TAM2 * QTD_M3
            }
        }
        else
        {
            printf("\n Gzuz"); // 1 * QTD_NM3
        }
    }
}

// 0 + 1 + (1 + (TAM1+1) + TAM1) + (TAM1) 
// + ((1 + (TAM2 + 1) + TAM2) * QTD_M3) + (TAM2 * QTD_M3) + ( 1 * QTD_NM3)

// a) tam = 10, QTD_M3 = 3, QTD_NM3 = 7

// 0 + 1 + (1 + (10+1) + 10) + (10) 
// + ((1 + (10 + 1) + 10) * 3) + (10 * 3) + ( 1 * 7)

// 0 + 1 + (22) + (10) 
// + (66) + (30) + (7)  = 136



// b) tam = 7, QTD_m3 = 2, QTD_NM3 = 5

// 0 + 1 + (1 + (7+1) + 7) + (7) 
// + ((1 + (7 + 1) + 7) * 2) + (7 * 2) + ( 1 * 5)

// 0 + 1 + (16) + (7) 
// + (32) + (14) + ( 5) = 75



// c) tam = 9, QTD_m3 = 3, QTD_NM3 = 6
// 0 + 1 + (20) + (9) 
// + (60) + (27) + (6) = 123

