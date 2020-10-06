#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include "omp.h"


__global__ void funcao1(int *var_gpu)
{
    printf("a");
    *var_gpu = 2;
}

int main()
{
    int var, *var_gpu;

    var =0;
    cudaMalloc((void**)&var_gpu,sizeof(int));
    cudaMemcpy(var_gpu,&var,sizeof(int),cudaMemcpyHostToDevice);

    funcao1<<<10,10>>>(var_gpu);
    
    cudaMemcpy(&var,var_gpu,sizeof(int),cudaMemcpyDeviceToHost);

    printf("var2 = %d\n",var);
    cudaFree(var_gpu);
    return 0;
    
}