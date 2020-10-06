def recebe_dados_aluno(matricula,nome,disciplina,media):
    alunos[matricula] = [nome,disciplina,media]

def calcula_media(nota1,nota2):
    resultado  =  float((nota1+nota2)/2)
    return resultado

# criando dicionario;
alunos = {}

for _ in range(3):

    # lendo os dados do usuario
    matricula_usuario = int(input("Digite sua matricula: "))
    nome_usuario = str(input("Digite seu nome: "))
    disciplina_usuario = str(input("Digite sua disciplina: "))
    n1 = float(input("Digite a primeira nota: "))
    n2 = float(input("Digite a segunda nota: "))

    # calculando a media atraves da funcao calcula_media
    media_usuario = calcula_media(n1,n2)


    # cadastrando o aluno atraves da funcao recebe_dados_aluno
    recebe_dados_aluno(matricula_usuario,nome_usuario,disciplina_usuario,media_usuario)

print(alunos)


# f = open("teste.csv","w")
# for chave in alunos:
#     f.write(f'{alunos[chave][0]};{alunos[chave][1]};{alunos[chave][2]}\n')

# f.close()

import csv
f = open("teste.csv","w")
arquivo = csv.writer(f,quoting=csv.QUOTE_NONNUMERIC,delimiter=';')
for chave in alunos:
    arquivo.writerow(alunos[chave])




# if __name__ == "__main__":
#     # main()




