/*

Utilizando a estrutura do OpenMPI faça:

a) no processo 0 leia um número n inteiro positivo do usuário e atribua a uma variável de nome multiplicador.
b) No processo 0 aloque um vetor com tamanho igual a quantidade de processos e preencha-os com valores aleatórios.
c) Faça com que todos processos enxerguem o valor do multiplicador recebido no processo 0.
d) Distribua os valores do vetor preenchido no processo 0 entre os diversos processos.
e) Em cada processo calcule o produto do multiplicador pelo valor recebido do vetor.
f) Agrupe os produtos de cada processo em um vetor no processo 0.
g) Calcule o somatório do vetor resultante agrupado.

*/