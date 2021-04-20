/*
Utilizando as seguintes estruturas, construa um programa que implemente as seguintes funções:
insert ou enqueue - insere itens numa ila (ao inal).
remove ou dequeue - retira itens de uma ila (primeiro item).
empty - veriica se a ila está vazia.
size - retorna o tamanho da ila.
front - retorna o próximo item da ila sem retirar o mesmo da ila
*/

typedef struct fila
{
    int tamanho;
    struct elemento * inicio;
    struct elemento * final;
}fila;

typedef struct elemento
{
    int valor;
    struct elemento * prox;
}elemento;

