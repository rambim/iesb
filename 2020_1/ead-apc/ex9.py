cpf = 123
nome = "Felippe"
dicionario = {"cpf": cpf}
dicionario["nome"] = nome
# dicionario = {"nome": nome}
print(type(dicionario))

print(dicionario)
print(dicionario["nome"])
del dicionario["nome"]
print(dicionario)


print(f'teste print {cpf}',cpf)

