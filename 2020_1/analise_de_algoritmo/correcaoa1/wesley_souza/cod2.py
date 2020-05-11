
class SubSet():
    def __init__(self, setNumbers, sumSubSet):
        self.__setNumbers = setNumbers[:]
        self.__matrix = [[False for i in range(sumSubSet + 1)] for j in range(len(setNumbers) + 1)]
        self.__sumSubSet = sumSubSet
        self.__setNumbers.sort()

    @property
    def existSubSet(self):
        self.startSubSet()
        return self.__matrix[-1][-1] == True

    def startSubSet(self):
        for i, value in enumerate(self.__setNumbers):
            self.__matrix[0][i] = False
            self.__matrix[i][0] = True
            for j in range(1, len(self.__matrix[i])):
                if(i > 0):
                    if(j >= value and self.__matrix[i-1][j] == False):
                        self.__matrix[i][j] = self.__matrix[i - 1][j] or self.__matrix[i - 1][j - value]
                    else:
                        self.__matrix[i][j] = self.__matrix[i-1][j]
                elif(self.__setNumbers[i] == j):
                    self.__matrix[i][j] = True

    def printSubset(self):
        self.printMatrix()
        subset = []
        for i in range(len(self.__setNumbers) - 1, -1 ,-1):
            if(sum(subset) < self.__sumSubSet):
                for j in range(len(self.__matrix[0]) - 1, -1, -1):
                    print(j)
                    if(self.__matrix[i][j] == True):
                        if((self.__matrix[i-1][j] is False) and (self.__matrix[i - 1][j - self.__setNumbers[i]] == True)):
                            subset.append(self.__setNumbers[i])
                        break

        print(subset)     

    def printMatrix(self):
        for line in self.__matrix:
            print(line)
        print('\n')



if (__name__ == '__main__'):
    setA = [10,15,20,25]
    sumSubSetA = 50

    subset = SubSet(setA, sumSubSetA)
    print(subset.existSubSet == True and "Exists Subset")
    subset.printSubset()