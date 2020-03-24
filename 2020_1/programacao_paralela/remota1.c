/*

barrier
mutual exclusion ( critical e atomic).
ex13
ex14


#pragma omp for

Diferença entre sequencial, laço dentro de um parallel, laço usando um parallel FOR
ex15
ex16
ex17

Construtor omp parallel junto com for
ex18
ex19

Trabalhando com Loops.

Estratégia:
1) Encontrar loops intensivos.
2) Fazer com que cada iteração do loop seja independente para que eles possam ser executados separadamente.
3) Paralelize

exercicio1.c
sol_exercicio1.c

collapse for dentro de for
ex20.c
é ótimo quando o laço externo da ordem da quantidade de threads.



schedule(static [,chunk])
 Distribuir blocos de iterações de tamanho 
"chunk" para cada thread.
Pré-determinado e previsível pelo programador.
Menos trabalho em tempo de execução: 
agendamento feito em tempo de compilação


schedule(dynamic[,chunk])
 Cada thread captura iterações de "pedaços" 
 de uma fila até que todas as 
 iterações tenham sido manipuladas.
 Trabalho imprevisível e altamente variável por iteração
 A maioria dos trabalhos em tempo de execução:
  lógica de planejamento complexa usada 
  em tempo  de execução


schedule(guided[,chunk])
Threads capturam dinamicamente blocos de iterações. 
O tamanho do bloco começa grande e diminui 
para o tamanho "pedaço" à medida que o 
cálculo prossegue
Caso especial de dinâmica para reduzir a sobrecarga de agendamento

schedule(runtime)
Tamanho da agenda e do fragmento extraídos 
da variável de ambiente OMP_SCHEDULE 
(ou da biblioteca de tempo de execução)

schedule(auto)
A programação é deixada até o tempo de 
execução para escolher 
(não precisa ser nenhuma das opções acima)
Quando o tempo de execução pode "aprender" de execuções
 anteriores do mesmo loop








*/