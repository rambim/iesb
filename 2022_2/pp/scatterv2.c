#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//fonte: https://gist.github.com/ehamberg/1263868/cae1d85dee821d45fb0cd58747aaf33370f3f1ed

#define SIZE 7

int main(int argc, char *argv[])
{
    int rank, size;     
    int rec_buf[SIZE];          

    int data[SIZE]= {1,2,3,4,5,6,7};

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int *sendcounts = malloc(sizeof(int)*size);
    int *displs = malloc(sizeof(int)*size);

    sendcounts[0] = 2;
    sendcounts[1] = 1;
    sendcounts[2] = 3;
    sendcounts[3] = 1;

    displs[0] = 5;
    displs[1] = 4;
    displs[2] = 1;
    displs[3] = 0;

    MPI_Scatterv(&data, sendcounts, displs, MPI_INT, &rec_buf, 7, MPI_INT, 0, MPI_COMM_WORLD);

    printf("%d: ", rank);
    for (int i = 0; i < sendcounts[rank]; i++) {
        printf("%d\t", rec_buf[i]);
    }
    printf("\n");

    MPI_Finalize();

    free(sendcounts);
    free(displs);

    return 0;
}