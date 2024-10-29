#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>


int main()
{
    int dia1, dia2, hora1, hora2, minuto1, minuto2, segundo1,segundo2;
    int total1, total2, total3;
    int dia3, hora3, minuto3, segundo3;

    scanf("Dia %d",&dia1);
    scanf("%d : %d : %d",&hora1, &minuto1, &segundo1);
    scanf(" Dia %d",&dia2);
    scanf(" %d : %d : %d",&hora2, &minuto2, &segundo2);

    total1 = segundo1 + (minuto1 * 60) + (hora1 * 3600) + (dia1 * 3600 * 24);
    total2 = segundo2 + (minuto2 * 60) + (hora2 * 3600) + (dia2 * 3600 * 24);
    total3 = total2-total1;

    dia3 = total3 / (3600 * 24);
    total3 = total3 - (dia3 * 3600 * 24);
    hora3 = total3 / 3600;
    total3 = total3 - (hora3 * 3600);
    minuto3 = total3 / 60;
    total3 = total3 - (minuto3 * 60);
    segundo3 = total3;
    printf("%d dia(s)\n",dia3);
    printf("%d hora(s)\n",hora3);
    printf("%d minuto(s)\n",minuto3 );
    printf("%d segundo(s)\n",segundo3);

    return 0;



}