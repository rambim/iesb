#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Aluno
struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

// Função para preencher os dados de um aluno passando a estrutura por referência
void preencherAlunoRef(struct Aluno *aluno, char *nome, int idade, 
                      float nota) {
    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    aluno->nota = nota;
}

// Função para imprimir os dados de um aluno passando a estrutura por referência
void imprimirAlunoRef(struct Aluno *aluno) {
    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);
    printf("Nota: %.2f\n", aluno->nota);
}

// Função para preencher os dados de um aluno passando a estrutura por valor
struct Aluno preencherAlunoVal(char *nome, int idade, float nota) {
    struct Aluno aluno;
    strcpy(aluno.nome, nome);
    aluno.idade = idade;
    aluno.nota = nota;
    return aluno;
}

// Função para imprimir os dados de um aluno passando a estrutura por valor
void imprimirAlunoVal(struct Aluno aluno) {
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("Nota: %.2f\n", aluno.nota);
}

int main() {
    // Alocando a estrutura estaticamente
    struct Aluno aluno1;
    preencherAlunoRef(&aluno1, "João", 20, 8.5);
    imprimirAlunoRef(&aluno1);

    // Alocando a estrutura dinamicamente usando malloc
    struct Aluno *aluno2;
    aluno2 = (struct Aluno *) malloc(sizeof(struct Aluno));
    preencherAlunoRef(aluno2, "Maria", 22, 9.0);
    imprimirAlunoRef(aluno2);

    // Liberando a memória alocada com malloc
    free(aluno2);

    // Preenchendo e imprimindo a estrutura por valor
    struct Aluno aluno3 = preencherAlunoVal("Pedro", 21, 7.0);
    imprimirAlunoVal(aluno3);

    return 0;
}
