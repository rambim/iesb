agenda = {}



print(type(agenda))

agenda["Felippe"] = ["casado","masculino","futebol"]
agenda["Jefferson"] = ["solteiro","masculino","Submission"]
agenda["Jose"] = ["logica","materiais"]

print(f'Anter de deletar: {agenda}')
if (agenda.get("Jeferson")):
    del agenda["Jeferson"]
else:
    print("Contato nao localizado")







