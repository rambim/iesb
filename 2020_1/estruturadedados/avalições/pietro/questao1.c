#include<stdlib.h>
#include<stdio.h>

#include<math.h>
#include<locale.h>
#include<string.h>

typedef struct lista
{
    int qtd;
    struct registro * inicio;
}lista;

typedef struct registro
{
    int valor;
    struct registro * prox;
}registro;

void menu(lista * l);
lista * aloca_lista();
registro * aloca_registro();
void incluir_final(lista * l, int x);
registro * buscar(lista * l, int x);
int remover(lista * l, int x);
void mostrar(lista * l);
void mostrar_ant_pos(lista * l, int x);

int main(){
    lista * l1;
    l1 = aloca_lista();
    menu(l1);
    return 0;
}

lista * aloca_lista(){
    lista * novo;
    novo =(lista*)malloc(sizeof(lista));
    novo->qtd=0;
    novo->inicio=NULL;
    return novo;
}

registro * aloca_registro(){
    registro * novo;
    novo =(registro*)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}


void incluir_final(lista * l, int x){
    registro * novo,*aux;
    novo = aloca_registro();
    novo->valor = x;

    if ( l->inicio==NULL)
    {
      l->inicio=novo;
    }
    else
    {
       aux = l->inicio;
       while(aux->prox!=NULL)
       {
           aux=aux->prox;
       }
       aux->prox = novo;

    }
     l->qtd++;
}

registro * buscar(lista * l, int x)
{
    registro * aux;
    if ( l->qtd==0)
    {
        return NULL;
    }
    else
    {
        aux = l->inicio;
        while(aux!=NULL)
        {
            if ( aux->valor ==x)
            {
                return aux;
            }

            aux=aux->prox;
        }

        return NULL;
    }
}

int remover(lista * l, int x)
{
    registro * aux=NULL, *ant=NULL;
    if ( l->qtd==0)
    {
        return 0;
    }
    else
    {
        aux = l->inicio;
        while(aux!=NULL)
        {
            if ( aux->valor == x)
            {
                if (ant ==NULL)
                {
                    l->inicio = aux->prox;
                }
                else
                {
                    ant->prox = aux->prox;
                }
                l->qtd--;
                free(aux);
                return 1;
            }

            ant = aux;
            aux = aux->prox;
        }
        return 2;
    }
}

void mostrar(lista * l)
{
    registro * aux;
    if (l->inicio==NULL)
    {
        printf("\n Nao existem elementos");
    }
    else
    {
        aux=l->inicio;
        while(aux!=NULL)
        {
            printf("\n %d",aux->valor);
            aux=aux->prox;
        }
    }
}

void mostrar_ant_pos(lista * l, int x){
	registro *ant=NULL, *aux=NULL;
    if ( l->qtd==0){
        printf("N�o existem elementos na lista");
    }
    else{
        aux = l->inicio;
        while(aux!=NULL){
            if ( aux->valor == x){
                if (ant ==NULL)
                {
                    printf("N�mero encontrado sem anterior e n�mero posterior");
                    if(aux->prox==NULL){
                    	printf(" n�o encontrado \n");
                    	return;
					}
					printf(" � %d \n", aux->prox->valor);
                    return;
                }
                else{
                    printf("N�mero anterior � %d e n�mero posterior", ant->valor);
                    if(aux->prox==NULL){
                    	printf(" n�o encontrado \n");
                    	return;
					}
					printf(" � %d \n", aux->prox->valor);
                    return;
                }
            }

            ant = aux;
            aux = aux->prox;
        }
        printf("N�mero n�o encontrado na lista\n");
        return ;
    }
}

void menu(lista * l){
	setlocale(LC_ALL, "Portuguese");
    int op;
    registro * aux;
    int retorno,numero;


    do
    {
    	system("cls");
        printf("\n 1 - inserir: ");
        printf("\n 2 - buscar:");
        printf("\n 3 - remover");
        printf("\n 4 - mostrar");
        printf("\n 5 - mostra registro, o registro anterior e posterior");
        printf("\n 6 - sair");
        printf("\n");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            printf("\n Qual numero deseja inserir: ");
            scanf("%d",&numero);
            incluir_final(l,numero);
			
            break;
        case 2:
            printf("\n Qual numero deseja buscar: ");
            scanf("%d",&numero);
            aux = buscar(l,numero);
            if ( aux==NULL)
            {
                printf("\n Numero n�o esta na lista");
            }
            else
            {
                printf("\n numero %d encontrado na lista",aux->valor);
            }
			
            break;
        case 3:
            printf("\n Digite o numero que deseja remover: ");
            scanf("%d",&numero);
            retorno = remover(l,numero);
            if (retorno ==1)
            {
                printf("\n Numero removido com sucesso");
            }
            if (retorno == 0)
            {
                printf("\n Lista vazia");
            }
            if (retorno == 2)
            {
                printf("\n Numero n�o foi removido");
            }
            
            break;
        case 4:
            mostrar(l);

            break;
        case 5:
        	printf("\n Qual numero deseja procurar: ");
            scanf("%d",&numero);
            
        	mostrar_ant_pos(l,numero);
        	

        	break;
        case 6:
            printf("\n Saindo do programa");
            
            break;
        default:
            printf("\n op��o inv�lida");

            break;

        }

    }while(op!=6);
}
