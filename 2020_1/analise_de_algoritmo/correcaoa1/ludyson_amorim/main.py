''' Prova 1º Bimestre - Analise de Algoritmos
Alunos: Ludyson Jose Alves do Amorim 1512082067
				Pedro Izaque Silva Reis 1512082096 '''

# Testando a função 
conjunto = [5, 4, 10, 8, 9, 6] 
soma = 19
tamanho = len(conjunto) 

# Solução recursiva do Subset Sum
def SubsetSumRec(conjunto, tamanho, soma) : 
    if (soma == 0) : 
        return True
  
    if (tamanho == 0 and soma != 0) : 
        return False
   
    if (conjunto[tamanho - 1] > soma) : 
        return SubsetSumRec(conjunto, tamanho - 1, soma); 
   
    return SubsetSumRec(conjunto, tamanho-1, soma) or SubsetSumRec(conjunto, tamanho-1, soma-conjunto[tamanho-1]) 

'''
T(n) = 2 + T(n-1) + T(n-1) 
T(n) = 2T(n-1) + 2 
T(n-1) = 2 + 2T(n-2) 
T(n-2) = 2 + 2T(n-3) 

Ampliar: 

T(n) = T(n) = 2 + 2(2 + 2T(n-2)) = 2 + 2² + 2² T(n-2) 
T(n) = T(n) = 2 + 2² + 2² (2 + 2T(n-3)) = 2 + 2² + 2³ + 2³ T(n-3)² + 2² (2 + 2T(n-3)) = 2 + 2² + 2³ + 2³ T(n-3) 
T(n) = 2 + 2² + ... + 2^(k-2) + 2^(k-1) + 2^k + (2^n) * T(n-k)2² + ... + 2^(k-2) + 2^(k-1) + 2^k + (2^n) * T(n-k) 

T (0) = 0 

t(n) se n>=1   
n = k, porque n-k=0, porque n-k=0 

S = 2+2² + 2³ + 2^4 + 2^5+...+ 2^n 
2S = 2² + 2³ + 2^4 + 2^5+ 2^6 +... +2^(n+1) ² + 2³ + 2^4 + 2^5+2^6+... +2^(n+1) 
-S S = 2 + 2² + 2³ + 2^4 + 2^5+...+2^n
-2+2^(n+1)

Como 2^k-2

T(n) = 2^n *constante + 2^k-2
T(n) = 2^n + 2^n-2
T(n) = 2^(n+1)-2
Complexidade igual = O(2^n) 
'''

# Solução dinamica do Subset Sum
def SubsetSumDn(conjunto,tamanho,soma):       # Total da contagem = 8*kn + 12*n + 14*k + 28 =~ O(n²)
      
    subset=([[False for i in range(soma+1)]   # 2 + (n+1)*(2 + 2*(k+1)) = 2*kn + 4*n + 2*k + 6
        for i in range(tamanho+1)]) 

    for i in range(tamanho+1):                # 2 + 2*(k+1)             = 2*k + 4
        subset[i][0] = True
            
    for i in range(1,soma+1):                 # 2 + 2*(n+1)             = 2*n + 4
        subset[0][i] = False
               
    for i in range(1,tamanho+1):              # 2 + (k+1)*(2 + 5*(n+1)) = 5*kn + 5*n + 7*k + 9
        for j in range(1,soma+1): 
            if j<conjunto[i-1]: 
                subset[i][j] = subset[i-1][j] 
            if j>=conjunto[i-1]: 
                subset[i][j] = (subset[i-1][j] or subset[i - 1][j-conjunto[i-1]]) 
      
    for i in range(tamanho+1):                # 2 + (k+1)*(2 + (n+1))   = kn + n + 3*k + 5
        for j in range(soma+1): 
            print (subset[i][j],end=" ") 
        print() 
    
    return subset[tamanho][soma] 

# Solução backtracking do Subset Sum
def SubsetSumBt(conjunto, soma, aux):
    if len(conjunto) == 0:
        return None
    else:
        if conjunto[0] == soma:
            return [conjunto[0]]
        else:
            v = SubsetSumBt(conjunto[1:], (soma - conjunto[0]), aux=conjunto[0])
            if v:
                if aux == 0:
                    print([conjunto[0]] + v)
                else:
                    print([aux] + [conjunto[0]] + v)
            else:
                return SubsetSumBt(conjunto[1:], soma, aux)

'''
T(n) = 2 + T(n-1) + T(n-1) 
T(n) = 2T(n-1) + 2 
T(n-1) = 2 + 2T(n-2) 
T(n-2) = 2 + 2T(n-3) 

Ampliar: 

T(n) = T(n) = 2 + 2(2 + 2T(n-2)) = 2 + 2² + 2² T(n-2) 
T(n) = T(n) = 2 + 2² + 2² (2 + 2T(n-3)) = 2 + 2² + 2³ + 2³ T(n-3)² + 2² (2 + 2T(n-3)) = 2 + 2² + 2³ + 2³ T(n-3) 
T(n) = 2 + 2² + ... + 2^(k-2) + 2^(k-1) + 2^k + (2^n) * T(n-k)2² + ... + 2^(k-2) + 2^(k-1) + 2^k + (2^n) * T(n-k) 

T (0) = 0 

t(n) se n>=1   
n = k, porque n-k=0, porque n-k=0 

S = 2+2² + 2³ + 2^4 + 2^5+...+ 2^n 
2S = 2² + 2³ + 2^4 + 2^5+ 2^6 +... +2^(n+1) ² + 2³ + 2^4 + 2^5+2^6+... +2^(n+1) 
-S S = 2 + 2² + 2³ + 2^4 + 2^5+...+2^n
-2+2^(n+1)

Como 2^k-2

T(n) = 2^n *constante + 2^k-2
T(n) = 2^n + 2^n-2
T(n) = 2^(n+1)-2
Complexidade igual = O(2^n)
'''

menu = "0"
while menu=="0":
    print()
    print(conjunto)
    print()
    print(soma)
    print ("""
    1.Subset Sum em Recursividade
    2.Subset Sum na forma Dinamica
    3.Subset Sum em Backtracking
    """)
    menu = input("Escolha uma opção? ")

    if menu == "1":
        if (SubsetSumRec(conjunto, tamanho, soma) == True) : 
            print("Subconjunto Encontrado!") 
        else : 
            print("Nenhum subconjunto encontrado!")
    elif menu == "2":
        if (SubsetSumDn(conjunto, tamanho, soma) == True): 
            print("Subconjunto Encontrado!") 
        else: 
            print("Nenhum subconjunto encontrado!") 
    elif menu == "3":
        SubsetSumBt(conjunto, soma, 0)
    elif menu != "":
        menu="0"
        print("\n Opção Invalida. Tente Novamente")