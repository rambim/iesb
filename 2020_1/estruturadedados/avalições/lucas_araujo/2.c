#include <stdlib.h>
#include <stdio.h>


typedef struct Fila
{
    struct Registro * comeco;
    struct Registro * fim;
}Fila;

typedef struct Registro
{
    int valor;
    struct Registro * prox;
    struct Registro * anterior;
}Registro;

Registro * faz_registro(int x)
{
    Registro * registro_retornavel = (Registro *)malloc(sizeof(Registro));

    registro_retornavel->prox = NULL;
    registro_retornavel->anterior = NULL;

    registro_retornavel->valor = x;

    return registro_retornavel; 
}

Fila * faz_fila()
{
    Fila * fila_retornavel = (Fila *)malloc(sizeof(Fila));

    fila_retornavel->comeco = NULL;
    fila_retornavel->fim = NULL;

    return fila_retornavel;
}

void adiciona_fila(Fila * f1, int x)
{
    Registro * adiciona = faz_registro(x);
    if(f1->comeco == NULL)
    {
        f1->comeco = adiciona;
        f1->fim = adiciona;
    }
    else
    {
        Registro * aux = f1->fim;
        adiciona->anterior = aux;
        aux->prox = adiciona;
        f1->fim = adiciona;
    }
}

int pop(Fila * f1)
{
    if(f1->fim == NULL)
    {
        return -1;
    }
    else
    {
        int x;
        Registro * aux = f1->comeco;
        f1->comeco = aux->prox;
        x = aux->valor;
        free(aux);
        return x;
    }
}

Fila * cria_fila_1_a_n(int n)
{
    Fila * retorno = faz_fila();
    int i;
    for(i=1; i<=n; i++)
    {
        adiciona_fila(retorno, i);
    }

    return retorno;
}

void mostra (Fila * f1)
{
    if(f1->comeco == NULL)
    {
        printf("Ta vazia\n");
    }
    else
    {
        Registro * aux = f1->comeco;
        while (aux != NULL)
        {
            printf("%d <- ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }
    
}

int main()
{
    int n;
    while(1)
    {
        scanf("%d", &n);

        if(!n){
            return 0;
        }
        else{
            if(n<2)
            {
                continue;
            }
            Fila * f = cria_fila_1_a_n(n);
            //int discart[n-1];
            int disc, req, i;

            printf("Discarded cards: ");
            for(i = 0; i < n-1; i++)
            {
                disc = pop(f);
                req = pop(f);
                adiciona_fila(f, req);
                if(i == (n - 2))
                {
                    printf("%d", disc);
                }else
                {
                    printf("%d, ", disc);
                }
            }
            printf("\nRemaining card: %d\n", f->comeco->valor);

        }
    }
}
