/*




Escreva um programa que liste todas as diferentes palavras que existem em um texto. 
Neste caso, uma palavra é definida como uma sequência de letras, maiúsculas ou minúsculas. Palavras com 
apenas uma letra também deverão ser consideradas. Seu programa deverá ser case insensitive. 
Por exemplo, palavras como "Microsoft", "microsoft" ou "Microsoft" deverão ser consideradas como a mesma palavra.

Entrada
A entrada contém no máximo 10000 linhas de texto, 
cada uma delas com no máximo 200 caracteres. O fim de entrada é determinado pelo EOF.

Saída
Você deve imprimir uma lista das diferentes palavras que aparecem no texto, uma palavra por linha. 
Todas as palavras devem ser impressas com letras minúsculas, em ordem alfabética. Deverá haver no máximo 5000 palavras distintas.


Exemplo de entrada:
Ex(*$a#.mpl.e:
Adventures in Disneyland
Two blondes were going to Disneyland when they came to a fork in the road. The sign read: "Disneyland LEFT."
So they went home.

Exemplo de saída:
a
adventures
blondes
came
disneyland
e
ex
fork
going
home
in
left
mpl
read
road
sign
so
the
they
to
two
went
were
when

Funções que podem auxiliar:

#include <ctype.h>
int toupper(int c);
int tolower(int c);



Considerando a entrada de valores inteiros não negativos, ordene estes valores segundo o seguinte critério:

Primeiro os Pares utilizando o algoritmo Quicksort
Depois os Ímpares utilizando o algoritmo Mergesort
Sendo que deverão ser apresentados os pares em ordem crescente e depois os ímpares em ordem decrescente.

Entrada
A primeira linha de entrada contém um único inteiro positivo N (1 < N <= 105) Este é o número de linhas de entrada que vem logo a seguir. 
As próximas N linhas conterão, cada uma delas, um valor inteiro não negativo.

Saída
Apresente todos os valores lidos na entrada segundo a ordem apresentada acima. Cada número deve ser impresso em uma linha, conforme exemplo abaixo.



*/