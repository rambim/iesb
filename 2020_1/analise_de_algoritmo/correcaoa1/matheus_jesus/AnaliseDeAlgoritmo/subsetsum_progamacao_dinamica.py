import time

def montaMatriz(vet,c):


    mat = [[0 for col in range(c+1)] for lin in range(len(vet))]
    for indicelin, linha in enumerate(mat):
        for indicecol, coluna in enumerate(linha):
            #preenche a 1ª coluna com vdd
            linha[0]=1
            #linha inicial tem conceito diferente
            if indicelin==0:
                if indicecol==vet[indicelin]:
                   mat[indicelin][indicecol]=1
            #a partir da segunda linha:
            else:
                if indicecol < vet[indicelin]:
                    mat[indicelin][indicecol]=mat[indicelin-1][indicecol]
                else:
                    #se o de cima for verdadeiro o termo recebe verdadeiro
                    if mat[indicelin-1][indicecol] == 1:
                        mat[indicelin][indicecol] = 1
                    else:
                        #se o de cima for falso sobe um e volta a qtd de termos representante da linha
                        mat[indicelin][indicecol] = mat[indicelin-1][indicecol - vet[indicelin]]

    for i in mat:
        print(i, "\n")
    return mat

def achaCombinacao(mat,v,c):
    aux=0
    for linha,i in enumerate(mat):
        for coluna, j in enumerate(i):
            if mat[linha][coluna]==1:
                aux=1
            else:
                aux=0

    if aux==1:
        print("Há subconjunto")
    else:
        print('Não há subconjunto')
inicio2 = time.time()
v=[2,3,5,7,10,15]
c=17
mat = montaMatriz(v,c)
achaCombinacao(mat,v,c)
fim2 = time.time()
print("Tempo dinamico:", fim2-inicio2)
