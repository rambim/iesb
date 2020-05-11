"""
Solução dinamica do subset sum
"""

def subset_sum_dinamico(lista, capacidade):
    def subset_sum(lista, capacidade, storage=()):
        for _ in lista:
            if not lista:
                return False
            if lista[0] == capacidade:
                return list(storage + (lista[0],))
            storage = storage + (lista[0],)
            capacidade = capacidade - lista[0]
            lista = lista[1:]
    while True:
        result = subset_sum(lista, capacidade)
        if result == False or result == None:
            lista = lista[1:]
        else:
            return result
##########################################################################
##########################################################################

def red(str):
    return '\033[91m' + str + '\033[0m'


def main():
    print(
        """
        Gilberto Charles Silveira Araújo - 1512130109
        Erika Bianca Csan - 1612082057

        Entre com a {capacidade}, enter, e em seguida, a {lista}, com itens separados por espaços:
        """
        .format(
            capacidade=red('capacidade'),
            lista=red('lista')))

    capacidade = int(input('\t{capacidade}'.format(capacidade=red('capacidade '))))  # Entrada da capacidade

    # Pré otimização: Eu já recebo a lista de forma ordenada
    lista = sorted(
        list(map(int, input('\t{lista}'.format(lista=red('lista '))).split(" "))))

    # Pré otimização: Com a lista ordenada, eu crio uma nova lista sem os
    # itens maiores que a capacidade
    if lista[len(lista) - 1] > capacidade:
        lista = lista[0:next(i for i, x in enumerate(lista) if x > capacidade)]

    # Agora sim, eu chamo minha função
    subconjunto = subset_sum_dinamico(lista, capacidade)
    print(
        """
        {resposta} {subconjunto}
        """.format(
            resposta=red(
                'Subconjunto encontrado:'),
            subconjunto=subconjunto
        ))

if __name__ == "__main__":
    main()