#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<locale.h>

typedef struct lista
{
    int qtd;
    struct registro * inicio;
    struct registro * fim;
}lista;

typedef struct registro
{
    int valor;
    struct registro * ant;
    struct registro * prox;
}registro;

void menu(lista *l);
lista * aloca_lista();
registro * aloca_registro();
void mostrar(lista * l);
int desaloca_registro(lista * l,int x);

int main(){
    lista * l;
    l = aloca_lista();
    menu(l);
    return 0;
}

lista * aloca_lista(){
    lista * novo;
    novo =(lista*)malloc(sizeof(lista));
    novo->qtd=0;
    novo->inicio=NULL;
    novo->fim=NULL;
	return novo;
}

registro * aloca_registro(){
    registro * novo;
    novo =(registro*)malloc(sizeof(registro));
    novo->valor = 0;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

void aloca_registro(lista * l, int x){
	registro * aux;
	registro * novo;
	novo = aloca_registro();
	novo->valor = x;
	
	if ( l->inicio==NULL)
    {
    	//novo->ant=l;
		l->inicio = novo;
		l->fim = novo;
    }else {
		aux = l->fim;
		novo->ant = aux;
		aux->prox = novo;
		l->fim = novo;
	}
    
    
    l->qtd++;
}

int busca_registro(lista * l,int x){
	registro * aux;
    if ( l->qtd==0){
        return 1;
    }
    else{
        aux = l->inicio;
        while(aux!=NULL){
            if ( aux->valor ==x){
                return 0;
            }
            aux=aux->prox;
        }

        return 1;
    }
}

int remove_registro(lista * l,int x){
	registro * aux=NULL;
	registro * ant=NULL;
	registro * prox=NULL;
	if(l->inicio==NULL){
		return 1;
	}else{
		aux = l->inicio;
		while(aux!=NULL){
            if ( aux->valor == x){
            	if (ant == NULL){
                    l->inicio = aux->prox;
                    l->inicio->ant = NULL;
                }
                else
                {
                    ant->prox = prox;
                    prox->ant = ant;
                }
                l->qtd--;
                free(aux);
                return 0;
            }

            ant = aux;
            aux = aux->prox;
            prox = aux->prox;
        }
	}
	return 1;
}

void mostrar(lista * l){
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


void menu(lista * l){
	setlocale(LC_ALL, "Portuguese");
    int op;
    int retorno,numero;


    do
    {
    	system("cls");
        printf("\n 1 - inserir ");
        printf("\n 2 - buscar");
        printf("\n 3 - remover");
        printf("\n 4 - mostrar");
        printf("\n 5 - sair");
        printf("\n");
        scanf("%d",&op);

        switch(op){
        case 1:   
        	printf("Qual número deseja inserir?\n");
        	scanf("%d", &numero);
        	
        	aloca_registro(l,numero);
        	
            break;
        case 2:
        	printf("Qual número deseja buscar?\n");
        	scanf("%d", &numero);
        	
        	retorno = busca_registro(l,numero);
        	
        	if(retorno == 0){
        		printf("Número %d encontrado na lista\n ", numero);
			}else if(retorno == 1){
				printf("Número não encontrado na lista");
			}
        	
			getch();
            break;
        case 3:
        	printf("Qual número deseja remover?\n");
        	scanf("%d", &numero);
        	
        	retorno = remove_registro(l,numero);
        	
        	if(retorno == 0){
        		printf("Número %d removido da lista\n ", numero);
			}else if(retorno == 1){
				printf("Número não encontrado na lista");
			}
            getch();
            break;
        case 4:
        	
        	mostrar(l);
        	
        	getch();
            break;
    	case 5:		
            printf("\n Saindo do programa");         
            break;
        default:
            printf("\n opção inválida");
            getch();
            break;

        }

    }while(op!=5);
}










