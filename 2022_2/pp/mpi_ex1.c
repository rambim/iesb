#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

int main()
{
    int qtd_processos;
    int id_processo;
    char maquina[MPI_MAX_PROCESSOR_NAME];
    int tamanho_do_nome;
    double start;
    const double waiting_time = 1;
    int cc0,cc1,cc2,cc3,cc4;

    cc0=cc1=cc2=cc3=cc4=0;

    MPI_Status status;

    int x = 0;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo);
    MPI_Get_processor_name(maquina, &tamanho_do_nome);

    switch (id_processo)
    {
    case 0:
        while (1)
        {
            start = MPI_Wtime();
            while (MPI_Wtime() - start < 5)
            {
                // We keep looping until <waiting_time> seconds have elapsed
            }
            cc0++;
            printf("\n Sou a thread %d %d", id_processo,cc0);
        }
        break;
    case 1:
        while (1)
        {
            start = MPI_Wtime();
            while (MPI_Wtime() - start < 2)
            {
                // We keep looping until <waiting_time> seconds have elapsed
            }
            cc1++;
            printf("\n Sou a thread %d %d", id_processo,cc1);
            MPI_Probe(0,0,MPI_COMM_WORLD,&status);
            printf("\n Sou a thread %d %d %d", id_processo,cc1,status.MPI_ERROR);
            printf("\n Sou a thread %d %d %d", id_processo,cc1,status.MPI_SOURCE);
            printf("\n Sou a thread %d %d %d", id_processo,cc1,status.MPI_TAG);
        }
        break;
    case 2:
        while (1)
        {
            start = MPI_Wtime();
            while (MPI_Wtime() - start < 2)
            {
                // We keep looping until <waiting_time> seconds have elapsed
            }
            cc2++;
            printf("\n Sou a thread %d %d", id_processo,cc2);
        }
        break;
    case 3:
        while (1)
        {
            start = MPI_Wtime();
            while (MPI_Wtime() - start < 2)
            {
                // We keep looping until <waiting_time> seconds have elapsed
            }
            cc3++;
            printf("\n Sou a thread %d %d", id_processo,cc3);
        }
        break;
    default:
        printf("\n Sou a thread %d", id_processo);
        break;
    }

    MPI_Finalize();
    printf("\n");
    return 0;
}