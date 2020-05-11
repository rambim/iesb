import time

#- Backtracking.
# em vetor vet = [2,3,5,7,10,15]
# Se n = qtd do meu vetor vet, então o numero de combinações possiveis será
# 2^n = 2^6 = 64

class subset_sum_backtrack:
    subset_count = 0
    test = []
    list2 = []
    def __init__(self):
        list = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22]
        inicio = time.time()
        self.subset_sum(list, 0, 0, 10)
        self.list2 = list
        fim = time.time()
        print("Qtd conjuntos: ",self.subset_count)
        print("tempo: ",fim - inicio)

    def subset_sum(self,list, sum, starting_index, target_sum):
        #print("sum", sum, "start_i", starting_index, "target_sum", target_sum)

        if target_sum == sum:
            self.subset_count += 1


            if starting_index < len(list):
                self.subset_sum(list, sum - list[starting_index - 1], starting_index, target_sum)

        else:

            for i in range(starting_index,len(list)):
                self.subset_sum(list, sum + list[i], i + 1, target_sum)




p = subset_sum_backtrack()

