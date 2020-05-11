"""
Alogoritmos subset sum
"""

import time
import sys
import numpy as np
import os
import pandas as pd
import matplotlib.pyplot as plt

"""dinâmica"""
def dinamico(lista, TAM, soma):

    # criacao da matriz com numpy
    matriz = np.zeros((TAM + 1, soma + 1), dtype=int)

    # preenchendo matriz
    for i in range(1, TAM + 1):
        for j in range(1, soma + 1):

            # verifico se o peso que eu tenho cabe na mochila
            if lista[i-1] <= j:
               matriz[i][j] = matriz[i-1][j - lista[i-1]] + \
                   (i)  # valor do item
            else:
                matriz[i][j] = matriz[i-1][j]

    # pegando o conjunto
    conjunto = []
    soma_aux = soma
    while True:
        if TAM == -1:
            break;

        valor = matriz[TAM][soma]

        if valor == matriz[TAM - 1][soma]:
            TAM = TAM - 1
        else:
            TAM = TAM - 1
            conjunto.append(lista[TAM])
            soma = soma - lista[TAM]

    if np.sum(conjunto) == soma_aux:
        print("CONJUNTO ACHADO: ", conjunto)
        return True
    else:
        return False


"""recursiva"""
def recursivo(lista, TAM, soma):

    # se a soma é zero
    if(soma == 0):
        return True

    # se o tamanho for zero , lista vazia
    if(TAM == 0 and soma != 0):
        return False

    if(lista[TAM - 1] > soma):
        return recursivo(lista, TAM - 1, soma)

    return recursivo(lista, TAM-1, soma) or recursivo(lista, TAM-1, soma-lista[TAM - 1])


"""backtracking"""
contador = 0
conjuntos = []
vet = []

def backtracking(lista, soma, index, peso):

    global contador
    global conjuntos
    global vet

    if soma == peso:
        contador += 1
        if index < len(lista):
            backtracking(lista, soma - lista[index], index + 1, peso)
    else:             
        for i in range(index, len(lista)):   
            backtracking(lista, soma + lista[i], i + 1, peso) 
            
    
def executar():
    """EXECUCAO"""
    arq = open('./conjuntos.txt')
    numeros = arq.read()
    lista = list(map(int, numeros.split(","))) # colocar aqui o vetor
    lista.sort()
    soma = int(input("Digite a soma..\n")) # passar na linha de comando qual o peso
    soma_back = soma
    TAM = len(lista)

    print("\nLISTA: ", lista, "SOMA: " , soma)
    print("---------IMPLEMENTACAO DINAMICA------")
    if dinamico(lista, TAM, soma):
        print("Existe um subconjunto DINAMICO")
    else:
        print("nao existe um subconjunto!!")

    print("\n----------RECURSIVO----------------")
    if recursivo(lista, TAM, soma) : 
        print("Existe um subconjunto")
    else:
        print("nao existe um subconjunto!!")

    print("\n----------backtracking----------------")
    backtracking(lista, 0, 0, soma_back)
    print("QUANTIDADE DE CONJUNTOS: ", contador)


def gerar_csv():
    
    max_execucao = 12
    soma = 6
    tam_array = 5
    tam_array_iteracao = []
    
    tempos_recursivo = []
    tempos_dinamico = []
    tempos_back = []
    
    #dinamico
    for i in range(1,max_execucao):
        
        print("iteracao: ", i)
        
        vetor = np.linspace(0, tam_array, tam_array, dtype=int)
        
        print("DINAMICO")   
        temp_ini = time.time()
        dinamico(vetor, tam_array, soma)
        temp_fim = time.time()
        tempos_dinamico.append(temp_fim - temp_ini)
        
        print("RECURSIVO")
        temp_ini = time.time()
        recursivo(vetor, tam_array, soma)
        temp_fim = time.time()
        tempos_recursivo.append(temp_fim - temp_ini)
        
        
        print("backtracking")
        temp_ini = time.time()
        backtracking(vetor, 0,0, soma)
        temp_fim = time.time()
        tempos_back.append(temp_fim - temp_ini)
    
        tam_array_iteracao.append(tam_array)
        
        tam_array = tam_array + 2
        
    dinamico_data = {'metodo': 'dinamico','tempo': tempos_dinamico, 'tamanho_array': tam_array_iteracao }    
    df_dinamico = pd.DataFrame(dinamico_data, columns=['metodo','tempo', 'tamanho_array']) 
    
    recursivo_Data = {'metodo': 'recursivo','tempo': tempos_recursivo, 'tamanho_array': tam_array_iteracao } 
    df_recursivo = pd.DataFrame(recursivo_Data, columns=['metodo','tempo', 'tamanho_array']) 
    
    back_Data = {'metodo': 'backtracking','tempo': tempos_back, 'tamanho_array': tam_array_iteracao } 
    df_back = pd.DataFrame(back_Data, columns=['metodo','tempo', 'tamanho_array']) 
    
    frames = [df_back, df_dinamico, df_recursivo ]
    result = pd.concat(frames)
    
    result.to_csv('subsetsum_tempos.csv', index=False, sep=';')    

def gerar_grafico():
    dataframe = pd.read_csv('subsetsum_tempos.csv', sep=';')
    df = pd.DataFrame(dataframe, columns=['metodo','tempo', 'tamanho_array'])
    
    ax = plt.gca()
    
    df.plot(kind='line', x='tamanho_array', y='tempo', ax=ax, stacked=True)
    plt.title('TAMANHO X EXECUCAO')
    plt.ylabel('Tempo')
    plt.ylabel('Tam. Array')
   
    plt.savefig('output.png')
    

if __name__ == "__main__":
    print("1 - GERAR CSV")
    print("2 - GERAR GRAFICO")
    print("3 - LER UM CONJUNTO DO ARQUIVO, E PROCURAR PESO INFORMADO")
    opcao = int(input("Digite sua opcao....\n"))
    
    if opcao == 1:
        gerar_csv()
    elif opcao == 2:
        gerar_grafico()
    else:
        executar()    
    
    print("\n")