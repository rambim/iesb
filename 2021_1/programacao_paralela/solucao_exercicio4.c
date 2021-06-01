#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "mpi.h"

int main()
{
    int qtd_processos;
    int id_processo;
    char maquina[MPI_MAX_PROCESSOR_NAME];
    int tamanho_do_nome;
    
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo);
    MPI_Get_processor_name(maquina, &tamanho_do_nome);

    MPI_Status status;

    int x, y, z;

    switch (id_processo)
    {
    case 0:
        printf("\nDigite o valor de X: ");
        __fpurge(stdout);
        scanf("%d", &x);
        printf("\nDigite o valor de Y: ");
        __fpurge(stdout);
        scanf("%d", &y);

        MPI_Send(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&y, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
        MPI_Recv(&z, 1, MPI_INT, 5, 0, MPI_COMM_WORLD,&status);

        printf("\nMaquina: %s Id: %d  Valor resultado: %d",maquina, id_processo,z);
        break;
    case 1:
        MPI_Recv(&x,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
        x = x * 2;
        MPI_Send(&x,1,MPI_INT,2,0,MPI_COMM_WORLD);
        break;
    case 2:
        MPI_Recv(&x,1,MPI_INT,1,0,MPI_COMM_WORLD,&status);
        x = x - 10;
        MPI_Send(&x,1,MPI_INT,5,0,MPI_COMM_WORLD);
        break;
    case 3:
        MPI_Recv(&y,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
        y = y * 3;
        MPI_Send(&y,1,MPI_INT,4,0,MPI_COMM_WORLD);
        break;
    case 4:
        MPI_Recv(&y,1,MPI_INT,3,0,MPI_COMM_WORLD,&status);
        y = y - 20;
        MPI_Send(&y,1,MPI_INT,5,0,MPI_COMM_WORLD);
        break;
    case 5:
        MPI_Recv(&x,1,MPI_INT,2,0,MPI_COMM_WORLD,&status);
        MPI_Recv(&y,1,MPI_INT,4,0,MPI_COMM_WORLD,&status);
        z = x + y;
        MPI_Send(&z,1,MPI_INT,0,0,MPI_COMM_WORLD);
        break;
    }

    MPI_Finalize();

    printf("\n");
    return 0;
}