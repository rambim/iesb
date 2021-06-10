#include <stdlib.h>
#include <stdio.h>
#include "omp.h"

long long int fibo_recursivo(long long int n);
long long int fibo_iterativo(long long int n);
void multiplicar_duas_matrizes(long long int m1[2][2], long long int m2[2][2]);
void potencia_matriz(long long int m[2][2], int exp);
long long int fibo_matricial(long long int n);

int main(){
    double t1, t2;
    long long int casos[] = {1,5,15,20,25,30,35,40};
    int tamanho = sizeof(casos)/sizeof(casos[0]);

    printf("\n Tempos de execução em forma recursiva\n");
    for(int i = 0; i < tamanho; i++){
        t1 = omp_get_wtime();
        printf("-> %lld:",fibo_recursivo(casos[i]));
        t2 = omp_get_wtime();

        printf("%lld-esimo termo: ", casos[i]);
        printf("%lf s\n", t2-t1);
    }

    printf("\n Tempos de execução em forma iterativa\n");
    for(int i = 0; i < tamanho; i++){
        t1 = omp_get_wtime();
        printf("-> %lld: ",fibo_iterativo(casos[i]));
        t2 = omp_get_wtime();

        printf("%lld-esimo termo: ", casos[i]);
        printf("%lf s\n", t2-t1);
    }

    printf("\n Tempos de execução em forma matricial\n");
    for(int i = 0; i < tamanho; i++){
        t1 = omp_get_wtime();
        printf("-> %lld: ",fibo_matricial(casos[i]));
        t2 = omp_get_wtime();

        printf("%lld-esimo termo: ", casos[i]);
        printf("%lf s\n", t2-t1);
    }
}

// 1.a
long long int fibo_recursivo(long long int n) {
    
    if(n <= 1){
        return n;
    }
    
    return fibo_recursivo(n-1) + fibo_recursivo(n-2);
}

// 1.b
long long int fibo_iterativo(long long int n){
    long long int primeira, segunda, terceira;

    if(n == 1 || n == 2)
        return 1;

    primeira = 1;
    segunda = 1;
    terceira = 0;
    for(int i = 0; i<n-2; i++){
        terceira = primeira + segunda;
        primeira = segunda;
        segunda = terceira;
    }

    return terceira;
}


// aux 1.c
void multiplicar_duas_matrizes(long long int m1[2][2], long long int m2[2][2]){
    long long int a =  m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
    long long int b =  m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
    long long int c =  m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
    long long int d =  m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
    m1[0][0] = a;
    m1[0][1] = b;
    m1[1][0] = c;
    m1[1][1] = d;
}

// aux 1.c
void potencia_matriz(long long int m[2][2], int exp){
    if (exp == 0 || exp == 1){
        return;
    }

    long long int aux_matrix[2][2] = {{1,1},{1,0}};

    potencia_matriz(m,exp/2);
    multiplicar_duas_matrizes(m,m);
    if (exp % 2 != 0){
        multiplicar_duas_matrizes(m, aux_matrix);
    } 
}

// 1.c
long long int fibo_matricial(long long int n){
    long long int matriz_principal[2][2] = {{1,1}, {1,0}};

    if(n == 0)
        return 0;

    potencia_matriz(matriz_principal, n-1);

    return matriz_principal[0][0];
}