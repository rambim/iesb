#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    struct Registro * inicio;
}Lista;

typedef struct Registro
{
    int valor;
    struct Registro * proximo;
}Registro;


Registro * cria_registro(int valor);
Lista * cria_lista();
void adiciona_lista(Lista * l1, int valor);
int buscar(Lista * l1, int valor);
int buscar_mostrar_antes_e_depois(Lista * l1, int valor);
int apaga_especifico(Lista *l1, int valor);
void mostrar(Lista * l1);
void menu(Lista * l1);

int main()
{
    Lista * lista = cria_lista();

    menu(lista);

    return 0;
}

Registro * cria_registro(int valor)
{
    Registro * registro_a_retornar = (Registro *)malloc(sizeof(Registro));

    registro_a_retornar->proximo = NULL;
    registro_a_retornar->valor = valor;

    return registro_a_retornar;
}

Lista * cria_lista()
{
    Lista * lista_a_retornar = (Lista *)malloc(sizeof(Lista));

    lista_a_retornar->inicio = NULL;

    return lista_a_retornar;
}

void adiciona_lista(Lista * l1, int valor)
{
    Registro * reg = cria_registro(valor);

    if(l1->inicio == NULL)
    {
        l1->inicio = reg;
        printf("adicionei\n");
    }
    else
    {
        Registro * aux = l1->inicio;
        while(aux->proximo != NULL)
        {
            aux = aux->proximo;
        }

        aux->proximo = reg;
        printf("adicionei\n");
    }
}

int buscar(Lista * l1, int valor)
{
    if(l1->inicio == NULL)
    {
        printf("Lista vazia, nada a buscar\n");
        return 0;
    }
    else
    {
        Registro * aux = l1->inicio;
        while(aux != NULL)
        {
            if(aux->valor == valor)
            {
                printf("Encontrei\n");
                return aux->valor;
            }
            aux = aux->proximo;
        }
        printf("Não encontrei\n");
        return 0;
    }
}

int buscar_mostrar_antes_e_depois(Lista * l1, int valor)
{
    if(buscar(l1, valor))
    {
        Registro * anterior = NULL;
        Registro * aux = l1->inicio;
        while (aux->valor != valor)
        {
            anterior = aux;
            aux = aux->proximo;
        }
        if (anterior == NULL)
        {
            printf("Valor do registro anterior: NULL\n");
        }
        else
        {
            printf("Valor do registro anterior: %d\n", anterior->valor);
        }
        if(aux->proximo == NULL)
        {
            printf("Valor do registro posterior: NULL\n");
        }else
        {
            printf("Valor do registro posterior: %d\n", aux->proximo->valor);
        }
    }
}

int apaga_especifico(Lista *l1, int valor)
{
    if(l1->inicio == NULL)
    {
        printf("Lista vazia\n");
        return 0;
    }
    else
    {
        if(buscar(l1, valor))
        {
            Registro * anterior = NULL;
            Registro * aux = l1->inicio;
            while(aux->valor != valor)
            {
                anterior = aux;
                aux = aux->proximo;
            }
            if(anterior == NULL)
            {
                l1->inicio = aux->proximo;
            }else
            {
                anterior->proximo = aux->proximo;
            }
            free(aux);
            printf("Apaguei\n");
            return 1;
        }
        else
        {
            printf("Esse elemento não se encontra na lista\n");
            return 0;
        }   
    }
}

void mostrar(Lista * l1)
{
    if(l1->inicio == NULL)
    {
        printf("Lista vazia\n");
    }
    else
    {
        Registro * aux = l1->inicio;
        while(aux != NULL)
        {
            if(aux->proximo == NULL)
            {
                printf("%d", aux->valor);
            }
            else
            {
                printf("%d -> ", aux->valor);
            }
            aux = aux->proximo;
        }
        printf("\n");
    }
}

void menu(Lista * l1)
{
    int opc;
    int numero_para_manipular;

    do
    {
        printf("\nMenu lista ligada\n");
        printf("0 - sair\n");
        printf("1 - adicionar \n");
        printf("2 - buscar registro\n");
        printf("3 - buscar registro e mostrar anterior e posterior\n");
        printf("4 - apagar registro\n");
        printf("5 - mostrar lista\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 0:
            printf("Obrigado por usar o programa, até a proxima\n");
            break;
        case 1:
            printf("Digite um numero para adicionar na lista\n");
            scanf("%d", &numero_para_manipular);
            adiciona_lista(l1, numero_para_manipular);
            break;
        case 2:
            printf("Digite um numero para buscar na lista\n");
            scanf("%d", &numero_para_manipular);
            buscar(l1, numero_para_manipular);
            break;
        case 3:
            printf("Digite um numero para buscar na lista e mostrar o anterior e posterior\n");
            scanf("%d", &numero_para_manipular);
            buscar_mostrar_antes_e_depois(l1, numero_para_manipular);
            break;
        case 4:
            printf("Digite um numero para apagar da lista\n");
            scanf("%d", &numero_para_manipular);
            apaga_especifico(l1, numero_para_manipular);
            break;
        case 5:
            mostrar(l1);
            break;
        default:
            printf("opcao invalida\n");
            break;
        }
    } while (opc != 0);
    
}
