#include <stdio.h>
#include <stdlib.h>


int pop_fila();
void push_fila(int x);


int fila[5];
int inicio = 0;
int fim = 0;

int main()
{
    int opcao;
    int numero;

    do
    {
        printf("\n 1 - incluir na fila");
        printf("\n 2 - remover da fila");
        printf("\n 3 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um numero para ser incluido na fila:");
            scanf("%d",&numero);
            push_fila(numero);
            break;
        case 2:
            numero = pop_fila();
            printf("\n numero que saiu da fila %d",numero);
            break;
        case 3:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    }while(opcao!=3);
    return 0;
}


void push_fila(int x)
{
    
    if (fim>=5){
        printf("\n Filha cheia Acabou!");
    }
    else{
        fila[fim] = x;
        fim++;
    }

}

int pop_fila()
{
    int retorno;

    if (inicio>=5)
    {
        printf("\n Fila já esvaziou");
    }
    else{
        if (inicio == fim)
        {
            printf("\n Fila vazia");
            return -1;

        }
        else{
            retorno = fila[inicio];
            inicio++;
        }
    }

    return retorno;


}