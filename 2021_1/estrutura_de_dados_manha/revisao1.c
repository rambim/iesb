#include <stdio.h>
#include <stdlib.h>

typedef struct registro
{
    int numero1;
    int numero2;
    float valor1;
    float valor2;
}registro;

int main()
{
    

    printf("\nO tamanho de  um inteiro e de   : %ld bytes",sizeof(int));
    printf("\nO tamanho de  um float e de     : %ld bytes",sizeof(int));
    printf("\nO tamanho de  um char e de      : %ld bytes",sizeof(int));
    printf("\nO tamanho de  um registro e de  : %ld bytes",sizeof(int));


    int x = 2;
    int *ptr;

    ptr = &x;

    printf("\nConteudo de x  : %d",x);
    printf("\nConteudo de ptr: %d",ptr);
    printf("\nEndereco de x  : %d",&x);
    printf("\nEndereco de ptr: %d",&ptr);
    printf("\nConteudo apontado por ptr: %d",*ptr);

    int *y,*z;

    y = malloc(4);

    z =  (int*)malloc(sizeof(int));


    registro * aluno1;

    aluno1 = (registro*)malloc(sizeof(registro));


    (*aluno1).numero1 = 1;
    aluno1->numero2 = 2;


    registro * turma;

    turma = (registro*)malloc(sizeof(registro)*20);

    turma[2].numero1 = 2 ;


    int vet[10];

    printf("%d",vet);
    printf("%d",&vet[0]);
    
    return 0;

}