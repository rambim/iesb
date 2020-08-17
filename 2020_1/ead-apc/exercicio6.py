#3 e 4 ( 0.025)
# Escreva um programa para calcular o tempo que será reduzido da vida de um ser humano. Leia do usuário a quantidade
# cigarros fumados por dia e a quantidade de anos que usuário é fumante. Considere para o cálculo que o fumante
# perde 10 minutos de vida por cada por cigarro. Calcule quantos dias de vida ele perderá. Mostre o resultado em dias.

#ALEXANDRE CUNHA
#ISRAEL MORAES
#JOSÉ GIANNELLI
#JEFFERSON SANTOS
#Bruno


qtd_cigarros_dia = float(input("Digite a quantidade de cigarros por dia: "))
qtd_anos_fumante = float(input("Digite a quantos anos e fumante: "))
qtd_total_cigarros = qtd_cigarros_dia * 365 * qtd_anos_fumante
qtd_total_minutos_perdidos = 10 * qtd_total_cigarros
tempo_reduzido_em_dias = qtd_total_minutos_perdidos / 1440
print(tempo_reduzido_em_dias)
