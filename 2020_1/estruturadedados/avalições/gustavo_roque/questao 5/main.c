#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int tam;
    struct registro * ini,*ante;
}lista;

typedef struct registro{
    int  num;
    struct registro * prox;
}registro;


void inserir_ini(int num, lista * point);
registro * aloca_reg();
lista * aloca_lista();

void mostrar(lista * point);
int pop(lista *point, int pop);

int main()
{
    int opc = 0, num = 0, qtd = 0, i, pop1 = 0;
    lista * point;
    point = aloca_lista();

    do{
        printf("1 --> Inserir. \n");
        printf("2 --> pop. \n");
        printf("3 --> Mostrar. \n");

        printf("9 --> Sair. \n");
            scanf("%d", &opc);
        switch(opc)
        {
        case 1:


            if(pop1 == 0 && point->ini == NULL)
            {
                printf("Insira a quantidade de registros:\n");
                scanf("%d", &qtd);

                printf("Insira os valores:\n");
               for( i = 0; i<qtd; i++)
                {
                    scanf("%d", &num);
                    inserir_ini(num, point);
                }
                point->ante->prox = point->ini;
            }
            else if(pop1 > 0)
            {
                printf("insira o valor: \n");
                for(i = 0; i<pop1; i++)
                {
                    scanf("%d", &num);
                    inserir_ini(num, point);
                }
                pop1 = 0;
                point->ante->prox = point->ini;
            }
            else
                printf("Fila cheia. \n\n");
            break;
        case 2:
            pop1 = pop(point, pop1);
            break;
        case 3:
            mostrar(point);
            break;
        default:
            break;

        }

    }while(opc != 9);

    return 0;
}
lista * aloca_lista()
{
    struct lista * p1;
    p1 = (lista*)malloc(sizeof(lista));
    p1->ini = NULL;
    p1->tam = 0;
    p1->ante = NULL;
    return p1;
}
registro * aloca_reg()
{
    struct registro * l1;
    l1 = (registro*)malloc(sizeof(registro));
    l1->num = 0;

    l1->prox = NULL;

    return l1;
}


void inserir_ini(int num, lista * point)
{
    int posi = 1;
    struct registro * atual;

    if (point->ini == NULL)
    {
        point->ini = aloca_reg();

        atual = point->ini;
        atual->num = num;
        point->tam++;

    }
    else
    {
        atual = point->ini;

        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }

            atual->prox = aloca_reg();
            atual->prox->num= num;
            point->tam++;
            point->ante = atual->prox;

    }
}
int pop(lista *point, int pop)
{


    if(point->ante->prox == point->ini)
        point->ante->prox  = NULL;

    point->ini = point->ini->prox;
    point->tam--;
    return pop+1;
}
void mostrar(lista * point)
{
    int i;
    struct registro * atual;
    if (point->ini != NULL)
    {
        atual = point->ini;
       for(i = 0; i<point->tam+1; i++)
       {
           printf("Numero %d \n", atual->num);
            atual = atual->prox;
       }
    }
    else
    {
        printf("Lista vazia \n");
    }
}


