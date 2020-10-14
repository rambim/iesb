#2) ( 0.025)
# Escreva um programa que leia do usuário a quantidade de dias, horas, minutos e segundos.
# Calcule e mostre na tela o valor total em segundos do tempo recebido.

#ALEXANDRE CUNHA
#ISRAEL MORAES
#JOSÉ GIANNELLI
#JEFFERSON SANTOS
#Bruno

qtd_dias     = int(input("Digite a quantidade de dias: "))
qtd_horas    = int(input("Digite a quantidade de horas: "))
qtd_minutos  = int(input("Digite a quantidade de minutos: "))
qtd_segundos = int(input("Digite a quantidade de segundos: "))

total_segundos = (1* qtd_segundos) + (qtd_minutos * 60) + (qtd_horas * 3600) + (qtd_dias * 86400)

print(total_segundos)



