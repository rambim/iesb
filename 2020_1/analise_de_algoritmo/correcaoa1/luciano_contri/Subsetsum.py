import time
import matplotlib.pyplot as plt
import numpy as np

def SubsetSumRecursivo(set, n, sum):
   #se a soma for 0, quer dizer que já foram subtraidos os valores do subset existente que juntos dão a soma
   if (sum == 0):
      return True
   if (n == 0 and sum != 0):
      return False
   if (set[n - 1] > sum):
      return SubsetSumRecursivo(set, n - 1, sum);
   return SubsetSumRecursivo(set, n - 1, sum) or SubsetSumRecursivo(set, n - 1, sum - set[n - 1])


def subsetsum(set,n,sum):

    #preenchendo matriz
    matriz = ([[False for i in range(sum + 1)]
               for i in range(n + 1)])
    #preenchendo caso de zero elementos e soma 0 na matriz
    for i in range(n+1):
        matriz[i][0]=True
        for i in range(1,sum+1):
            matriz[0][i]=False
    for i in range(1, n + 1):
         for j in range(1, sum + 1):
             #comparando se com menos numeros é possivel e se com o valor subtraido da soma também é possivel
            if j<set[i-1]:
                matriz[i][j] = matriz[i-1][j]
            if j>= set[i-1]:
                matriz[i][j] = (matriz[i-1][j] or   matriz[i - 1][j-set[i-1]])
        # printando o set
         if matriz[n][sum]:
            m=n
            b=sum
            S=[]
            #quando b for 0 quer dizer que ja passou voltando pelos itens que eram verdadeiros
            while b > 0:
                if matriz[m-1][b]:
                    m=m-1
                else:
                    m=m-1
                    S.append(set[m])
                    b=b-set[m]
            print(S)
    return matriz[n][sum]

# =============================================================================
# 
# def SubsetSumRecursivox(set, n, sum):
#    for i in range(0, 10):
# 
#       SubsetSumRecursivo(set, n, sum)
# 
# =============================================================================
def subsetsumx(set, n, sum):
   for i in range(0, 1):

      subsetsum(set, n, sum)

set=[1,2,3,4]
sum=100000

print("recursivo")
tempos=[]

for i in range(5,27):  
    
   n=len(set)
   tempo = time.time_ns()
   SubsetSumRecursivo(set, n, sum)
   set.append(i)
   tempo = time.time_ns() - tempo
   tempos.append(tempo)
   print(i,tempo)
   
a=len(set)-4

set = [1, 2, 3, 4]
print("dinamico")
tempos2=[]
 
for i in range(5,35):
    n=len(set)
    tempo = time.time_ns()
    subsetsum(set, n, sum)
    tempo = time.time_ns() - tempo
    set.append(i)
    tempos2.append(tempo)
    print(i,tempo)
    

x = np.linspace(0,30, 100)
y = 10e6*4*x
plt.figure()
plt.plot(x, y,label="O(x)")   
#plt.plot(x,y1,label="O(x²)")
plt.plot(range(len(set)-4),tempos2,label="Dinamico")
plt.title("Dinâmico")
plt.legend()
plt.show()


x = np.linspace(0,22, 100)
y = np.exp(x)
plt.figure()
plt.plot(x, y,label="O(e^n)")   
plt.plot(range(a),tempos,label="Recursivo")
plt.title("Recursivo")
plt.legend()
plt.show()


