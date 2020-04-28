#include <stdlib.h>
#include <stdio.h>

typedef struct Lista_dupla
{
    struct Registro * inicio;
    struct Registro * fim;
    
}Lista_dupla;

typedef struct Registro
{
    int valor;
    struct Registro * anterior;
    struct Registro * proximo;
}Registro;


Lista_dupla * cria_lista_dupla();
Registro * cria_registro(int valor);
void adiciona(Lista_dupla * ld1, int valor);
int busca(Lista_dupla * ld1, int valor);
int primo(int valor);
void remove_lista(Lista_dupla * ld1, int valor);
void remove_primos(Lista_dupla * ld1);
void mostra(Lista_dupla * ld1);
void menu(Lista_dupla * ld1);

int main()
{
    Lista_dupla * lista = cria_lista_dupla();

    menu(lista);
    
    return 0;
}


Lista_dupla * cria_lista_dupla()
{
    Lista_dupla * lista_dupla_criada = (Lista_dupla *)malloc(sizeof(Lista_dupla));

    lista_dupla_criada->inicio = NULL;
    lista_dupla_criada->fim = NULL;

    return lista_dupla_criada;
}

Registro * cria_registro(int valor)
{
    Registro * registro_criado = (Registro *)malloc(sizeof(Registro));
    
    registro_criado->proximo = NULL;
    registro_criado->anterior = NULL;
    registro_criado->valor = valor;

    return registro_criado;
}

void adiciona(Lista_dupla * ld1, int valor)
{
    Registro * novo = cria_registro(valor);

    if(ld1->inicio == NULL)
    {
        ld1->inicio = novo;
        ld1->fim = novo;
        printf("adicionei\n");
    }
    else
    {
        Registro * aux = ld1->fim;
        ld1->fim = novo;
        novo->anterior = aux;
        aux->proximo = novo;
        printf("adicionei\n");
    }
}

int busca(Lista_dupla * ld1, int valor)
{
    if(ld1->inicio == NULL)
    {
        printf("Lista vazia\n");
        return 0;
    }
    else
    {
        Registro * aux = ld1->inicio;
        while(aux != NULL)
        {
            if(aux->valor == valor)
            {
                return 1;
                break;
            }
            aux = aux->proximo;
        }
        return 0;
    }
}

int primo(int valor)
{
    if(valor == 1 || valor == 0)
    {
        return 0;
    }
    int i;
    for(i=2; i <= valor/2; i++)
    {
        if(valor%i==0)
        {
            return 0;
        }
    }
    return 1;
}

void remove_lista(Lista_dupla * ld1, int valor)
{
    if(ld1->inicio == NULL)
    {
        printf("lista vazia");
    }
    else
    {
        Registro * aux = ld1->inicio;

        if(aux->valor == valor)
        {
            ld1->inicio = aux->proximo;
            free(aux);
            printf("Removi\n");
        }
        else
        {
            while (aux->proximo != NULL)
            {
                if (aux->valor == valor)
                {
                    printf("a\n");
                    break;
                }
                aux = aux->proximo;
            }

            if (aux->valor != valor)
            {
                printf("Não encontrei\n");
            }
            else
            {
                if (aux == ld1->inicio)
                {
                    ld1->inicio = aux->proximo;
                    aux->proximo->anterior = NULL;
                    free(aux);
                    printf("Removi\n");
                }
                else
                {
                    if (aux == ld1->fim)
                    {
                        Registro *algo = ld1->fim;
                        ld1->fim = aux->anterior;
                        ld1->fim->proximo = NULL;
                        free(aux);
                        printf("Removi\n");
                    }
                    else
                    {
                        aux->anterior->proximo = aux->proximo;
                        free(aux);
                        printf("Removi\n");
                    }
                }
            }
        }
        
    }
    

}

void remove_primos(Lista_dupla * ld1)
{
    if(ld1->inicio == NULL)
    {
        printf("lista vazia\n");
    }
    else
    {
        Registro * aux = ld1->inicio;
        while (aux != NULL)
        {
            if(primo(aux->valor))
            {
                remove_lista(ld1, aux->valor);
            }
            aux = aux->proximo;
        }
    }
}

void mostra(Lista_dupla * ld1)
{
    if(ld1->inicio == NULL)
    {
        printf("lista vazia\n");
    }
    else
    {
        Registro * aux = ld1->inicio;
        while (aux != NULL)
        {
            if(aux->proximo == NULL){
                printf("%d", aux->valor);
            }
            else{
                printf("%d -> ", aux->valor);
            }
            aux = aux->proximo;
        }
        printf("\n");
    }
}

void menu(Lista_dupla * ld1)
{
    int opc;
    int numero_a_manipular;

    do
    {
        printf("\nMENU\n");
        printf("0 - sair\n");
        printf("1 - adiciona\n");
        printf("2 - remove\n");
        printf("3 - remove_primos\n");
        printf("4 - mostra\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 0:
            printf("Obrigado por utilizar meu programa\n");
            break;
        case 1:
            printf("Informe um valor para adicionar ao fim da lista\n");
            scanf("%d", &numero_a_manipular);
            adiciona(ld1, numero_a_manipular);
            break;
        case 2:
            printf("Informe um valor para remover da lista\n");
            scanf("%d", &numero_a_manipular);
            remove_lista(ld1, numero_a_manipular);
            break;
        case 3:
            remove_primos(ld1);
            break;
        case 4:
            mostra(ld1);
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opc != 0);
    
}
// void adiciona(Lista_dupla * ld1, int valor);
// int busca(Lista_dupla * ld1, int valor);
// int primo(int valor);
// void remove(Lista_dupla * ld1, int valor);
// void remove_primos(Lista_dupla * ld1);
// void mostra(Lista_dupla * ld1);
// void menu(Lista_dupla * ld1);