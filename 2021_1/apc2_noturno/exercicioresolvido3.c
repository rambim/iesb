/*
Faca um programa que leia tres valores inteiros e chame uma funcao que receba estes 3 
valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variavel, 
o segundo menor valor na variavel do meio, e o maior valor na ultima variavel. A funcao
deve retornar o valor 1 se os tres valores forem iguais e 0 se existirem valores diferentes.
Exibir os valores ordenados na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int ordenar(int * a, int * b, int * c);
int ordenar_2(int *a,int *b, int *c);

int main(int argc, char * argv[])
{
    int n1,n2,n3;
    int retorno;

    printf("\nDigite o valaor de N1: ");
    scanf("%d",&n1);
    printf("\nDigite o valaor de N2: ");
    scanf("%d",&n2);
    printf("\nDigite o valaor de N3: ");
    scanf("%d",&n3);

    retorno = ordenar_2(&n1,&n2,&n3);

    if (retorno==1)
    {
        printf("\n Numeros iguais");
    }
    else
    {
        printf("\n %d %d %d",n1,n2,n3);
    }

    printf("\n");
    return 0;
}

int ordenar(int * a, int * b, int * c)
{
    int x;
    if ((*a==*b) && (*b==*c))
    {
        return 1;
    }
    else
    {
        if (*a <= *b && *b <= *c)
        {
            return 0;
        }
        else
        {
            if (*b <= *a && *a <= *c)
            {
                x = *b;
                *b = *a;
                *a = x;
                return 0;
            }
            else
            {
                if (*c <= *a && *a <= *b)
                {
                    x = *a;
                    *a = *c;
                    *c = x;

                    x = *c;
                    *c = *b;
                    *b = x;
                    return 0;
                }
                else
                {
                    if (*a <= *c && *c <= *b)
                    {
                        x = *b;
                        *b = *c;
                        *c = x;
                        return 0;
                    }
                    else
                    {
                        if (*b <= *c && *c <= *a)
                        {
                            x = *c;
                            *c = *a;
                            *a = x;

                            x = *a;
                            *a = *b;
                            *b = x;
                            return 0;
                        }
                        else
                        {
                            x = *a;
                            *a = *c;
                            *c = x;
                            return 0;
                        }

                    }

                }

            }

        }
    }
}


int ordenar_2(int *a,int *b, int *c)
{
    int pass,i;
    int vet[3];
    vet[0] = *a;
    vet[1] = *b;
    vet[2] = *c;

    if ((*a==*b) && (*b==*c))
    {
        return 1;
    }

    int aux;
    for(pass=0;pass<3-1;pass++)
    {
        for(i=0;i<3-pass-1;i++)
        {
            if (vet[i] > vet[i+1])
            {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
        }
    }

    *a = vet[0];
    *b = vet[1];
    *c = vet[2];
    return 0;
}