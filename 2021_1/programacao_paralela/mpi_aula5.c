#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
void delay();

int main()
{

    int qtd_processos;
    int id_processo;
    char maquina[MPI_MAX_PROCESSOR_NAME];
    int tamanho_do_nome;

    clock_t t1, t2, t3, t4; // duas variáveis para guardar o registro clock
    int x = 0;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo);
    MPI_Get_processor_name(maquina, &tamanho_do_nome);

    if (id_processo == 0)
    {
        x = 10;
    }

    printf("\nAntes do Broadcast: Maquina: %s Id: %d Valor de X: %d\n", maquina, id_processo, x);
    void delay();

    MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("\nDepois do Broadcast: Maquina: %s Id: %d Valor de X: %d\n", maquina, id_processo, x);
    MPI_Finalize();

    return 0;
}

void delay()
{
    int i, j, z;
    for (i = 0; i < 1000; i++)
        for (j = 0; j < 1000; j++)
            z = 1;
}