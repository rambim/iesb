#include <stdio.h>
#include <mpi.h>

int main(int argc, char * argv[])
{
    int size, rank;
    MPI_Status st;

    int valor_inicial, valor_modificado, total=0,i;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

   // printf("\nHello World sou o processo %d do total de %d",rank,size);
    fflush(stdout);


    if (rank==0)
    {
        
        for(i=1;i<size;i++)
        {
            valor_inicial = i* 10;
            MPI_Send(&valor_inicial,1,MPI_INT,i,0,MPI_COMM_WORLD);
            printf("\nMestre - Enviei %d para Proc %d",valor_inicial,i);
            fflush(stdout);
        }

        for(i=1;i<size;i++)
        {
            MPI_Recv(&valor_modificado,1,MPI_INT,i,MPI_ANY_TAG,MPI_COMM_WORLD, &st);
            printf("\nMestre %d - Recebi o valor modificado = %d",rank,valor_modificado);
            total = total + valor_modificado;
            fflush(stdout);
        }
            printf("\n Total = %d",total);
    }
    else
    {
        MPI_Recv(&valor_inicial,1,MPI_INT, 0,0,MPI_COMM_WORLD, &st);
        printf("\nESCRAVO %d - Recebi %d do mestre",rank,valor_inicial);
        fflush(stdout);

        valor_modificado  = valor_inicial * 10;

        MPI_Send(&valor_modificado,1,MPI_INT,0,0,MPI_COMM_WORLD);
        printf("\nEscravo %d - valor modificado %d",rank,valor_modificado);
        fflush(stdout);
        
    }
    

    MPI_Finalize();

    return 0;
}