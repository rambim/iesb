#include <stdio.h>

void func1() {
   int x = 10;
}

void func2() {
   printf("O valor de x é: %d", x);
}

int main() {
   func1();
   func2();

   return 0;
}