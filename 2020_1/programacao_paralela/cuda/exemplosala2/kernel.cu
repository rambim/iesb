
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdlib.h>
#include "omp.h"

#include <stdio.h>
#define tamanho 1000

cudaError_t addWithCuda(int *c, const int *a, const int *b, unsigned int size);
void preenche_vetor(unsigned long long int* vet,  unsigned long long int num);
void mostrar_vetor(unsigned long long int* vet);
void somar_vetores(unsigned long long int* a, unsigned long long int* b, unsigned long long int* c);

__global__ void addKernel(int *c, const int *a, const int *b)
{
    int i = threadIdx.x;
    c[i] = a[i] + b[i];

    

}


__global__ void somar_vetores_gpu(unsigned long long int* a, unsigned long long int* b, unsigned long long int* c)
{
    unsigned long long int qtd_threads = blockDim.x;
    unsigned long long int qtd_blocos = gridDim.x;
    unsigned long long int thread_id = threadIdx.x;
    unsigned long long int block_id = blockIdx.x;
    long int aux1, aux2;

  //  printf("\nEu sou a thread %d/%d do Bloco %d/%d", thread_id, qtd_threads-1, block_id, qtd_blocos-1);

    if (block_id < tamanho)
    {
        c[block_id] = a[block_id] + b[block_id];

        for (aux1 = 0; aux1 < 10000; aux1++)
        {
            for (aux2 = 0; aux2 < 10000; aux2++)
            {
                aux1 = aux1;
            }
        }

    }

    
}

void somar_vetores(unsigned long long int* a, unsigned long long int* b, unsigned long long int* c)
{
    int i;
    long int aux1, aux2;

    for (i = 0; i < tamanho; i++)
    {
        c[i] = a[i] + b[i];
        for (aux1 = 0; aux1 < 10000; aux1++)
        {
            for (aux2 = 0; aux2 < 10000; aux2++)
            {
                aux1 = aux1;
            }
        }
    }

}

int main()
{
    unsigned long long int* a, * b, * c, * a_gpu, * b_gpu, * c_gpu;
    unsigned long long int tam;
    tam = tamanho;
    

    double t1, t2;
        
    printf("\nTamanho = %llu", tamanho);

    t1 = omp_get_wtime();
    a = (unsigned long long int *)malloc(sizeof(unsigned long long int) * tamanho);
    b = (unsigned long long int*)malloc(sizeof(unsigned long long int) * tamanho);
    c = (unsigned long long int*)malloc(sizeof(unsigned long long int) * tamanho);
    t2 = omp_get_wtime();
    printf("\nTempo de alocacao de vetores na CPU: %lf", t2 - t1);

    t1 = omp_get_wtime();
    cudaMalloc((void**)&a_gpu, sizeof(unsigned long long int) * tamanho);
    cudaMalloc((void**)&b_gpu, sizeof(unsigned long long int) * tamanho);
    cudaMalloc((void**)&c_gpu, sizeof(unsigned long long int) * tamanho);
    t2 = omp_get_wtime();
    printf("\nTempo de alocacao de vetores na GPU: %lf", t2 - t1);


    preenche_vetor(a, 2);
    preenche_vetor(b, 4);
    
/*
    printf("\nMostrando vetor 1: ");
    mostrar_vetor(a, tamanho);
    printf("\nMostrando vetor 2: ");
    mostrar_vetor(b, tamanho);

*/
    
    t1 = omp_get_wtime();
    cudaMemcpy(a_gpu, a, tamanho * sizeof(unsigned long long int), cudaMemcpyHostToDevice);
    cudaMemcpy(a_gpu, b, tamanho * sizeof(unsigned long long int), cudaMemcpyHostToDevice);
    t2 = omp_get_wtime();
    printf("\nTempo de copia da CPU para GPU: %lf", t2 - t1);

    t1 = omp_get_wtime();
    somar_vetores (a, b,c);
    t2 = omp_get_wtime();
    printf("\nTempo da Soma na CPU: %lf", t2 - t1);

    t1 = omp_get_wtime();
     somar_vetores_gpu << <tam, 1 >> > (a_gpu, b_gpu, c_gpu);
    t2 = omp_get_wtime();
    printf("\nTempo da Soma na GPU: %lf", t2 - t1);

    printf("\n");
    free(a);
    free(b);
    free(c);

    cudaFree(a_gpu);
    cudaFree(b_gpu);
    cudaFree(c_gpu);
    return 0;
}


void preenche_vetor(unsigned long long int* vet, unsigned long long int num)
{
    unsigned long long int i;

    for (i = 0; i < tamanho; i++)
    {
        vet[i] = num;
    }
}


void mostrar_vetor(unsigned long long int* vet)
{
    unsigned long long int i;

    for (i = 0; i < tamanho; i++)
    {
        printf("%lld ", vet[i]);
    }
}

// Helper function for using CUDA to add vectors in parallel.
cudaError_t addWithCuda(int *c, const int *a, const int *b, unsigned int size)
{
    int *dev_a = 0;
    int *dev_b = 0;
    int *dev_c = 0;
    cudaError_t cudaStatus;

    // Choose which GPU to run on, change this on a multi-GPU system.
    cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
        goto Error;
    }

    // Allocate GPU buffers for three vectors (two input, one output)    .
    cudaStatus = cudaMalloc((void**)&dev_c, size * sizeof(int));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    cudaStatus = cudaMalloc((void**)&dev_a, size * sizeof(int));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    cudaStatus = cudaMalloc((void**)&dev_b, size * sizeof(int));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    // Copy input vectors from host memory to GPU buffers.
    cudaStatus = cudaMemcpy(dev_a, a, size * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

    cudaStatus = cudaMemcpy(dev_b, b, size * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

    // Launch a kernel on the GPU with one thread for each element.
    addKernel<<<1, size>>>(dev_c, dev_a, dev_b);

    // Check for any errors launching the kernel
    cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
        goto Error;
    }
    
    // cudaDeviceSynchronize waits for the kernel to finish, and returns
    // any errors encountered during the launch.
    cudaStatus = cudaDeviceSynchronize();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
        goto Error;
    }

    // Copy output vector from GPU buffer to host memory.
    cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(int), cudaMemcpyDeviceToHost);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

Error:
    cudaFree(dev_c);
    cudaFree(dev_a);
    cudaFree(dev_b);
    
    return cudaStatus;
}
