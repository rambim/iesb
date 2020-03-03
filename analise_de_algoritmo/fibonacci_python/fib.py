from math import sqrt, pow

def f_explicit(n):
    sqrt5 = sqrt(5)
    return int((1/sqrt5) * (pow((1+sqrt5)/2, n) - pow((1-sqrt5)/2, n)))

def f_recursive(n):
    if n == 1:
        return 1
    elif n == 2:
        return 1
    else:
        return f_recursive(n-1) + f_recursive(n-2)

def f_iterative(n):
    last = 1
    lastbutone = 1

    if n == 1:
        return lastbutone
    elif n == 2:
        return last
    else:
        for _ in range(2, n):
            current = last + lastbutone
            lastbutone = last
            last = current
        return current
