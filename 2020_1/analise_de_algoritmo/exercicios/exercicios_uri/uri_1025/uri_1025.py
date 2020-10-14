from bisect import bisect_left
def find(number,arr):
    index = (bisect_left(arr,number))

    if index < len(arr) and arr[index] == number:
       return index + 1
    else:
       return -1

seq = 1
while True:
    n, q = list(map(int,input().split()))
    if n == 0 and q == 0:
        break

    print("CASE# %d:" % seq)
    seq += 1
    lista = []
    for i in range(n+q):
        if i < n:
            lista.append(int(input()))

        if i == (n-1):
            lista.sort()

        if i >= n:
            pesq = int(input())
            index = find(pesq, lista)

            if index == -1:
                print(str(pesq) + " not found")
            else:
                print(str(pesq) + " found at " + str(index))