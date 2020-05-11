"""
Implementação do subset sum em forma de backtracking, resultando em todos os resultados
"""
def subset_sum(lista, capacidade, storage=()):
    if not lista:
        return
    if lista[0] == capacidade:  # Caso a recursão tenha chegado a um resultado, adciono à lista de resultados
        respostas.append(list(storage + (lista[0],)))
        return
    else:  # caso não, chamo recursivamente.
        """
        A primeira chamada continua a recursão com slice na lista
        A segunda chamada inicia novamente a chamada original mas com um slice na lista,
        para achar outros possíveis conjuntos
        """
        subset_sum(lista[1:], capacidade - lista[0], storage + (lista[0],))
        subset_sum(lista[1:], capacidade, storage)


##########################################################################
##########################################################################

def red(str):
    return '\033[91m' + str + '\033[0m'


respostas = []


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
    # itens maiores que a capacidade, assim a recurção não precisa
    # iterar itens que obviamente não fazer parte da solução
    if lista[len(lista) - 1] > capacidade:
        lista = lista[0:next(i for i, x in enumerate(lista) if x > capacidade)]

    # Agora sim, eu chamo minha função
    subset_sum(lista, capacidade)
    # Mostro o resultado
    resultado()


def resultado():
    if len(respostas) == 0:
        existe = "FALSE"
        subconjunto = "FALSE"
        subconjuntos = "FALSE"
    else:
        existe = "TRUE"
        subconjunto = respostas[0]
        subconjuntos = respostas
    print(
        """
        {pergunta_um}
            {existe}
        {pergunta_dois}
            {subconjunto}
        {pergunta_tres}
            {subconjuntos}
        """.format(
            pergunta_um=red(
                '1 ) Existe algum capacidadetório de subconjunto que é igual a capacidade?'),
            pergunta_dois=red(
                '2 ) Existe algum capacidadetório de subconjunto que é igual a capacidade?'),
            pergunta_tres=red(
                '3 ) Existe mais algum capacidadetório de subconjunto que é igual a capacidade?'),
            existe=existe,
            subconjunto=subconjunto,
            subconjuntos=subconjuntos
        ))


if __name__ == "__main__":
    main()
