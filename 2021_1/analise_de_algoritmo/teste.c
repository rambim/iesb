#include <stdio.h>
#include <math.h>

#define pi M_PI

int main()
{
    float raio_maior;
    float raio_menor;

    float altura_corte;
    float altura;
    float diferencas_raios;
    float declinio;
    float novo_raio;
    float volume;

    raio_maior = 6;
    raio_menor = 5;
    altura = 8;
    altura_corte = altura / 2;
    diferencas_raios = raio_maior - raio_menor;

    if (diferencas_raios < 0)
        diferencas_raios = diferencas_raios * (-1);

    declinio = diferencas_raios / altura;

    do
    {
        
        novo_raio = raio_menor + (altura_corte * declinio);

        volume = ((pi * altura_corte) / 3) * ((novo_raio * novo_raio) + (novo_raio * raio_menor) + (raio_menor * raio_menor));
    } while (volume < 199.996 && volume > 200.004)

        novo_raio = raio_menor + (altura_corte * declinio);

    volume = ((pi * altura_corte) / 3) * ((novo_raio * novo_raio) + (novo_raio * raio_menor) + (raio_menor * raio_menor));

    printf("\n Raior  maior  : %f", raio_maior);
    printf("\n Raior  menor  : %f", raio_menor);
    printf("\n Diferenca     : %f", diferencas_raios);
    printf("\n Altura        : %f", altura);
    printf("\n Declinio      : %f", declinio);
    printf("\n Novo raio:    : %f", novo_raio);
    printf("\n Volume: %f", volume);

    printf("\n %f", pi);
    return 0;
}