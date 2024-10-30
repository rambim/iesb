#include <stdio.h>
#include <stdlib.h>

void mostrar_vetor(int *vet, int tam);
void bubble1(int *vet, int tam);
void bubble2(int *vet, int tam);
void bubble3(int *vet, int tam);
void bubble4(int *vet, int tam, int pass);
void mostrar_vetor(int *vet, int tam);

int main()
{
    int vet[] = {1, 10, 2, 8, 3, 7, 5};

    long int tam = sizeof(vet) / sizeof(int);

    printf("Tamanho do vetor : %ld\n", tam);

    mostrar_vetor(vet, tam);
    bubble1(vet, tam);
    // bubble2(vet, tam);
    // bubble3(vet, tam);
    // bubble4(vet, tam, 0);
    mostrar_vetor(vet, tam);
}

void bubble1(int *vet, int tam)
{
    int pass, i, aux;
    for (pass = 0; pass < tam - 1; pass++)
    {
        for (i = 0; i < tam - 1; i++)
        {
            if (vet[i] > vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
            }
        }
    }
}

void bubble2(int *vet, int tam)
{
    int pass, i, aux;
    for (pass = 0; pass < tam - 1; pass++)
    {
        for (i = 0; i < tam - 1 - pass; i++)
        {
            if (vet[i] > vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
            }
        }
    }
}

void bubble3(int *vet, int tam)
{

    int pass, i, aux;
    int trocou = 1;
    for (pass = 0; pass < tam - 1 && trocou; pass++)
    {
        trocou = 0;
        for (i = 0; i < tam - 1 - pass; i++)
        {
            if (vet[i] > vet[i + 1])
            {
                trocou = 1;
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
            }
        }
    }
}

void bubble4(int *vet, int tam, int pass)
{

    if (pass >= tam - 1)
        return;

    int i, aux;
    for (i = 0; i < tam - 1 - pass; i++)
    {
        if (vet[i] > vet[i + 1])
        {
            aux = vet[i];
            vet[i] = vet[i + 1];
            vet[i + 1] = aux;
        }
    }
    bubble4(vet,tam,pass+1);
}

void mostrar_vetor(int *vet, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}