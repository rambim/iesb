// // sugestao de latitudes e longitudes
// -15.754748 -47.839425
// -15.751722 -47.841571
// -15.750132 -47.843480
// -15.747613 -47.846334
// -15.742392 -47.852393

#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>

#define INF INT_MAX

typedef struct locais LOCAIS;

struct locais
{
    char nome[50];
    double longitude;
    double latitude;
};

LOCAIS vetlocais[50];

int n_vertices;
double matriz_distancia[50][50];
int matriz_adjacencia[50][50];
int matriz_predecessor[50][50];
int origem, destino;

void funcao_encontrar_trajeto()
{
    int i, trajeto[50], contador;

    if (matriz_distancia[origem][destino] == INF)
    {
        printf("\nSem opcoes de trajeto \n");
        return;
    }
    contador = -1;
    do
    {
        trajeto[++contador] = destino;
        destino = matriz_predecessor[origem][destino];
    } while (destino != origem);

    trajeto[++contador] = origem;

    for (i = contador; i >= 0; i--)
        printf("%d ", trajeto[i]);
    printf("\n");
} /*End of findPath()*/

void funcao_ponto_inicial_e_final()
{
    int origem, destino;
    while (1)
    {
        printf("\nDigite um ponto de partida ou -1 para sair:\n");
        scanf("%d", &origem);
        if (origem == -1)
            break;
        printf("\nDigite o ponto de destino:\n");
        scanf("%d", &destino);
        if (origem < 0 || origem > n_vertices - 1 || destino < 0 || destino > n_vertices - 1)
        {
            printf("\nDigite pontos validos!\n\n");
            continue;
        }
        printf("\nO menor trajeto:");
        funcao_encontrar_trajeto();
        printf("\na distancia desse caminho: %.2f\n", matriz_distancia[origem][destino] / 1000);
    }
} /*End of main( )*/

void funcao_registrar_local()
{

    int indice;
    system("cls");

    printf("\n						|Registrando os Locais|\n\n");
    printf("1- Latitude e longitude:-22.9827  -43.2134   17-Latitude e longitude:-22.98314 -43.2049\n2- Latitude e longitude:-22.98378 -43.21348  18-Latitude e longitude:-22.98422 -43.20498\n3- Latitude e longitude:-22.98484 -43.21355  19-Latitude e longitude:-22.98532 -43.20504\n4- Latitude e longitude:-22.98591 -43.21361  20-Latitude e longitude:-22.98635 -43.20511\n5- Latitude e longitude:-22.9828  -43.21126  21-Latitude e longitude:-22.98326 -43.20279\n6- Latitude e longitude:-22.98387 -43.21134  22-Latitude e longitude:-22.98436 -43.20286\n8- Latitude e longitude:-22.98496 -43.21142  23-Latitude e longitude:-22.98541 -43.20292\n7- Latitude e longitude:-22.986   -43.21149  24-Latitude e longitude:-22.98646 -43.20299\n9- Latitude e longitude:-22.98294 -43.20915  25-Latitude e longitude:-22.98336 -43.20067\n10-Latitude e longitude:-22.984   -43.20921  26-Latitude e longitude:-22.98445 -43.20074\n11-Latitude e longitude:-22.98508 -43.20928  27-Latitude e longitude:-22.98552 -43.2008\n12-Latitude e longitude: 22.98614 -43.20931  28-Latitude e longitude:-22.98659 -43.20087\n13-Latitude e longitude:-22.98301 -43.20704  29-Latitude e longitude:-22.98346 -43.19855\n14-Latitude e longitude:-22.9841  -43.20712  30-Latitude e longitude:-22.98456 -43.19861\n15-Latitude e longitude:-22.98522 -43.20715  31-Latitude e longitude:-22.98568 -43.19869\n16-Latitude e longitude:-22.98624 -43.20723  32-Latitude e longitude:-22.98668 -43.19875\n");
	printf("\n	0_ _ _ _4_ _ _ _8_ _ _ _12_ _ _ _16_ _ _ _20_ _ _ _24_ _ _ _28\n");
	printf("\n	1	5	9 	13  	 17  	  21  	   25  	    29\n");
	printf("\n	2	6	10 	14  	 18  	  22  	   26  	    30\n");	
	printf("\n	3_ _ _ _7_ _ _ _11_ _ _ 15_ _ _ _19_ _ _ _23_ _ _ _27_ _ _ _31\n");
	printf("\n\nRegistre os locais, por exemplo:\n\nDigite o nome do local: Shopping\nDigite a latitude e longitude: -15.754748 -47.839425\n\nSiga com o cadastro abaixo...\n\n");

    for (indice = 0; indice < n_vertices; indice++)
    {
        fflush(stdin);

        printf("Digite o nome do ponto:\n", indice + 1);
        gets(vetlocais[indice].nome);

        printf("Digite a latitude e longitude:\n");
        scanf("%lf %lf", &vetlocais[indice].latitude, &vetlocais[indice].longitude);
    }
    printf("\nRegistrado! Pressione a tecla Enter para retornar ao menu \n");
}

