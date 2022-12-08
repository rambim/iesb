#include "mpi.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    MPI_Status status;

    printf("\nRank: %d", world_rank);
    if (world_rank == 0)
    {
        int x,retorno1,retorno2;
        x = 10;
        printf("\nRank 0 enviando valor 10 na variavel x pro rank 1");
        MPI_Send(&x, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);

        x = 20;
        printf("\nRank 0 enviando valor 10 na variavel x pro rank 2");
        MPI_Send(&x, 1, MPI_INT, 2, 1, MPI_COMM_WORLD);

        printf("\n Aguardando retorno do rank 1");
        MPI_Recv(&retorno1,1,MPI_INT,1,1,MPI_COMM_WORLD,&status);
        printf("\n Valor retornado pelo rank 1: %d",retorno1);

        printf("\n Aguardando retorno do rank 2");
        MPI_Recv(&retorno2,1,MPI_INT,2,1,MPI_COMM_WORLD,&status);
        printf("\n Valor retornado pelo rank 2: %d",retorno2);
    }
    else
    {
        int y;
        switch (world_rank)
        {
        case 1:
            printf("\nIniciando recebimento rank %d", world_rank);
            MPI_Recv(&y, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
            printf("\nValor recebido pelo rank %d: %d",world_rank, y);
            y = 15;
            MPI_Send(&y,1,MPI_INT,0,1,MPI_COMM_WORLD);
            break;
        case 2:
            printf("\nIniciando recebimento rank %d", world_rank);
            MPI_Recv(&y, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
            printf("\nValor recebido pelo rank %d: %d",world_rank, y);
            y = 25;
            MPI_Send(&y,1,MPI_INT,0,1,MPI_COMM_WORLD);
            break;
        default:
            break;
        }
    }

    // // Get the name of the processor
    // char processor_name[MPI_MAX_PROCESSOR_NAME];
    // int name_len;
    // MPI_Get_processor_name(processor_name, &name_len);

    // // Print off a hello world message
    // printf("Hello world from processor %s, rank %d out of %d processors\n",
    //        processor_name, world_rank, world_size);

    // // Finalize the MPI environment.
    MPI_Finalize();
    printf("\n");
    return 0;
}