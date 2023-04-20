#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição do nó da Skip List
typedef struct Node {
    int key;
    int value;
    struct Node** forward;
} Node;

// Função para criar um novo nó
Node* newNode(int key, int value, int level) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->forward = (Node**)malloc((level + 1) * sizeof(Node*));
    return node;
}

// Função para gerar um número aleatório entre 0 e 1
int randomLevel() {
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < 15) {
        level++;
    }
    return level;
}

// Função para inserir um novo nó na Skip List
void insert(Node** list, int key, int value, int maxLevel) {
    Node* update[maxLevel + 1];
    Node* x = *list;
    for (int i = maxLevel; i >= 0; i--) {
        while (x->forward[i] != NULL && x->forward[i]->key < key) {
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];
    if (x == NULL || x->key != key) {
        int level = randomLevel();
        if (level > maxLevel) {
            for (int i = maxLevel + 1; i <= level; i++) {
                update[i] = *list;
            }
            maxLevel = level;
        }
        x = newNode(key, value, level);
        for (int i = 0; i <= level; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
}

// Função para imprimir a Skip List
void printSkipList(Node* list) {
    for (int i = 0; i <= 15; i++) {
        printf("Level %d: ", i);
        Node* x = list->forward[i];
        while (x != NULL) {
            printf("%d -> ", x->key);
            x = x->forward[i];
        }
        printf("NULL\n");
    }
}

int main() {
    // Abrir o arquivo CSV para leitura
    FILE* file = fopen("dados.csv", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo CSV\n");
        return 1;
    }

    // Criar a Skip List vazia
    Node* list = newNode(-1, -1, 0);
    int maxLevel = 0;

    // Ler o arquivo CSV e inserir os dados na Skip List
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int key, value;
        sscanf(line, "%d,%d", &key, &value);
        insert(&list, key, value, maxLevel);
    }

    // Fechar o arquivo CSV
    fclose(file);

    // Imprimir a Skip List
    printSkipList(list);

    // Liberar a memória alocada
    Node* x = list;
    Node* next;
    while (x != NULL) {
        next =
