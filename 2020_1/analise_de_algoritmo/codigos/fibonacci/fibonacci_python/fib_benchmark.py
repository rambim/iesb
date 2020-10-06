import csv
from timeit import timeit

with open('fibonacci_benchmark.csv', 'w') as reportfile:
    writer = csv.writer(reportfile)
    writer.writerow([
        'n_arg',
        'recursive_seconds',
        'iterative_seconds',
        'explicit_seconds'
    ])
    for n in range(1, 3):
        print('n={}...'.format(n), end='')
        if n < 15:
            rec = timeit('fib.f_recursive({})'.format(n), setup='import fib')
        else:
            rec = 'NA'
            print(' ~recur~', end='')
        it = timeit('fib.f_iterative({})'.format(n), setup='import fib')
        exp = timeit('fib.f_explicit({})'.format(n), setup='import fib')
        print(' OK')
        writer.writerow([n, rec, it, exp])
