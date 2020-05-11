class SubSet():
    def __init__(self, setNumbers, sumSubSet):
        self.__setNumbers = setNumbers[:]
        self.__sumSubSet = sumSubSet
        self.__setNumbers.sort()

    @property
    def existSubSet(self):
        return self.subSetRec(self.__sumSubSet) == True

    def subSetRec(self, sumSubSet, index = 0):
        if(sumSubSet == 0):
            return False

        if(len(self.__setNumbers) - index == 1):
            if(self.__setNumbers[0] == sumSubSet):
                return True
            return False

        return self.subSetRec(sumSubSet - self.__setNumbers[index] , index + 1) or self.subSetRec(sumSubSet ,index + 1)
    

if (__name__ == '__main__'):
    setA = [10,15,20,25]
    sumSubSetA = 50

    subset = SubSet(setA, sumSubSetA)
    print(subset.existSubSet == True and "Exists Subset")