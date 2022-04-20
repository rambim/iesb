#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

static long long num_steps = 10000000000;
double step;

int main()
{
  int time = omp_get_wtime();

  int threads = 6;

  int i;
  double pi, sum = 0.0;
  double result[threads];

  step = 1.0 / (double)num_steps;

#pragma omp parallel num_threads(threads)
  {
    int num = omp_get_thread_num();
    double x, t_sum = 0.0;
    long long int j;
    for (j = num; j < num_steps; j += threads)
    {
      x = (j + 0.5) * step; 
      t_sum += 4.0 / (1.0 + x * x);
    }

    result[num] = t_sum;
  }

  for (i = 0; i < threads; i++)
    sum += result[i];

  pi = step * sum;

  printf("Pi: %lf sec: %lf\n", pi, omp_get_wtime() - time);

  return 0;
}