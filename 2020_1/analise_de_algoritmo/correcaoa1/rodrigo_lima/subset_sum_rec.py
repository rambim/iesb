# =============================================================================
# - Rodrigo Touriño Machado de Oliveira Lima
# - 1722130070
# - Análise de Algoritmos
# - 2020-04-21
# - Soma dos subconjuntos: Solução Recursiva
# =============================================================================

class SubsetSum:
    def __init__(self):
        self.subset_sum_exists = False


    def is_subset_sum(self, sum, arr, n, element_list):
        if self.subset_sum_exists:
            return

        if sum == 0:
            self.subset_sum_exists = True
            return
        
        if n == 0:
            return
        
        self.is_subset_sum(sum, arr, n - 1, element_list)

        list_copy = element_list.copy()
        list_copy.append(arr[n - 1])
        
        self.is_subset_sum(sum - arr[n - 1], arr, n - 1, list_copy)


    def caller(self):
        sum = 10
        arr = [1, 2, 3, 4, 5]
        element_list = []

        self.is_subset_sum(sum, arr, len(arr), element_list)

        if self.subset_sum_exists:
            print(f'Existe ao menos um subconjunto cuja soma dos valores de seus elementos é igual a {sum}')
        else:
            print(f'Não existe um subconjunto cuja soma dos valores de seus elementos é igual a {sum}')
 

if __name__ == '__main__':
    subset_sum = SubsetSum() 
    subset_sum.caller()