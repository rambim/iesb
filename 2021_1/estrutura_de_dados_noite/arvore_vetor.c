#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrar_vetor(int *vet, int tam);
void incluir_sequencial(int *vet, int tam, int *qtd_elementos, int x);
int buscar_numero_sequencial(int *vet, int tam, int procurado);
void incluir_arvore(int *vet, int tam, int *qtd_elementos, int x);
int buscar_numero_arvore(int *vet, int tam, int procurado);
void delay();

int main()
{
    srand(time(NULL));

    clock_t t1, t2; // duas variáveis para guardar o registro clock
    int *vet1, *vet2;
    int qtd_elementos_1 = 0, qtd_elementos_2 = 0, i, procurado, retorno, inserido;
    float diff;

    int tamanho = 50000;

    vet1 = (int *)calloc(tamanho, sizeof(int));
    vet2 = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < 200; i++)
    {
        inserido = rand() % 1000;
        incluir_sequencial(vet1, tamanho, &qtd_elementos_1, inserido);
        incluir_arvore(vet2, tamanho, &qtd_elementos_2, inserido);
    }
    incluir_sequencial(vet1, tamanho, &qtd_elementos_1, 500);
    incluir_arvore(vet2, tamanho, &qtd_elementos_2, 500);

    procurado = 500;

    printf("\n Mostrando primeiro vetor: ");
    mostrar_vetor(vet1, qtd_elementos_1);

    t1 = clock(); // pega esse instante
    retorno = buscar_numero_sequencial(vet1, qtd_elementos_1, procurado);
    t2 = clock(); // pega esse instante
    if (retorno)
    {
        printf("\n Numero esta no vetor");
    }
    else
    {
        printf("\n Numero nao esta no vetor");
    }
    diff = (((float)t2 - (float)t1) / 1000000.0F); // mile segundos

    printf("\nTempo gasto: %f", diff);

    printf("\n Mostrando segundo vetor: ");
    mostrar_vetor(vet2, 200);

    t1 = clock(); // pega esse instante
    retorno = buscar_numero_arvore(vet2, tamanho, procurado);
    t2 = clock(); // pega esse instante
    if (retorno)
    {
        printf("\n Numero esta no vetor");
    }
    else
    {
        printf("\n Numero nao esta no vetor");
    }
    diff = (((float)t2 - (float)t1) / 1000000.0F); // mile segundos

    printf("\nTempo gasto: %f", diff);
    printf("\n");

    return 0;
}

void incluir_sequencial(int *vet, int tam, int *qtd_elementos, int x)
{
    if (*qtd_elementos >= tam)
    {
        printf("\n Vetor cheio");
        return;
    }

    vet[*qtd_elementos] = x;
    (*qtd_elementos)++;
}

void incluir_arvore(int *vet, int tam, int *qtd_elementos, int x)
{
    int i = 0;
    int inseriu = 0;

    while (!inseriu)
    {
        if (vet[i] == 0)
        {
            vet[i] = x;
            inseriu = 1;
            (*qtd_elementos)++;
        }
        else
        {
            if (x < vet[i])
            {
                i = i * 2 + 1;
            }
            else
            {
                i = i * 2 + 2;
            }

            if (i > tam)
            {
                printf("\n Numero nao pode ser inserido");
                return;
            }
        }
    }
}

void mostrar_vetor(int *vet, int tam)
{
    int i;
    printf("\nVetor: ");
    for (i = 0; i < tam; i++)
        printf(" %d", vet[i]);
}

int buscar_numero_sequencial(int *vet, int tam, int procurado)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        delay();
        if (vet[i] == procurado)
        {
            return 1;
        }
    }
    return 0;
}
int buscar_numero_arvore(int *vet, int tam, int procurado)
{
    int i = 0;
    int encontrou = 0;

    while (!encontrou)
    {
        delay();
        if (vet[i] == procurado)
        {
            return 1;
        }
        else
        {
            if (procurado < vet[i])
            {
                i = i * 2 + 1;
            }
            else
            {
                i = i * 2 + 2;
            }

            if (i>tam)
            {
                printf("\n Numero nao esta no vetor");
                return 0;
            }
        }
    }
    return 0;
}

void delay()
{
    int i, j, z;
    for (i = 0; i < 10000; i++)
    {
        for (j = 0; j < 10000; j++)
        {
            z = 1;
        }
    }
}
