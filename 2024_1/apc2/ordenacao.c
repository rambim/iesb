#include <stdio.h>


int bubble(int * vet, int tam);
int main()
{
    int vet [] = { 1, 10, 2, 9, 3, 8, 4, 7 ,5 ,6, -400, 152, 100};

    bubble(vet,13);

    int i;

    for(i=0;i<12;i++)
    {
        printf(" %d",vet[i]);
    }
}

int bubble(int * vet, int tam)
{
    int pass,i;
    int trocou=1;
    int aux;

    for(pass=0;pass<tam-1 && trocou;pass++)
    {
        trocou =0;
        for(i=0;i<tam-1-pass;i++)
        {
            if (vet[i] > vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                trocou=1;
            }
        }
    }
}