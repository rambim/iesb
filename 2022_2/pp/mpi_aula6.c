#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
void delay();
void preenche_vetor(int * vet, int tam);

int main()
{

    int qtd_processos;
    int id_processo;
    char maquina[MPI_MAX_PROCESSOR_NAME];
    int tamanho_do_nome;

    
    int * vet;
    int valor=0;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo);
    MPI_Get_processor_name(maquina, &tamanho_do_nome);

    if (id_processo==0)
    {
        vet = (int*)calloc(10,sizeof(int));
        preenche_vetor(vet,10);
    }

    printf("\nAntes do Scatter: Maquina: %s Id: %d Valor : %d\n", maquina, id_processo, valor);

    MPI_Scatter( &vet[3] , 1 , MPI_INT , &valor , 1 , MPI_INT , 0 , MPI_COMM_WORLD);

    
    printf("\nDepois do Scatter: Maquina: %s Id: %d Valor : %d\n", maquina, id_processo, valor);
   
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

void preenche_vetor(int * vet, int tam)
{
    int i;
    for(i=0;i<tam;i++)
        vet[i] = i + 1;
}