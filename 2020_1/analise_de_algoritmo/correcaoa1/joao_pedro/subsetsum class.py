from time import time
import matplotlib.pyplot as plt

class SubsetSum():
    
    def __init__(self):
        self.contador = 0
        
    def __subset_sum_recursivo_aux(self, lista, starting_index, s):
        if s == 0:
            return True
        if len(lista) - starting_index == 1:
            if lista[starting_index] == s:
                return True
            else:
                return False
        
        result1 = self.__subset_sum_recursivo_aux(lista, starting_index + 1, s - lista[starting_index])
        result2 = self.__subset_sum_recursivo_aux(lista, starting_index + 1, s)
    
        return result1 or result2
    
    def subset_sum_recursivo(self, lista, s):
        if(len(lista) < 1):
            return False
        if len(lista) == 1:
            return True if lista[0] == sum else False
        
        return self.__subset_sum_recursivo_aux(lista, 0, s)
        
    def calcula_tempo_recursivo(self, iteracoes, soma):
        tempos = []
        
        for i in range(iteracoes):
            ini = time()
            lista = [j for j in range(i)]
            self.subset_sum_recursivo(lista, soma)
            fim = time()
            tempos += [fim - ini]
        return tempos
            
    def subset_sum_programming_dynamic(self, conjunto, soma):
        tamanho = len(conjunto)
        
        subset=[[False 
                 for i 
                 in range(soma+1)]  
                         for i 
                         in range(tamanho+1)]
                
                
        for i in range(tamanho + 1):
            subset[i][0] = True
            
            
        for i in range(1,soma+1): 
              subset[0][i]=False
             
        
        for i in range(1,tamanho+1): 
            for j in range(1,soma+1): 
                if j<conjunto[i-1]: 
                    subset[i][j] = subset[i-1][j] 
                if j>=conjunto[i-1]: 
                    subset[i][j] = (subset[i-1][j] or 
                                    subset[i - 1][j-conjunto[i-1]])
                    
        return subset[tamanho][soma] 
    
    def calcula_tempo_programmin_dynamic(self, iteracoes, soma = None):
        """
            Calcula o tempo com a passagens de tempo de acordo com as iterações passadas por parâmetro
        """
        
        tempos = []
        soma = soma or 1
        for i in range(iteracoes):
            ini = time()
            conjunto = [j for j in range(i)]
            
            if i % 5 == 0:
                soma += 1
            
            self.subset_sum_programming_dynamic(conjunto, soma)
            
            fim = time()
            tempos += [fim - ini]
            
        return tempos
            
    def subset_sum_backtracking(self, lista, soma, index, soma_procurada):
        if(soma_procurada == soma):
            self.contador += 1
            if index < len(lista):
                self.subset_sum_backtracking(lista, soma - lista[index-1], index, soma_procurada)
        else:
            for i in range(index, len(lista) ):
                self.subset_sum_backtracking(lista, soma + lista[i], i + 1, soma_procurada)
        
        return self.contador
        
    def calcula_tempo_backtracking(self, iteracoes):
        tempos = []
        for i in range(iteracoes):
            ini = time()
            lista = [j for j in range(1, i+1)]
            self.subset_sum_backtracking(lista, 0, 0, 10)
            fim = time()
            tempos += [fim - ini]
        
        return tempos
       


def exporta_grafico(tempo, nome_grafico):
    plt.plot(tempo)
    plt.legend(['tempo'])
    plt.title(nome_grafico)
    plt.savefig(nome_grafico)


if __name__ == '__main__':
    
    subset = SubsetSum()
    tempo_recursivo = subset.calcula_tempo_recursivo(20,10)
    tempo_dinamico = subset.calcula_tempo_programmin_dynamic(1000)
    tempo_back = subset.calcula_tempo_backtracking(23)

    exporta_grafico(tempo_recursivo, 'recursivo Θ(2^n).png')
    exporta_grafico(tempo_dinamico, 'dinamico O(N*S).png')
    exporta_grafico(tempo_back, 'backtracking Θ(2^n).png')
    
    oquadrado = [2 ** i for i in range(100)]
    n_soma = []
    soma = 1

    for i in range(1000):
        if i % 5 == 0:
            soma += 1
        n_soma += [i * soma]
    
    
    plt.plot(n_soma)
    plt.title('O(n*soma)')
    plt.savefig("O(n ^ soma).png")
    
    
    plt.plot(oquadrado)
    plt.title("O(2 ** n)")
    plt.savefig("O(2^n).png")

    


