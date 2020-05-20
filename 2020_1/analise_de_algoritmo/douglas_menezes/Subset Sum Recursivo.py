def isSubsetSum(conjunto, n, capacidade):

    if(capacidade == 0):
        return True
    if(n==0 and capacidade != 0):
        return False

    if(conjunto[n-1] > capacidade):
        return isSubsetSum(conjunto, n-1, capacidade)

    return isSubsetSum(conjunto, n-1, capacidade) or isSubsetSum(conjunto, n-1, capacidade-conjunto[n-1])


#Conjunto
conjunto = [2, 4, 7, 8, 9]

#Capacidade
capacidade = 16

n = len(conjunto)

if(isSubsetSum(conjunto, n, capacidade) == True):
    print('Ha um conjunto que é igual a capacidade!')

else:
    print('Não há conjunto que é igual a capacidade!')
