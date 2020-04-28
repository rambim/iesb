#include<stdlib.h>
#include<stdio.h>

#include<math.h>
#include<locale.h>
#include<string.h>

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
void remove_registro(lista * l,int x);
void remove_primos(lista *l);

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

void remove_registro(lista * l,int x){
	registro * aux=NULL;
	registro * ant=NULL;
	registro * prox=NULL;
	if(l->inicio==NULL){
		printf("N�mero n�o encontrado na lista");
		return;
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
                printf("N�mero %d removido da lista\n ", x);
                return;
            }

            ant = aux;
            aux = aux->prox;
            prox = aux->prox;
        }
	}
	printf("N�mero n�o encontrado na lista");
	return;
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

void remove_primos(lista *l){
	registro * aux;
	int x, num, m;
    if (l->inicio==NULL)
    {
        printf("\n Nao existem elementos");
    }
    else
    {
        aux=l->inicio;
        while(aux!=NULL)
        {
        	num =aux->valor;
            if(num<2 ){
			}
			else if(num==2){
				remove_registro(l,num);
			}else{
				x=num;
				m=1;
				//printf("N�mero do m.1: %d \n", m);
    			while(m!=0 && x>1){
    				x--;
					m=num%x;
    				//printf("N�mero do m.2: %d \n", m);
    			}
    			
    			//printf("N�mero do x : %d \n", x);
				
				if(x==1){
    				remove_registro(l,num);
    			}
			}
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
        printf("\n 5 - remove primos");
        printf("\n 6 - insere n�meros de 1 a 10 e primos");
        printf("\n 7 - sair");
        printf("\n");
        scanf("%d",&op);

        switch(op){
        case 1:   
        	printf("Qual n�mero deseja inserir?\n");
        	scanf("%d", &numero);
        	
        	aloca_registro(l,numero);
        	
            break;
        case 2:
        	printf("Qual n�mero deseja buscar?\n");
        	scanf("%d", &numero);
        	
        	retorno = busca_registro(l,numero);
        	
        	if(retorno == 0){
        		printf("N�mero %d encontrado na lista\n ", numero);
			}else if(retorno == 1){
				printf("N�mero n�o encontrado na lista");
			}
        	
			
            break;
        case 3:
        	printf("Qual n�mero deseja remover?\n");
        	scanf("%d", &numero);
        	
        	remove_registro(l,numero);
			
            
            break;
        case 4:
        	
        	mostrar(l);
        	
        	
            break;
    	case 5:
			
			remove_primos(l);
			
			printf("Feito com sucesso!");
			
			break;
		case 6:
			
			for(numero=1;numero<=10;numero++){
				aloca_registro(l,numero);
			}
			aloca_registro(l,11);
			aloca_registro(l,13);
			aloca_registro(l,17);
			aloca_registro(l,19);
			aloca_registro(l,23);
			aloca_registro(l,29);
			
			printf("Feito com sucesso!");
			
			break;
		case 7:		
            printf("\n Saindo do programa");         
            break;
        default:
            printf("\n op��o inv�lida");

            break;

        }

    }while(op!=7);
}

