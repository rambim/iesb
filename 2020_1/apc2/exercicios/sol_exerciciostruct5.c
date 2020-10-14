#include <stdio.h>
#include <stdlib.h>
#define tam 5

typedef struct carro
{
    long int chassi;
    int ano;
    float preco;
} carro;

void preenche_carro1(carro *a);
carro preenche_carro2();
void preenche_vetor_carros(carro *vet, int qtd);
void mostra_carro(carro a);
int main()
{
    carro vet_carros[tam];
    float p = 1;
    int i;

    preenche_vetor_carros(vet_carros, tam);

    while (p != 0)
    {
        printf("\n Digite o valor p: ");
        scanf("%f", &p);
        if (p != 0)
        {
            for (i = 0; i < tam; i++)
            {
                if (vet_carros[i].preco < p)
                {
                    mostra_carro(vet_carros[i]);
                }
            }
        }
    }

    return 0;
}

void preenche_carro1(carro *a)
{
    printf("\n Digite o chassi: ");
    scanf("%ld", &a->chassi);
    printf("\n Digite o ano: ");
    scanf("%d", &a->ano);
    printf("\n Digite o preco: ");
    scanf("%f", &a->preco);
}

carro preenche_carro2()
{
    carro a;
    printf("\n Digite o chassi: ");
    scanf("%ld", &a.chassi);
    printf("\n Digite o ano: ");
    scanf("%d", &a.ano);
    printf("\n Digite o preco: ");
    scanf("%f", &a.preco);
    return a;
}

void preenche_vetor_carros(carro *vet, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++)
    {
        preenche_carro1(&vet[i]);
    }
}

void mostra_carro(carro a)
{
    printf("carro: ");
    printf("\n Chassi: %ld", a.chassi);
    printf("\n Ano   : %d", a.ano);
    printf("\n Preco : %f", a.preco);
    printf("\n");
}