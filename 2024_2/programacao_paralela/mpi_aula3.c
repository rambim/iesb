#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

void preenche_valor(int *x);
void mostrar_vetor(int *vet, int tam);

int main()
{

    MPI_Init(NULL, NULL);
    int qtd_processos;
    int id_processo;
    char maquina[MPI_MAX_PROCESSOR_NAME];
    int tamanho_do_nome;

    clock_t t1, t2,t3,t4; // duas variáveis para guardar o registro clock

    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo);
    MPI_Get_processor_name(maquina, &tamanho_do_nome);

    MPI_Status status;

    int *vet, i;
    float diff;

    vet = (int *)calloc(5, sizeof(int));
    for (i = 0; i < 5; i++)
    {
        vet[i] = i + 2;
    }

    if (id_processo == 0)
    {
        printf("\nTotal de Processos: %d", qtd_processos);

        printf("\nMaquina: %s Id: %d", maquina, id_processo);

        t1 = clock(); // pega esse instante

        for (i = 0; i < 5; i++)
        {
            MPI_Send(&vet[i], 1, MPI_INT, i + 1, 0, MPI_COMM_WORLD);
        }

        for (i = 0; i < 5; i++)
        {
            MPI_Recv(&vet[i], 1, MPI_INT, i + 1, 0, MPI_COMM_WORLD,&status);
        }

        t2 = clock();

        mostrar_vetor(vet, 5);
        diff = (((float)t2 - (float)t1) / 1000000.0F); // mile segundos
        printf("\nTempo gasto: %f", diff);
    }
    else
    {
        int x;
        switch (id_processo)
        {
        case 1:
            
            MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
            t3 = clock();
            preenche_valor(&x);
            MPI_Send(&x,1,MPI_INT,0,0,MPI_COMM_WORLD);
            t4 = clock();
            diff = (((float)t4 - (float)t3) / 1000000.0F); // mile segundos
            // printf("\nMaquina: %s Id: %d Tempo gasto: %f",maquina, id_processo, diff);

            break;
        case 2:
            MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
            t3 = clock();
            preenche_valor(&x);
            MPI_Send(&x,1,MPI_INT,0,0,MPI_COMM_WORLD);
            t4 = clock();
            diff = (((float)t4 - (float)t3) / 1000000.0F); // mile segundos
            // printf("\nMaquina: %s Id: %d Tempo gasto: %f",maquina, id_processo, diff);
            break;
        case 3:
            MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
            t3 = clock();
            preenche_valor(&x);
            MPI_Send(&x,1,MPI_INT,0,0,MPI_COMM_WORLD);
            t4 = clock();
            diff = (((float)t4 - (float)t3) / 1000000.0F); // mile segundos
            // printf("\nMaquina: %s Id: %d Tempo gasto: %f",maquina, id_processo, diff);
            break;
        case 4:
            MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
            t3 = clock();
            preenche_valor(&x);
            MPI_Send(&x,1,MPI_INT,0,0,MPI_COMM_WORLD);
            t4 = clock();
            diff = (((float)t4 - (float)t3) / 1000000.0F); // mile segundos
            // printf("\nMaquina: %s Id: %d Tempo gasto: %f",maquina, id_processo, diff);
            break;
        case 5:
            MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
            t3 = clock();
            preenche_valor(&x);
            MPI_Send(&x,1,MPI_INT,0,0,MPI_COMM_WORLD);
            t4 = clock();
            diff = (((float)t4 - (float)t3) / 1000000.0F); // mile segundos
            // printf("\nMaquina: %s Id: %d Tempo gasto: %f",maquina, id_processo, diff);
            break;
        }
    }

    MPI_Finalize();

    // printf("\n");
    return 0;
}

void preenche_valor(int *x)
{
    long long int i, j, z;

    *x = *x * 2;
    for (i = 0; i < 100000; i++)
    {
        for (j = 0; j < 100000; j++)
        {
            z = 1;
        }
    }
}

void mostrar_vetor(int *vet, int tam)
{
    int i;
    printf("\nVetor: ");
    for (i = 0; i < tam; i++)
        printf(" %d", vet[i]);
}
