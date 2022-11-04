#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 7

int main(int argc, char *argv[])
{
    int rank, size;
    int rec_buf[SIZE];
    int n, i;
    int *data;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // if (rank == 0)
    // {
    //     scanf("%d", &n);
    //     data = (int *)malloc(sizeof(int) * n);
    //     for (i = 0; i < n; i++)
    //     {
    //         data[i] = i + 1;
    //     }
    //     for (i = 0; i < n; i++)
    //     {
    //         printf("I = %d : %d\n", i, data[i]);
    //     }
    //     printf("Quantidade de threads: %d\n", size);
    // }

    // MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    // printf("Rank: %d Valor de N: %d\n", rank, n);
    // printf("Rank: %d Quantiadde de threads: %d\n", rank, size);

    int tam_por_thread = n / size;

    // printf("Rank: %d tamanho por thread %d\n", rank, tam_por_thread);

    int *sendcounts = malloc(sizeof(int) * size);
    int *displs = malloc(sizeof(int) * size);

    int aux;
    if (rank == 0)
    {
        aux = n;
        for (i = size - 1; i>0; i--)
        {
            sendcounts[i] = tam_por_thread;
            aux = aux - sendcounts[i];
            displs[i] = aux;
        }
        sendcounts[i] = n - (tam_por_thread * (size - 1));
        aux = aux - sendcounts[i];
        displs[i] = aux;

        for (i = 0; i < size; i++)
        {
            printf("Sendount indice %d = %d\n", i, sendcounts[i]);
            printf("displ indice %d = %d\n", i, displs[i]);
        }
    }

    // sendcounts[0] = 2;
    // sendcounts[1] = 1;
    // sendcounts[2] = 3;
    // sendcounts[3] = 1;

    // displs[0] = 5;
    // displs[1] = 4;
    // displs[2] = 1;
    // displs[3] = 0;

    // MPI_Scatterv(&data, sendcounts, displs, MPI_INT, &rec_buf, 7, MPI_INT, 0, MPI_COMM_WORLD);

    // printf("%d: ", rank);
    // for (int i = 0; i < sendcounts[rank]; i++) {
    //     printf("%d\t", rec_buf[i]);
    // }
    // printf("\n");

    MPI_Finalize();

    // free(sendcounts);
    // free(displs);

    return 0;
}