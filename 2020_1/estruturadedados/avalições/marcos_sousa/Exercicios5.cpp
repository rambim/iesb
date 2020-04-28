#include <stdio.h>
#include <stdlib.h>

typedef struct lista //estrutura da lista
{ 
int quantidade;
struct registro *inicio;
}lista;

typedef struct registro //estrutura do registro
{
	int valor;
	struct registro *proximo;
}registro;

//funções
void mostrar(lista *l);
lista *aloca_lista();
registro *aloca_registro();
void incluir(lista *l, int x);
int remover_do_registro(lista *l, int x);
registro *buscar(lista *l, int x);
void menu(lista *l);
int posterior_anterior(lista *l,int x);
registro *inferior(lista *l,int x);
registro *posterior(lista *l,int x);

int main()
{

    lista *l1;


    l1 = aloca_lista();
   
    
    menu(l1);

    return 0;
}

lista *aloca_lista()
{
	lista *novo;
	novo=(lista*)malloc(sizeof(lista));
	novo->inicio=NULL;
	novo->quantidade=0;
	return novo;
}

registro *aloca_registro()
{
	registro *novo; 
	novo=(registro*)malloc(sizeof(registro));
	novo->valor=0;
	novo->proximo=NULL;
	return novo;
}

void incluir(lista *l,int x)
{
	registro *novo ,*aux;   //novo endereço e o auxiliar para apontar o endenreço
	novo=aloca_registro(); //recebe a funçao de alocar registro
	novo->valor=x;       //recebe o valor do usuario
	if(l->inicio==NULL)
	{
		l->inicio=novo; //1 valor da lista
	}
	else
	{
	aux=l->inicio;
	
	while(aux->proximo!=NULL)
	{
		   aux = aux->proximo;  
	       }

        aux->proximo = novo;  
    }

    l->quantidade++;  
}

void mostrar(lista *l)
{
	registro *aux;
	if(l->inicio==NULL) 
	{
		printf("\nNão Há elementos na lista\n");
	}
	else 
	{
			aux=l->inicio; 
			while(aux!=NULL) 
			{
				printf("\nvalor %d",aux->valor);
				aux=aux->proximo; 
			}
	}
}

int remover_do_registro(lista *l,int x)
{
	registro *aux=NULL, *ant=NULL; 
	if(l->inicio==NULL)
	{
		return 0; 
	}
	else 
	{
		aux=l->inicio; 
		while(aux!=NULL) 
		{
			if(aux->valor==x)  
			{
				if(ant==NULL)
				{
				l->inicio=aux->proximo; 
			}
			else 
			{
				ant->proximo = aux->proximo; 
			}
			free(aux); 
			l->quantidade--; 
			return 1; 
			}
			else
			{
			ant = aux; 
            aux = aux->proximo; 
            
			}
		}
		return 0;
	}
}

registro *buscar (lista *l,int x)
{
	registro *aux;
	if(l->inicio==NULL) 
	{
		return NULL; 
	}
	else 
	{
	
	aux=l->inicio;
	while(aux!=NULL)
	{
		if(aux->valor==x)
		{
			return aux;
		}
		else
		{
			aux=aux->proximo;
		}
	}
	return NULL;
}
}

int  posterior_anterior(lista *l,int x)
{

	registro *aux=NULL, *ant=NULL; 
	
	if(l->inicio==NULL)//nao ha elementos 
	{
		printf("\nNao ha elementos"); 
	}
	else //ha elemento
	{
		aux=l->inicio;
			while(aux!=NULL) 
			{
				if(aux->valor==x)
		{
		
		if(ant==NULL)//se nao houver um numero anterior
		{
			if(aux->proximo==NULL)//nem posterior nem inferior
			{
			return NULL;
			
		}
			else //so  posterior
			{
				aux=aux->proximo;
				return 1;
				
			}
		}
		else//ha o anterior
		{
			if(aux->proximo==NULL)//so anterior
			{
				ant=aux;
				return 2;
				
			}
			else//posterior e anterior
			{
				ant=aux;
				aux=aux->proximo;
				return 3;
			
				
			}
			
		}
		
	}
	else
	{
		ant = aux;
		aux=aux->proximo;
	}

}
return NULL;
}
}

registro *posterior(lista *l,int x)
{
	registro *aux;
	if(l->inicio==NULL) //se não houver nenhum elemento
	{
		return NULL; 
	}
	else //se houver algum elemento
	{
	
	aux=l->inicio;
	while(aux!=NULL)
	{
		if(aux->valor==x)
		{
			aux=aux->proximo;
			return aux;
		}
		else
		{
			aux=aux->proximo;
		}
	}
	return NULL;
}
}


registro *inferior(lista *l,int x)
{
	registro *aux;
	registro *ant;
	if(l->inicio==NULL) //se não houver nenhum elemento
	{
		return NULL; 
	}
	else //se houver algum elemento
	{
	
	aux=l->inicio;
	while(aux!=NULL)
	{
		if(aux->valor==x)
		{
			return ant;
		}
		else
		{
			ant=aux;
			aux=aux->proximo;
		}
	}
	return NULL;
}
}
void menu(lista *l)
{
    int opcao;
    int numero;
    int retorno;
    int quantidade;
    int j;
    registro *aux;
    registro *ant;
    
        do 
    {
        printf("\n 1 - Incluir");
        printf("\n 2 - Buscar");
        printf("\n 3 - Remover");
        printf("\n 4 - Mostrar");
        printf("\n 5 - Quantidade de elementos  ");
        printf("\n 6 - Na frente e atras do numero");
        printf("\n 7 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) 
        {
        case 1:
            printf("\n Qual numero deseja inserir:\n ");
            scanf("%d", &numero);
            incluir(l, numero);
            quantidade++;
            break;
        case 2:
            printf("\n Qual numero deseja buscar: \n");
            scanf("%d", &numero);
            aux = buscar(l, numero);
            if (aux == NULL)
            {
                printf("\n numero nao encontrado\n");
            }
            else
            {
                printf("\n Numero %d encontrado\n", aux->valor);
            }

            break;

        case 3:
            printf("\n Qual numero deseja remover: \n");
            scanf("%d", &numero);
            retorno = remover_do_registro(l, numero);
            if (retorno == 0)
            {
                printf("\n numero nao esta na lista\n");
            }
            else
            {
                printf("\n numero removido com sucesso\n");
                quantidade--;
            }

            break;
        case 4:
            mostrar(l);
            break;
            case 5:
            printf("Ha %d elementos na lista\n",quantidade);
            break;
        case 6:
                printf("\n Qual numero deseja saber o posterior e anterior: \n");
            scanf("%d", &numero);
            j = posterior_anterior(l, numero);
            ant=inferior(l,numero);
            aux=posterior(l, numero);
            

            	if (j== NULL)
            {
            	
                printf("\n Numero nao esta na lista ou nao ha na frente ou atras\n");
            }
            if(j==1 )
            {
               printf("\nfrente: %d nao ha atras \n",aux->valor);
           }

            if(j==2 )
            {
            printf("\natras: %d nao ha elementos a frente\n",ant->valor);
            }
            if(j==3 && aux!=NULL && ant !=NULL)
            {
               printf("\natras: %d frente: %d\n ",ant->valor,aux->valor);
            }

            break;
        case 7:
            printf("\n Finalizando\n");
            break;
            
        default:
            printf("\n opcao invalida tente novamente\n");
            break;
        }

    } while (opcao != 7);
}


