#include <stdio.h>
#define tam 20

int vetor_de_pilhas[tam];
int i = -1, j = tam;

int push1(int x)
{
    if(i==(j-1))
    {
        printf("pilha cheia\n");
        return 0;
    }else
    {
        i++;
        vetor_de_pilhas[i] = x;
        return vetor_de_pilhas[i];
    } 
}

int push2(int x)
{
    if(j==(i+1))
    {
        printf("pilha cheia\n");
        return 0;
    }
    else
    {
        j--;
        vetor_de_pilhas[j] = x;
        return vetor_de_pilhas[j];
    }
}

int pop1()
{
    int retorno;
    if(i==-1)
    {
        printf("pilha vazia");
        return 0;
    }
    else
    {
        retorno = vetor_de_pilhas[i];
        i--;
        return vetor_de_pilhas[i];
    }
}

int pop2()
{
    int retorno;
    if(j==tam)
    {
        printf("pilha vazia");
        return 0;
    }
    else
    {
        retorno = vetor_de_pilhas[j];
        j++;
        return vetor_de_pilhas[j];
    }   
}

void mostrar()
{
    int k;
    for(k=0; k<tam;k++)
    {
        printf("%d ", vetor_de_pilhas[k]);
    }
    printf("\n");
}
void menu()
{
    int opc;
    int numero_a_manipular;
    do
    {
        printf("\nMenu\n");
        printf("0 - sair\n");
        printf("1 - push pilha 1\n");
        printf("2 - push pilha 2\n");
        printf("3 - pop pilha 1\n");
        printf("4 - pop pilha 1\n");
        printf("5 - mostrar\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 0:
            printf("Até logo\n");
            break;
        case 1:
            printf("Informe um numero para push na pilha 1\n");
            scanf("%d", &numero_a_manipular);
            push1(numero_a_manipular);
            break;
        case 2:
            printf("Informe um numero para push na pilha 2\n");
            scanf("%d", &numero_a_manipular);
            push2(numero_a_manipular);
            break;
        case 3:
            pop1(numero_a_manipular);
            break;
        case 4:
            pop2(numero_a_manipular);
            break;
        case 5:
            mostrar();
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }while(opc!=0);
    
}
int main() {
    menu();
}