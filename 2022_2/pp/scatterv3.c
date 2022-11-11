#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 7

int main(int argc, char *argv[])
{
    int rank, qtd_processos;
    int rec_buf[TAM];
    int n, i;
    int data[TAM] = {1, 2, 3, 4, 5, 6, 7};
    int tamanho;
    int *vet;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);

    int *sendcounts = malloc(sizeof(int) * qtd_processos);
    int *displs = malloc(sizeof(int) * qtd_processos);

    if (rank == 0)
    {
        scanf("%d", &tamanho);
    }
    MPI_Bcast(&tamanho, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Rank %d = %d\n", rank, tamanho);
    vet = (int *)malloc(sizeof(int) * tamanho);

    if (rank == 0)
    {
        for (i = 0; i < tamanho; i++)
        {
            vet[i] = i + 1;
        }
    }

    MPI_Barrier(MPI_COMM_WORLD);
    int tam_por_thread = TAM / qtd_processos;
    int tam_ult_thread = TAM - (tam_por_thread * (qtd_processos - 1));
    for (i = 0; i < qtd_processos - 1; i++)
    {
        // printf("\n Thread %d = Tam = %d", i, tam_por_thread);
        displs[i] = TAM - (i + 1) * tam_por_thread;
        sendcounts[i] = tam_por_thread;
    }

    // printf("\n Thread %d = Tam = %d", i, tam_ult_thread);
    displs[i] = 0;
    sendcounts[i] = tam_ult_thread;

    MPI_Scatterv(vet, sendcounts, displs, MPI_INT, &rec_buf, tamanho, MPI_INT, 0, MPI_COMM_WORLD);

    printf("\n%d: ", rank);
    for (int i = 0; i < sendcounts[rank]; i++)
    {
        printf("%d\t", rec_buf[i]);
    }
    printf("\n");

    MPI_Finalize();

    free(sendcounts);
    free(displs);

    return 0;
}