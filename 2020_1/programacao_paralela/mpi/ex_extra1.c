#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, soma=0, sub=0, mult=1, tam=0;
    int * vet;


    printf("\nDigite o tamanho do vetor: ");
    scanf("%d",&tam);

    vet = (int*)malloc(sizeof(int)*tam);

    for(i=0;i<tam;i++)
    {
        vet[i] = i+1;
    }

    for(i=0;i<tam;i++)
    {
        soma = soma + vet[i];
        sub = sub - vet[i];
        mult = mult * vet[i];

    }

    printf("\nSoma = %d",soma);
    printf("\nSub  = %d",sub);
    printf("\nMult = %d",mult);


}


/*

1) o Vetor vet é o vetor onde ocorrem as operações de somatorio, produtório, etc. Adapte 
o código para que seja executado em paralelo usandi MPI.

a)(0,5) versão 1 : 4 processos executando. Cada processo faz uma função, 1 soma, 1 subtrai e 1 multiplica. O processo
que sobrou é responsável por orquestrar a execução dos 3 e apresentar os resultados.

b) (0,5)versão 2: Modelo mestre escravo de forma que seja distribuída os calculos a serem feitos da forma mais
balanceada possível

*/