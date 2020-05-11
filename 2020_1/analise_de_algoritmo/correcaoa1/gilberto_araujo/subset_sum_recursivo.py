"""
Subset sum recursivo
Retorna TRUE ou FALSE, dependendo se existe ou não um subset
"""
def subset_sum_recursivo(lista, n, capacidade):

    if (capacidade == 0):
        return True
    if (n == 0 and capacidade != 0):
        return False

    if (lista[n - 1] > capacidade):
        return subset_sum_recursivo(lista, n - 1, capacidade)

    return subset_sum_recursivo(lista,
                      n - 1,
                      capacidade) or subset_sum_recursivo(lista,
                                                n - 1,
                                                capacidade - lista[n - 1])


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

    capacidade = int(
        input(
            '\t{capacidade}'.format(
                capacidade=red('capacidade '))))  # Entrada da capacidade

    # Pré otimização: Eu já recebo a lista de forma ordenada
    lista = sorted(
        list(map(int, input('\t{lista}'.format(lista=red('lista '))).split(" "))))

    # Pré otimização: Com a lista ordenada, eu crio uma nova lista sem os
    # itens maiores que a capacidade, assim a recurção não precisa
    # iterar itens que obviamente não fazer parte da solução
    if lista[len(lista) - 1] > capacidade:
        lista = lista[0:next(i for i, x in enumerate(lista) if x > capacidade)]

    # Agora sim, eu chamo minha função
    n = len(lista)
    if (subset_sum_recursivo(lista, n, capacidade)):
        print("Existe um subconjunto igual a capacidade informada")
    else:
        print("Não existe um subconjunto igual a capacidade informada")


if __name__ == "__main__":
    main()
