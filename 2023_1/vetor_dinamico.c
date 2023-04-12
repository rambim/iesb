#include <stdio.h>
#include <stdlib.h>

typedef struct vet_dinamico{
    int * numeros;
    int tamanho;
    int qtd_preenchidos;
}vet_dinamico;

void inserir(vet_dinamico * x, int numero);
void remover (vet_dinamico *x);


int main()
{
    vet_dinamico a;
    a.numeros = (int*) malloc(sizeof(int) * 4);
    a.tamanho = 4;
    a.qtd_preenchidos=0;
    int i =10;
    while(i--)
    {
        printf("\n");
        printf("\n Quantidade de numeros no vetor: %d",a.qtd_preenchidos);
        printf("\n Tamanho do vetor: %d",a.tamanho);
        inserir(&a,1);
    }
    i=10;
    while(i--)
    {
        printf("\n");
        printf("\n Quantidade de numeros no vetor: %d",a.qtd_preenchidos);
        printf("\n Tamanho do vetor: %d",a.tamanho);
        remover(&a);
    }

    
}

void inserir(vet_dinamico  * x, int numero)
{
    float percentual;
    if (x->qtd_preenchidos >= x->tamanho)
    {
        printf("\n Vetor dinamico cheio!");
        return;
    }

    x->numeros[x->qtd_preenchidos] = numero;
    x->qtd_preenchidos++;

    printf("\n Numero preenchido");
    printf("\n Quantidade atual: %d",x->qtd_preenchidos);
    printf("\n Tamanho Atual: %d",x->tamanho);

    percentual = (float)x->qtd_preenchidos / (float)x->tamanho;
    // printf("\nTestando percentual");
    if ( percentual >= 0.6){
        printf("\nPassei dos 60");
        x->numeros = (int*)realloc(x->numeros,x->tamanho * 2 * sizeof(int));
        x->tamanho = x->tamanho * 2;
        printf("\n Realocado com dobro do tamanho");
    }
    printf("\n Tamanho novo: %d",x->tamanho);
}

void remover (vet_dinamico *x)
{
    float percentual;
    printf("\n Removendo %d",x->numeros[x->qtd_preenchidos-1]);
    x->numeros[x->qtd_preenchidos-1] = 0;
    x->qtd_preenchidos--;
    printf("\n Numero preenchido");
    printf("\n Quantidade atual: %d",x->qtd_preenchidos);
    printf("\n Tamanho Atual: %d",x->tamanho);
    percentual = (float)x->qtd_preenchidos / (float)x->tamanho;
    // printf("\nTestando percentual");
    if ( percentual <= 0.2){
        printf("\n menos que  20");
        x->numeros = (int*)realloc(x->numeros,x->tamanho / 2 * sizeof(int));
        x->tamanho = x->tamanho /2;
        printf("\n Realocado com metade do tamanho");
    }
    printf("\n Tamanho novo: %d",x->tamanho);


}

