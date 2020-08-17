

def incluir_agenda(cpf,rg,nome):
    agenda[cpf] = [rg,nome]


agenda={}
print(type(agenda))
incluir_agenda(123,456,"Felippe")
print(agenda[123])
print(agenda[123][1])

import csv

f = open("teste.csv","w", newline='')
writer = csv.writer(f,quoting=csv.QUOTE_NONNUMERIC, delimiter=';')
writer.writerow(["teste", agenda[123][0], agenda[123][1] ])

