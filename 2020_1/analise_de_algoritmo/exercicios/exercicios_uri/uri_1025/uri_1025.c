#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void mostrar_vetor(int *x, int tam);

void quick_sort(int *a, int left, int right);
int binary_search(int *vet, int ini, int fim, int x);
int PesquisaBinaria(int k[], int chave, int N);
int compara(const void *p1, const void *p2);
int procura (int * vet, int tam, int x);


int main()
{
    int N = 1, Q = 1;

    int procurado;
    int i, j;
    int retorno;
    int qtd_casos = 0;
    int *vet;
    int b, *p;
    

    while (1)
    {
        qtd_casos++;
        scanf("%d %d", &N, &Q);

        if (N == 0 && Q == 0)
        {

            return 0;
        }

        //printf("x = %d y = %d", x, y);

        vet = (int *)malloc(sizeof(int) * N);

        for (i = 0; i < N; i++)
        {
            scanf("%d", &vet[i]);
        }

        //printf("\n Mostrando lista de marmores");
        //mostrar_vetor(vet, x);

        //printf("\n Mostrando numeros a serem procurados");
        //mostrar_vetor(procurados, y);

        //printf("\n Vetor de marmore ordenado: ");

        quick_sort(vet, 0, N - 1);

        //mostrar_vetor(vet, x);
        //printf("\n");

        for (i = 0; i < Q; i++)
        {
            scanf("%d", &procurado);
            if (i == 0)
            {
                printf("CASE# %d:\n", qtd_casos);
            }

// solução 2 accept
/*
            p = (int *) bsearch(&procurado, vet, N, sizeof(int), compara);
			b = (int) (p - vet);

			for(j=0;j<b;j++)
			{
				if ( procurado == vet[j])
				{
					b = j;
					break;
				}
			}



            if(p != NULL)
                printf("%d found at %d\n", procurado, (b+1));
                else
                printf("%d not found\n", procurado);
*/
// solução 2 accept

// solução 1 5% WA
/*

   //         retorno = PesquisaBinaria(vet, procurado, N);
            retorno = binary_search(vet,0,N-1,procurado);
            if (retorno == -1)
            {
                printf("%d not found\n", procurado);
            }
            else
            {
                for(j=0;j<N;j++)
                {
                    if (vet[j]==procurado)
                    {

                        printf("%d found at %d\n", procurado,j+1);
                        break;
                    }
                }
            }

*/
// solução 1 5% WA
// solução 3 ok

            retorno = procura(vet,N,procurado);
            if (retorno == -1)
            {
                printf("%d not found\n", procurado);
            }
            else
            {
                printf("%d found at %d\n", procurado, retorno+1);
            }

// solução 3 ok
        }
        free(vet);
    }
    printf("\n");
    return 0;
}

void mostrar_vetor(int *x, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("\n %d", x[i]);
    }
}

void quick_sort(int *a, int left, int right)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while (i <= j)
    {
        while (a[i] < x && i < right)
        {
            i++;
        }
        while (a[j] > x && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > left)
    {
        quick_sort(a, left, j);
    }
    if (i < right)
    {
        quick_sort(a, i, right);
    }
}

int binary_search(int *vet, int ini, int fim, int x)
{
    int meio;
    meio = (ini + fim) / 2;

    if (fim <= ini)
    {
        return -1;
    }

    if (x == vet[meio])
    {
        return meio;
    }
    else
    {
        if (x < vet[meio])
        {
            return binary_search(vet, ini, meio - 1, x);
        }
        else
        {
            return binary_search(vet, meio + 1, fim, x);
        }
    }
}

int PesquisaBinaria(int k[], int chave, int N)
{
    int inf, sup, meio;
    inf = 0;
    sup = N - 1;
    while (inf < sup)
    {
        meio = (inf + sup) / 2;
        if (chave == k[meio])
            return meio;
        else if (chave < k[meio])
            sup = meio-1;
        else
            inf = meio + 1;
    }
    return -1; /* não encontrado */
}

int compara(const void *p1, const void *p2)
{
    int *i = (int *)p1, *j = (int *)p2;

    if (*i > *j)
        return 1;
    else if (*i == *j)
        return 0;
    else
        return -1;
}

int procura (int * vet, int tam, int x)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if (vet[i]==x)
        {
            return i;
        }
    }
    return -1;

}
