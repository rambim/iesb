# =============================================================================
# - Rodrigo Touriño Machado de Oliveira Lima
# - 1722130070
# - Análise de Algoritmos
# - 2020-04-21
# - Soma dos subconjuntos: Programação Dinâmica
# =============================================================================


def subset_sum(set, n, sum): 
    table = [[False for i in range(sum + 1)] for i in range(n + 1)]

    for i in range(n + 1): 
        table[i][0] = True

    for i in range(1, sum + 1): 
         table[0][i] = False
              
    for i in range(1, n + 1):
        for j in range(1, sum + 1):
            if j < set[i - 1]:
                table[i][j] = table[i - 1][j]
            if j >= set[i - 1]:
                table[i][j] = (table[i - 1][j] or table[i - 1][j - set[i - 1]])

    if table[n][sum]:
        return get_subset_elements(set, table, n, sum)
    else:
        return None


def get_subset_elements(set, table, n, sum):
    subset = []
    i = n
    j = sum

    while True:
        if i == 0 or j == 0:
            break

        if table[i - 1][j] == True:
            i = i - 1
        else:
            subset.append(set[i - 1])
            j = j - set[i - 1]
            i = i - 1
        
    return subset


def print_subset(subset):
    print('Subconjunto:', end=' ')
    for element in subset:
        print(element, end=' ')
    print()

          
if __name__=='__main__': 
    set = [3, 34, 4, 12, 5, 2]
    sum = 9
    n = len(set)

    subset = subset_sum(set, n, sum)

    if subset:
        print_subset(subset)
    else:
        print("No subset with given sum")
