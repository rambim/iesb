
def funcao1(alunos,x):
    alunos["teste"] = [1,2,3]
    x = str("teste2")
    print(f'Id de alunos dentro da funcao = {hex(id(alunos))}')
    print(f'Id de x      dentro da funcao = {hex(id(x))}')


def main():
    teste = {}
    y = str("teste1")
    print(f'Id de teste antes da funcao = {hex(id(teste))}')
    print(f'Id de y      antes da funcao = {hex(id(y))}')
    funcao1(teste,y)
    print(f'Id de teste depois da funcao = {hex(id(teste))}')
    print(f'Id de y      depois da funcao = {hex(id(y))}')
    print(teste)
    print(y)
    

if __name__ == "__main__":
    main()

