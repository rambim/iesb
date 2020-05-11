def subsetsum(conjunto, capacidade, parcial=[]):
    soma = sum(parcial)


    if soma == capacidade:
        encontrou = True
        print(encontrou)
        return True

    if soma >= capacidade:
        return

    for i in range(len(conjunto)):
        k = conjunto[i]
        remaining = conjunto[i+1:]
        found = subsetsum(remaining, capacidade, parcial + [k])
        if found:
            return True



if __name__ == "__main__":
    A = [1, 2, 3]
    capacidade = 10
    if subsetsum(A,capacidade):
     print()
    else:
     print(False)


