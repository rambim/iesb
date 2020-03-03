fibtests <- read.csv('fibonacci_benchmark.csv')

plot(
  x=fibtests$n_arg,
  y=fibtests$recursive_seconds,
  type='o',
  col='red',
  main='Benchmarking de algoritmos Fibonacci',
  xlab='Valor do argumento n da função',
  ylab='Segundos levados executar 10^6 de vezes',
  ylim=c(0, 10)
)

lines(
  x=fibtests$n_arg,
  y=fibtests$iterative_seconds,
  type='o',
  col='green'
)

lines(
  x=fibtests$n_arg,
  y=fibtests$explicit_seconds,
  type='o',
  col='blue'
)

legend(
  x=30,
  y=10,
  c('Recursivo', 'Iterativo', 'Fechado'),
  fill=c('red', 'green', 'blue')
)

