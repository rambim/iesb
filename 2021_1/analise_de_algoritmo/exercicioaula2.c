/*

1) Implemente o bubblesort sequencial.
2) Implemente o bubble sort recursivo.
3) Demonstre a complexidade do algoritmo sequencial através da contagem de instruções ( Notação BIG O).
4) Demonstre a complexidade do algoritmo recursivo através da análise de recorrência. ( Notação BIG O).

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrar_vetor(int *vet, int tam);
void bubble(int *vet, int n);
void bubble_recursivo(int *vet, int n, int pass);

int main()
{
    srand(time(NULL));

    int vet[30], i;

    for (i = 0; i < 30; i++)
    {
        vet[i] = rand() % 100;
    }

    printf("\n Mostrando antes de ordenar: ");
    mostrar_vetor(vet, 30);

    // bubble(vet, 30);
    bubble_recursivo(vet, 30,0);

    printf("\n Mostrando depois de ordenar: ");
    mostrar_vetor(vet, 30);
}

void mostrar_vetor(int *vet, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("\n %d", vet[i]);
    }
}

void bubble(int *vet, int n)
{
    int pass, i, aux, trocou = 0;           

    for (pass = 0; pass < n - 1; pass++)    
    {
        trocou = 0;
        for (i = 0; i < n - pass - 1; i++)
        {
            if (vet[i] > vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                trocou = 1;
            }
        }

        if (!trocou)
            break;
    }
}

// 1 + 1 + 1 + (n)*dentro + (n) + 1
// dentro = 3 + (n) * dentro2 + (n)
// dentro2 = 5
// 1 + 1 + 1 + n(3+5n+n)
// 3 + n(3+6n)
// 3 + 3n + 6n²
// O(n²)




void bubble_recursivo(int *vet, int n, int pass)
{
    int i, aux, trocou = 0;

    if (pass >= n - 1)
        return;

    trocou = 0;
    for (i = 0; i < n - pass - 1; i++)
    {
        if (vet[i] > vet[i + 1])
        {
            aux = vet[i];
            vet[i] = vet[i + 1];
            vet[i + 1] = aux;
            trocou = 1;
        }
    }

    if (!trocou)
        return;
    bubble_recursivo(vet,n,pass+1);
}
