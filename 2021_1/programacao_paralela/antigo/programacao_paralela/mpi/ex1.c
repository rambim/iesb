#include <stdio.h>
#include <mpi.h>

int main(int argc, char * argv[])
{
    int size, rank;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    printf("\nHello World sou o processo %d do total de %d",rank,size);
    fflush(stdout);

    MPI_Finalize();

    return 0;
}