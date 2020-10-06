#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <math.h>

//ponto nome 88888 seria o "0"
int i, j, p, k, n = 5, ponto_inicial;
double latitude[5] = {-15.754748, -15.751722, -15.750132, -15.747615, -15.742392};
double longitude[5] = {-47.839425, -47.841571, -47.843480, -47.846334, -47.852393};
int nome[5] = {88888, 111111, 222222, 33333, 4444444};
int matriz_predecessor[5];
int dist[10][10];

// double distancia; // acho que sera inutil

double funcao_conversor_latitude_longitude(double latitude1, double longitude1, double latitude2, double longitude2)
{
    double raio_da_terra = 6371; // raio da terra em km
    double pi = 3.1415927;
    int indice;

    double latitude1_radianos = latitude1 * pi / 180;
    double latitude2_radianos = latitude2 * pi / 180;
    double delta_latitude = ((latitude2 - latitude1) * pi / 180);
    double delta_longitude = ((longitude2 - longitude1) * pi / 180);

    double a = sin(delta_latitude / 2) * sin(delta_latitude / 2) + cos(latitude1_radianos) * cos(latitude2_radianos) * sin(delta_longitude / 2) * sin(delta_longitude);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = raio_da_terra * c * 1000;

    //    printf("\n dist: %.2lf km n", d);

    return d;
}

void funcao_execucao_floydwarshall()
{

    // printf("Insira o numero de vertices:\n"); // testar o nº de vertices como tamanho da struct
    // scanf("%d", &n);
    printf("\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            dist[i][j] = funcao_conversor_latitude_longitude(latitude[i], longitude[i], latitude[j], longitude[j]);
        }
    ////////////////// funcao_floyd_warshell//////////////////////////////////
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf(" \n\n Distancias mais curtas entre cada par de vartices:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d metros\t", dist[i][j]);
        printf("\n");
    }
}

// double funcao_menor(double a, double b)
// {
//     if (a < b)
//     {
//         a = b;
//     }
//     return a;
// }

// void funcao_comparar_predecessor()
// {
// }

void funcao_imprime_ordem(int pontoinicial)
{
    // pontoinicial fará o papel de "i"

    // int contador = 0;
    // p = 0;

    for (j = 0; j < n; j++)
    {
        for (k = 0; k < n; k++)
        {
            for (p = 0; p < n; p++)
            {
                if (matriz_predecessor[p] != j && matriz_predecessor[p] != k && matriz_predecessor[p] != pontoinicial)
                {
                    for (p = 0; p < n; p++)
                    {
                        if (pontoinicial != j && pontoinicial != k && dist[pontoinicial][j] != 0 && dist[pontoinicial][k] != 0 && matriz_predecessor[0] != pontoinicial)
                        {
                            // funcao_menor(dist[pontoinicial][j], dist[pontoinicial][k]);

                            printf("de %d para %d a distancia: %d, \n", nome[pontoinicial], nome[j], dist[pontoinicial][j]);

                            matriz_predecessor[p] = pontoinicial;
                            // p++;
                            pontoinicial = j;
                            //contador++;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    funcao_execucao_floydwarshall();

    printf("digite a posicao do ponto inicial: ");
    scanf("%d", &ponto_inicial);

    // for (int contador = 0; contador < n; contador++)
    // {
    for (int L = 0; L < n; L++)
    {
        matriz_predecessor[L] = 12345;
    }

    funcao_imprime_ordem(ponto_inicial);
    // }

    return 0;
}

/*
temos uma matriz i j com distâncias:

i é o ponto indicado como inicial pelo usuário

para i digitado pelo usuário e j de 0 a 5 as distâncias são:

i   j   distancia
1   0   840m
1   1   0m **A
1   2   350m
1   3   838m
1   4   300m **B

o menor caminho é 1-4 **C

printf (matriz ij, struct.nome[i], structnome[j])
a saida desse print será: a distancia 300m entre os pontos 1 e 4

// p=p
// matriz_predecessor[P]=i

i=j  (Ponto 1 = Ponto 4)
iguala o i ao j. assim leia-se que i recebe j.
Dessa forma, o novo i passa a ser 4

**A - criar um if para a restrição i!=j
**B - Após o i virar o j no final da função, como evitar que ele compare com o antigo i? e faça um "retorno"?
    
    criar um if(matriz_predecessor[p] != j)
    p++

    porém, dessa forma só consigo comparar o último i. então tem que ser um for a parte para a matriz predecessor

**C como descobrir qual o menor número?


return i (que é 4)
chama a função de novo
*/
