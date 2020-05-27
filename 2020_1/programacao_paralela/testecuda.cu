#include <stdio.h>
#include <cuda.h>
#include <cuda_runtime.h>

__global__ void teste()
{
    printf("hello world GPU");
    printf("\n");
}

int main()
{
    teste<<<2,2>>>();
    printf("hello awdawdworld");
    printf("\n");
    return 0;
}