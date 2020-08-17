#1) ( 0.025)
#Leia um número fornecido pelo usuário. 
#Caso o número seja positivo, calcule a raíz quadrada do número
#Caso o número seja negativo, mostre na tela a mensagem de que esse número é invalido.

#ALEXANDRE CUNHA
#ISRAEL MORAES
#JOSÉ GIANNELLI
#JEFFERSON SANTOS
#Bruno


n = int(input('Digite um numero: '))

if (n>0):
    raiz = n **(1/2)
    print(raiz)
else:
    print("Numero invalido")