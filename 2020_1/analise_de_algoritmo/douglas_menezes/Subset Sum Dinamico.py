def IsSubsetSumDinamico(conjunto, capacidade):
    colunas = capacidade + 1
    linha_anterior = [[]] * colunas
    linha_atual = [[]] * colunas
    linha_anterior[0] = [[]]
    linha_atual[0] = [[]]
    for valor in conjunto:
        for j in range(1, colunas):
            complemento = j - valor
            combinar = []
            if complemento >= 0:
                for c in linha_anterior[complemento]:
                    combinar.append(c + [valor])
                linha_atual[j] = linha_anterior[j] + combinar
            else:
                linha_atual[j] = linha_anterior[j]
        linha_anterior = linha_atual[:]

    return linha_atual[-1]

conjunto = [2, 4, 6, 7, 9, 11, 16]
capacidade = 20

if (IsSubsetSumDinamico(conjunto, capacidade)):
    print('Ha pelo menos um conjunto que é igual a capacidade!')
    print("CONJUNTOS" + ":" , IsSubsetSumDinamico(conjunto, capacidade))

else:
    print('Não há conjunto que é igual a capacidade!')