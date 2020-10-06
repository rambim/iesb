// sugestao de latitudes e longitudes
// -15.754748 -47.839425
// -15.751722 -47.841571
// -15.750132 -47.843480
// -15.747613 -47.846334
// -15.742392 -47.852393

#include <stdlib.h>
#include <stdio.h>

#include <locale.h>
#include <string.h>
#include <math.h>

typedef struct locais LOCAIS;
struct locais
{
    char nome[50];
    double longitude;
    double latitude;
};
LOCAIS vetlocais[5];

void funcao_registrar_local()
{

    int indice;
    system("cls");

    printf("Registre 5 locais em sequ�ncia, por exemplo:\n\nDigite o nome do local: Shopping\nDigite a latitude e longitude: -15.754748 -47.839425\n\nSiga com o cadastro abaixo...\n\n");

    for (indice = 0; indice < 5; indice++)
    {
        fflush(stdin);

        printf("Digite o nome do ponto:\n", indice + 1);
        gets(vetlocais[indice].nome);

        printf("Digite a latitude e longitude:\n");
        scanf("%lf %lf", &vetlocais[indice].latitude, &vetlocais[indice].longitude);
    }
    printf("\nPressione a tecla Enter para retornar ao menu \n");
}

void funcao_exibir_locais_registrados()
{
    int indice;
    for (indice = 0; indice < 5; indice++)
    {
        printf("\nO ponto de nome: %s - com latitude: %lf e longitude: %lf - registrado\n", vetlocais[indice].nome, vetlocais[indice].latitude, vetlocais[indice].longitude);
    }
    printf("\nPressione a tecla Enter para retornar ao menu \n");
}

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
    double d = raio_da_terra * c * 1000; // conversao para metros

    return d;
}

void funcao_execucao_floydwarshall()
{
    int i, j, k, n = 5;
    int dist[10][10];
    printf("\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            dist[i][j] = funcao_conversor_latitude_longitude(vetlocais[i].latitude, vetlocais[i].longitude, vetlocais[j].latitude, vetlocais[j].longitude);
        }
    ////////////////// funcao_floyd_warshall//////////////////////////////////
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("A matriz de dist�ncia entre os pontos:\n");
    printf("\n");

    for (i = 0; i < 5; i++)
        printf("|%s| \t\t", vetlocais[i].nome);
     printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d metros\t", dist[i][j]);
        printf("|%s \n", vetlocais[i].nome);
    }
    printf("\nPressione a tecla Enter para retornar ao menu \n");
}

void funcao_exibir_menu()
{
    int escolha_user;

    system("cls");
    printf("\nSelecione uma das opc�es:\n\n1- Registrar pontos\n2- Exibir pontos cadastrados\n3- Exibir matriz Floyd Warshall\n4- Sair\n\n");
    scanf("%d", &escolha_user);
    switch (escolha_user)
    {
    case 1:
        funcao_registrar_local();
        getch();
        funcao_exibir_menu();
        break;
    case 2:
        funcao_exibir_locais_registrados();
        getch();
        funcao_exibir_menu();
        break;
    case 3:
        funcao_execucao_floydwarshall();
        getch();
        funcao_exibir_menu();
        break;

    case 4:
        printf("\nFloydwarshall encerrado. Obrigado!");
        break;
    default:
        printf("\nIndique um comando v�lido!\nDigite Enter para selecionar novamente\n");
        getch();
        funcao_exibir_menu();
        break;
    }
}

int main()
{

    funcao_exibir_menu();

    return 0;
}
