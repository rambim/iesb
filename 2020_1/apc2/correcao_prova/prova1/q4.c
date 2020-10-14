#include <stdio.h>
#include <stdlib.h>

typedef struct vetores
{
    int vet_de_primos[10];
    int vetor_de_n_primos[10];

} vetores;

int verifica_primo(int x);
void mostrar_vetor(int *vet, int tam);
void menu(vetores a, int qtd_primos, int qtd_n_primos);

int main()
{
    int vet[10], i, x, y;
    vetores a;
    int opcao;

    

    for (i = 0; i < 10; i++)
    {
        printf("\n Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    x = 0;
    y = 0;

    for (i = 0; i < 10; i++)
    {
        if (verifica_primo(vet[i]))
        {
            a.vet_de_primos[x] = vet[i];
            x++;
        }
        else
        {
            a.vetor_de_n_primos[y] = vet[i];
            y++;
        }
    }

    menu(a,x,y);

    return 0;
}

void menu(vetores a, int qtd_primos, int qtd_n_primos)
{
    int opcao;

    do
    {
        printf("\n 1 - Mostrar primos: ");
        printf("\n 2 - Mostrar nao primos: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Mostrando os primos: ");
            mostrar_vetor(a.vet_de_primos,qtd_primos);
            break;
        case 2:
            printf("\n Mostrando os nao primos: ");
            mostrar_vetor(a.vetor_de_n_primos,qtd_n_primos);
            break;
        case 0:
            printf("\n saindo...\n");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }

    } while (opcao != 0);
}

int verifica_primo(int x)
{
    int divisor;

    if (x == 1)
    {
        return 0;
    }

    for (divisor = 2; divisor < x; divisor++)
    {
        if (x % divisor == 0)
        {
            return 0;
        }
    }
    return 1;
}

void mostrar_vetor(int *vet, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("\n %d", vet[i]);
    }
}