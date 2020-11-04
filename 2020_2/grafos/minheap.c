#include <stdio.h>
#include <stdlib.h>


int heap[100];

int count=0;



int get_pai(int index)
{
    return index/2;
}

int get_filho_esquerda(int index)
{
    return index*2;
}

int get_filho_direita(int index)
{
    return index*2+1;
}

void subir_minimo(int index)
{
    if (index<=1) return ;

    int pai,aux;
    pai = get_pai(index);

    if (heap[index] < heap[pai])
    {
        aux = heap[index];
        heap[index] = heap[pai];
        heap[pai] = aux;
        subir_minimo(pai);
    }
}

void push(int x)
{
    count++;
    heap[count] = x;
    subir_minimo(count);
}

void desce_max(int index)
{
    if (index * 2 > count) return;

    int esquerdo = get_filho_esquerda(index);
    int direito = get_filho_direita(index);

    int menor = index;

    if (esquerdo <=count && heap[esquerdo] < heap[menor])
    {
        menor = esquerdo;
    }
    if (direito <=count && heap[direito] < heap[menor])
    {
        menor = direito;
    }

    if (menor==index) return;

    int aux;

    aux = heap[index];
    heap[index] = heap[menor];
    heap[menor] = aux;
    desce_max(menor);


}

void pop()
{
    if (count==0) return ;
    printf("\n Removendo %d",heap[1]);
    heap[1] = heap[count];
    count--;
    desce_max(1);

}



void mostrar()
{
    int i;
    printf("Mostrando: ");
    for(i=1;i<=count;i++)
    {
        printf("%d ",heap[i]);
    }
}


int main()
{


    push(1);
    push(10);
    push(2);
    push(9);
    push(3);
    push(8);
    push(4);
    push(7);
    push(5);
    push(6);
    mostrar();
    pop();
    mostrar();
    pop();
    mostrar();
    pop();
    mostrar();
    pop();
    mostrar();
    pop();
    mostrar();
    pop();
    mostrar();
    pop();
    mostrar();
    pop();
    mostrar();
    return 0;
}



