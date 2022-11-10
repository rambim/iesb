#include <stdio.h>
#include <stdlib.h>

int valida_nota(double nota);
int main()
{
    double n, media;
    double n1 = 0, n2 = 0;
    int status = 0;
    int opcao = 0;
    int continuar = 1;

    while (continuar)
    {
        scanf("%lf", &n);
        if (valida_nota(n))
        {
            if (status == 0)
            {
                n1 = n;

                status = 1;
            }
            else
            {
                if (status == 1)
                {
                    n2 = n;
                    status = 0;
                    media = (n1 + n2) / 2.0;
                    printf("media = %.2lf\n", media);
                    do
                    {
                        printf("novo calculo (1-sim 2-nao)\n");
                        scanf("%d", &opcao);

                        switch (opcao)
                        {
                        case 1:
                            continuar = 1;
                            status=0;
                            break;
                        case 2:
                            continuar = 0;
                            break;
                        }
                    } while (opcao != 1 && opcao != 2);
                }

            }
        }
        else
        {
            printf("nota invalida\n");
        }
    }
}

// retorna 1 se a nota for valida
// retorna 0 se a nota nao for valida
int valida_nota(double nota)
{
    if (nota < 0 || nota > 10)
        return 0;
    else
        return 1;
}