void funcao_exibir_locais_registrados()
{
    int indice;
    for (indice = 0; indice < n_vertices; indice++)
    {
        printf("\nO ponto de nome: %s - com latitude: %lf e longitude: %lf - registrado\n", vetlocais[indice].nome, vetlocais[indice].latitude, vetlocais[indice].longitude);
    }
    printf("\nPressione a tecla Enter para retornar ao menu \n");
}

// vvoid funcao_registrar_adjacencia() //////////////////////////////////////////////////
// {
//     int a, b;

//     printf("\n");
//     printf("\nDigite 1 se ha adjacencia e 0 se NAO ha adjacencia\n");

//     for (a = 0; a < n_vertices; a++)
//         for (b = 0; b < n_vertices; b++)
//         {
//             printf("Digite se ha adjacancia [%s][%s]:\n", vetlocais[a].nome, vetlocais[b].nome);
//             scanf("%d", &matriz_adjacencia[a][b]);
//         }
//     printf("\nRegistrado! Pressione a tecla Enter para retornar ao menu \n");
// }

// void funcao_exibir_adjacencias_registradas() /////////////////////////////////////////////////////////////
// {
//     int i, j;
//     for (i = 0; i < n_vertices; i++)
//         printf("|%s|\t", vetlocais[i].nome);
//     printf("\n");

//     for (i = 0; i < n_vertices; i++)
//     {
//         for (j = 0; j < n_vertices; j++)
//         {
//             printf(" %d \t", matriz_adjacencia[i][j]);
//         }
//         printf("|%s \n", vetlocais[i].nome);
//     }
//     printf("\nPressione a tecla Enter para retornar ao menu \n");
// }

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

void funcao_entrada_floydwarshall()
{
    int i, j, k;
    long int infinito = INF;
    printf("\n");
    for (i = 0; i < n_vertices; i++)
    {
        for (j = 0; j < n_vertices; j++)
        {

            matriz_predecessor[i][j] = -1;
            matriz_predecessor[i][j] = i;
            matriz_distancia[i][j] = funcao_conversor_latitude_longitude(vetlocais[i].latitude, vetlocais[i].longitude, vetlocais[j].latitude, vetlocais[j].longitude);
        }
    }
}

// {
//     int i, j, k;
//     long int infinito = INF;
//     printf("\n");
//     for (i = 0; i < n_vertices; i++)
//     {
//         for (j = 0; j < n_vertices; j++)
//         {

//             if (matriz_adjacencia[i][j] == 0) /////////////////////////////////////////////////////////
//             {
//                 matriz_distancia[i][j] = INF;
//                 matriz_predecessor[i][j] = -1;
//             }
//             else
//             {
//                 ////////////////////////////////////////
//                 matriz_distancia[i][j] = matriz_adjacencia[i][j];
//                 matriz_predecessor[i][j] = i;
//                 matriz_distancia[i][j] = funcao_conversor_latitude_longitude(vetlocais[i].latitude, vetlocais[i].longitude, vetlocais[j].latitude, vetlocais[j].longitude);
//             }
//         }
//     }
// }

void funcao_floyd_warshall()
{

    int i, j, k;

    funcao_entrada_floydwarshall();

    for (k = 0; k < n_vertices; k++)
        for (i = 0; i < n_vertices; i++)
            for (j = 0; j < n_vertices; j++)
                if (matriz_distancia[i][k] + matriz_distancia[k][j] < matriz_distancia[i][j])
                {
                    matriz_distancia[i][j] = matriz_distancia[i][k] + matriz_distancia[k][j];
                    matriz_predecessor[i][j] = matriz_predecessor[k][j];
                }
}

void funcao_exibir_matriz_distancia_minima()
{
    int i, j, k;
    funcao_floyd_warshall();
    printf("A matriz de distancia minima entre os pontos (Floyd-Warshall):\n");
    printf("\n");
    for (i = 0; i < 5; i++)
        printf("|%s| \t\t", vetlocais[i].nome);
    printf("\n");

    for (i = 0; i < n_vertices; i++)
    {
        for (j = 0; j < n_vertices; j++)
            printf("%.2f kms\t", matriz_distancia[i][j] / 1000);
        printf("|%s \n", vetlocais[i].nome);
    }
    printf("\nPressione a tecla Enter para retornar ao menu \n");
}

