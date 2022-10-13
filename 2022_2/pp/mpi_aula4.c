#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

void preenche_valor(int *x);
void mostrar_vetor(int *vet, int tam);

int main()
{

    MPI_Init(NULL, NULL);
    int qtd_processos;
    int id_processo;
    char maquina[MPI_MAX_PROCESSOR_NAME];
    int tamanho_do_nome;

    clock_t t1, t2, t3, t4; // duas variáveis para guardar o registro clock

    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo);
    MPI_Get_processor_name(maquina, &tamanho_do_nome);

    MPI_Status status;

    if (id_processo == 0)
    {
        int x = 10;
        int y = 20;
        MPI_Send(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&y, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
    }
    else
    {
        int x,y;
        MPI_Recv(&y, 1, MPI_INT, 0, 1, MPI_COMM_WORLD,&status);
        printf("\n Y recebido: %d",y);
        MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,&status);
        printf("\n X recebido: %d",x);
    }

    MPI_Finalize();

    // printf("\n");
    return 0;
}

void preenche_valor(int *x)
{
    long long int i, j, z;

    *x = *x * 2;
    for (i = 0; i < 100000; i++)
    {
        for (j = 0; j < 100000; j++)
        {
            z = 1;
        }
    }
}

void mostrar_vetor(int *vet, int tam)
{
    int i;
    printf("\nVetor: ");
    for (i = 0; i < tam; i++)
        printf(" %d", vet[i]);
}
