/*

    1. Ler um valor do usuário e armazenar em X.
    2. Vou pegar a quantidade máxima de notas de 100 que cabe em X e armazenar em qtd_100.
    3. Subtrair o valor de 100 * qtd_100 de X e sobrescrever X.
    4. Voupegar a quantidade máxima de notas de 50 que cabe em X e armanzear em qtd_50.
    5. Subtrair o valor de 50 * qtd_50 de X e sobrescrever X.
    4. Voupegar a quantidade máxima de notas de 25 que cabe em X e armanzear em qtd_25.
    5. Subtrair o valor de 25 * qtd_25 de X e sobrescrever X.

    .
    .
    .
     Até a nota de 1.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x, valor_original;
    int qtd_100, qtd_50, qtd_20, qtd_10, qtd_5, qtd_2, qtd_1;

    do
    {
        scanf("%d", x);

        if (x<=0)
        {
            printf("Valor negativo, digite novamente: \n");
        }

    } while (x < 0);

    valor_original = x;
    qtd_100 = x / 100;
    x = x - qtd_100 * 100;
    qtd_50 = x / 50;
    x = x - qtd_50 * 50;
    qtd_20 = x / 20;
    x = x - qtd_20 * 20;
    qtd_10 = x / 10;
    x = x - qtd_10 * 10;
    qtd_5 = x / 5;
    x = x - qtd_5 * 5;
    qtd_2 = x / 2;
    x = x - qtd_2 * 2;

    printf("%d\n", valor_original);
    printf("%d nota(s) de R$ 100,00\n", qtd_100);
    printf("%d nota(s) de R$ 50,00\n", qtd_50);
    printf("%d nota(s) de R$ 20,00\n", qtd_20);
    printf("%d nota(s) de R$ 10,00\n", qtd_10);
    printf("%d nota(s) de R$ 5,00\n", qtd_5);
    printf("%d nota(s) de R$ 2,00\n", qtd_2);
    printf("%d nota(s) de R$ 1,00\n", x);

    return 0;
}