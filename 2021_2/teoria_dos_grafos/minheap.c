#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int vertice;
    int distancia;
} elemento;

elemento heap[1000];

int count_min_heap = 0;

int define_filho_esquerda(int indice)
{
    return indice * 2;
}

int define_filho_direita(int indice)
{
    return (indice * 2) + 1;
}

int define_pai(int indice)
{
    return indice / 2;
}

void subir_minimo(int indice)
{

    elemento aux;

    if (indice <= 1)
        return;

    int pai = define_pai(indice);

    if (heap[indice].distancia < heap[pai].distancia)
    {
        aux = heap[indice];
        heap[indice] = heap[pai];
        heap[pai] = aux;
        subir_minimo(pai);
    }
}

void desce_minimo(int indice)
{
    if (indice * 2 > count_min_heap)
        return;

    int esquerda = define_filho_esquerda(indice);
    int direita = define_filho_direita(indice);

    int menor = indice;

    if (esquerda <= count_min_heap && heap[esquerda].distancia < heap[menor].distancia)
    {
        menor = esquerda;
    }

    if (direita <= count_min_heap && heap[direita].distancia < heap[menor].distancia)
    {
        menor = direita;
    }

    if (menor == indice)
        return;

    elemento aux;

    aux = heap[indice];
    heap[indice] = heap[menor];
    heap[menor] = aux;
    desce_minimo(menor);
}

int push(elemento x)
{
    count_min_heap++;
    heap[count_min_heap] = x;
    subir_minimo(count_min_heap);
}

elemento pop()
{
    elemento retorno;
    if (count_min_heap == 0)
    {
        retorno.distancia = -1;
        retorno.vertice = -1;
        return retorno;
    }

    retorno = heap[1];
    // printf("\n %d",heap[1]);
    heap[1] = heap[count_min_heap];
    count_min_heap--;
    desce_minimo(1);
    return retorno;
}

int main()
{
    elemento aux;
    aux.distancia = 1;
    aux.vertice = 1;
    push(aux);
    aux.distancia = 10;
    aux.vertice = 10;
    push(aux);
    aux.distancia = 2;
    aux.vertice = 2;
    push(aux);
    aux.distancia = 9;
    aux.vertice = 9;
    push(aux);

    int i;

    elemento retorno;

    while (retorno.distancia != -1)
    {
        retorno = pop();
        if (retorno.distancia != -1)
        {
            printf("\n Vertice: %d Distancia %d", retorno.vertice, retorno.distancia);
        }
    }

    printf("\n");
    return 0;
}