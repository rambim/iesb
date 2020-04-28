#include <stdlib.h>
#include <stdio.h>

#include <math.h>
#include <locale.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	char expressao[50];
	int paren = 0;
	int i, j;

	printf("Informe a express�o matem�tica: ");
	scanf("%s", &expressao);
	j = strlen(expressao);

	for (i = 0; i < j; i++)
	{

		if (expressao[i] == '(')
		{
			paren++;
		}
		else if (expressao[i] == ')')
		{
			if (paren == 0)
			{
				printf("\nExpress�o incorreta!");
				return 0;
			}
			else
			{
				paren--;
			}
		}
	}

	if (paren == 0)
	{
		printf("\nExpress�o correta!");
	}
	else
	{
		printf("\nExpress�o incorreta!");
	}

	return 0;
}
