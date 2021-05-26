#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main()
{

    MPI_Init(NULL, NULL);
    int qtd_processos;
    int id_processo;
    char maquina[MPI_MAX_PROCESSOR_NAME];
    int tamanho_do_nome;

    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo);
    MPI_Get_processor_name(maquina, &tamanho_do_nome);

    MPI_Status status;

    if (id_processo == 0)
    {
        printf("\nTotal de Processos: %d", qtd_processos);

        int x=10;
        printf("\nMaquina: %s Id: %d - Enviando X para ID 1 ", maquina, id_processo);
        MPI_Send(&x,1,MPI_INT,1,0,MPI_COMM_WORLD);

        printf("\nMaquina: %s Id: %d - Recebendo resposta do ID 1 ", maquina, id_processo);
        MPI_Recv(&x,1,MPI_INT,1,0,MPI_COMM_WORLD,&status);
        printf("\nStatus do recebimento da mensagem:  ");
        printf("\nX = %d",x);
        printf("\nErro: %d ",status.MPI_ERROR);
        printf("\nOrigem: %d",status.MPI_SOURCE);

        
    }
    else
    {
        int y;
        printf("\nMaquina: %s Id: %d - Vou receber o valor em Y que veio do ID 0 ", maquina, id_processo);
        MPI_Recv(&y,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
        printf("\nStatus do recebimento da mensagem:  ");
        printf("\nY = %d",y);
        printf("\nErro: %d ",status.MPI_ERROR);
        printf("\nOrigem: %d",status.MPI_SOURCE);

        y = 20;
        MPI_Send(&y,1,MPI_INT,0,0,MPI_COMM_WORLD);

    }

    // printf("\nMaquina: %s Id: %d ", maquina, id_processo);

    MPI_Finalize();

    printf("\n");
    return 0;
}

// void print_id()

// typedef struct _MPI_Status {
//   int count;
//   int cancelled;
//   int MPI_SOURCE;
//   int MPI_TAG;
//   int MPI_ERROR;
// } MPI_Status, *PMPI_Status;