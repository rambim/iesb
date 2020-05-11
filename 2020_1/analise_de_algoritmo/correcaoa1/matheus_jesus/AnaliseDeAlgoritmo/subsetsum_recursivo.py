

def sub_set_recursivo(vet, n, c):
    if (c == 0):
         return True
    if (n == 0 and c != 0):
         return False

    if (vet[n - 1] > c):
          return sub_set_recursivo(vet, n - 1, c)

    return sub_set_recursivo(vet, n - 1, c) or sub_set_recursivo(vet, n - 1, c - vet[n - 1])

vet = [10,15]
c = 50
n = len(vet)

if (sub_set_recursivo(vet, n, c) == True):
    print("Possui um subconjunto que sua soma da a Capacidade")
else:
    print("Não tem um subconjunto que sua soma de a Capacidade")