void funcao_exibir_matriz_distancia_geral()
{
    int i, j, k;
    funcao_entrada_floydwarshall();
    printf("A matriz de distancia geral entre os pontos:\n");
    printf("\n");
    for (i = 0; i < 5; i++)
        printf("|%s| \t\t", vetlocais[i].nome);
    printf("\n");

    for (i = 0; i < n_vertices; i++)
    {
        for (j = 0; j < n_vertices; j++)
            printf("%.2f kms\t", matriz_distancia[i][j] / 1000);
        printf("|%s \n", vetlocais[i].nome);
    }
}

void funcao_registrar_quantidade_de_pontos()
{	
    printf("\nDigite a quantidade de pontos que serao cadastrados:\n ");
    scanf("%d", &n_vertices);
    if (n_vertices != 0)
    {
        printf("\nRegistrado! Pressione a tecla Enter para retornar ao menu...\n");
    }
    else
    {
        printf("\nPor favor indique um numero maior que 0!\nClique Enter para informar novamente...\n");
    }
}

void funcao_exibir_menu()
{
    int escolha_user;

    system("cls");
    printf("_______________________________________________________________________________________________________________________\n\n");
    printf("						Algoritmo de Melhor Rota\n");
    printf("_______________________________________________________________________________________________________________________\n\n");
    printf("						   |Menu Principal|\n");
    printf("Selecione uma das opcoes:\n");
    printf("\n1- Informar quantidade de pontos \n2- Registrar pontos\n3- Exibir pontos cadastrados\n");
    // printf("4- Registrar adjacencais\n5- Exibir adjacencais cadastrados\n"); //adicionar o case 8 aqui
    printf("6- Exibir matriz de distancia\n7- Ajuda\n0- Sair\n\n");
    scanf("%d", &escolha_user);
    switch (escolha_user)
    {
    case 1:
        system("cls");
        printf("\n						|Informando a Quantidade de Pontos|\n");
        funcao_registrar_quantidade_de_pontos(); //file
        getch();
        funcao_exibir_menu();
        break;
    case 2:
        funcao_registrar_local(); //file
        getch();
        funcao_exibir_menu();
        break;
    case 3:
        system("cls");
        printf("\n					|Exibindo os Locais Registrados|\n");
        funcao_exibir_locais_registrados(); //file
        getch();
        funcao_exibir_menu();
        break;
    // case 4:
    //     system("cls");
    //     printf("\n					|Registrando Adjac�ncias|\n");
    //     funcao_registrar_adjacencia();
    //     getch();
    //     funcao_exibir_menu();
    //     break;
    // case 5:
    //     //system("cls");
    //     //printf("\n						   |Registrando Adjac�ncias|\n");
    //     funcao_exibir_adjacencias_registradas();
    //     getch();
    //     funcao_exibir_menu();
    //     break;
    case 6:
        funcao_exibir_matriz_distancia_geral();  //file
        funcao_exibir_matriz_distancia_minima(); //file
        funcao_ponto_inicial_e_final();
        // funcao_encontrar_trajeto();
        getch();
        funcao_exibir_menu();
        break;
    case 7:
        system("cls");
        printf("\nPara ver os pontos acesse:\n\nhttps://www.google.com/maps/d/u/0/viewer?mid=1NtnaH2MTeDxL2JKV1B1ClpAxil_3vwz-&hl=pt-BR&ll=-22.98552632376205%2C-43.206983715459046&z=16\n\nDigite Enter para selecionar novamente...\n");
        getch();
        funcao_exibir_menu();
        break;
    /*case 8:
    //o secund�rio ser� um suporte para que voce nao tenha que fechar e abrir o programa para arrumar poss�veis erros de informa�ao/digita�ao
    //FALTA MUDAR AS OP��ES
    printf("						   |Menu Secund�rio|																			\n");
    printf("Selecione uma das opcoes:\n");
	printf("\n10- Informar quantidade de pontos \n20- Registrar pontos\n30- Exibir pontos cadastrados\n");
    printf("40- Registrar adjacencais\n50- Exibir adjacencais cadastrados\n");
    printf("60- Exibir matriz de distancia\n0- Sair\n\n");
    */
    case 0:
        printf("\nPrograma encerrado. Obrigado!\n");
        break;
    default:
        printf("\nIndique um comando valido!\nClique Enter para selecionar novamente...\n");
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
