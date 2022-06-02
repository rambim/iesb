#include <stdio.h>

float teste(int c) {
	if (c % 2 == 0) {
		return 1;
	}
	return 0;
}

int main(void) {
	int a = 2, b = 0;
	float c;
	
	c = a + b;
	
	if (a == b || a == c) {
		printf("Teste 1 \n");
	} else {
		printf("Teste 2 \n");
	}
	
	while (a + 5 >= b) {
		c = teste(a + 1);
		a = a - c - 1;
		printf("%i %f \n", a, c);
	}

	return 0;
}