#include <stdio.h>
#include <stdlib.h>

void ordenar(float vet[], int tam);
int valida_triangulo_isoceles(float *vet);
int valida_triangulo_equilatero(float *vet);
int valida_triangulo_acutangulo(float *vet);
int valida_triangulo_obtusangulo(float *vet);
int valida_triangulo_retangulo(float *vet);
int valida_se_nao_forma_trinagulo(float *vet);
int main()
{

    float vet[3];
    int i;

    scanf("%f %f %f", &vet[0], &vet[1], &vet[2]);

    ordenar(vet, 3);

    for (i = 0; i < 3; i++)
    {
        printf("%.2f ", vet[i]);
    }

    if (valida_se_nao_forma_trinagulo(vet))
        printf("\n Nao forma triangulo");

    else
    {
        if (valida_triangulo_retangulo(vet))
            printf("\n triangulo retangulo");

        if (valida_triangulo_acutangulo(vet))
            printf("\n triangulo acutangulo");

        if (valida_triangulo_equilatero(vet))
            printf("\n triangulo equilatero");
        else
        {
            if (valida_triangulo_isoceles(vet))
                printf("\n triangulo isoceles");
        }

        if (valida_triangulo_obtusangulo(vet))
            printf("\n triangulo obtusangulo");
    }

    printf("\n");
    return 0;
}

int valida_se_nao_forma_trinagulo(float *vet)
{
    if (vet[0] >= (vet[1] + vet[2]))
        return 1;
    else
        return 0;
}

int valida_triangulo_retangulo(float *vet)
{
    float a_quadrado, b_quadrado, c_quadrado;
    a_quadrado = vet[0] * vet[0];
    b_quadrado = vet[1] * vet[1];
    c_quadrado = vet[2] * vet[2];

    if (a_quadrado == (b_quadrado + c_quadrado))
        return 1;
    else
        return 0;
}

int valida_triangulo_obtusangulo(float *vet)
{
    float a_quadrado, b_quadrado, c_quadrado;
    a_quadrado = vet[0] * vet[0];
    b_quadrado = vet[1] * vet[1];
    c_quadrado = vet[2] * vet[2];

    if (a_quadrado > (b_quadrado + c_quadrado))
        return 1;
    else
        return 0;
}

int valida_triangulo_acutangulo(float *vet)
{
    float a_quadrado, b_quadrado, c_quadrado;
    a_quadrado = vet[0] * vet[0];
    b_quadrado = vet[1] * vet[1];
    c_quadrado = vet[2] * vet[2];

    if (a_quadrado < (b_quadrado + c_quadrado))
        return 1;
    else
        return 0;
}

int valida_triangulo_equilatero(float *vet)
{
    if (vet[0] == vet[1] && vet[1] == vet[2])
        return 1;
    else
        return 0;
}

int valida_triangulo_isoceles(float *vet)
{
    if (vet[0] == vet[1] || vet[1] == vet[2] || vet[2] == vet[0] && (!valida_triangulo_equilatero(vet)))
        return 1;
    else
        return 0;
}

void ordenar(float vet[], int tam)
{
    int qtd_vezes, i;
    float aux;

    for (qtd_vezes = 0; qtd_vezes < tam - 1; qtd_vezes++)
    {
        for (i = 0; i < tam - 1 - qtd_vezes; i++)
        {
            if (vet[i] < vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
            }
        }
    }
}
