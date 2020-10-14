/*

MESSAGE: BCCABBDDAECCBBAEDDCC

TAMANHO 20

ASCII CODE 8 BITS

A   65  01000001
B   66  01000010
C   67
D   68
E   69

8BITS POR LETRA * 20 LETRAS = 160 BITS.

Nós não estamos utilizando todos os caracteres do alfabeto ASCII muito menos
todos os simbolos do teclado. Pq utilizar 8 bits para representar todo o
alfabeto da nossa mensagem?

Nâo podemos utilizar nossa própria tabela de códigos?



Fixe Size Codes


letra   count/frequency     code
a           3 (3/20)
b           5 (5/20)
c           6 (6/20)
d           4 (4/20)
e           2 (2/20)

O que podemos fazer com essa informação?

Será que a frequencia não pode nos ajudar a comprimir ainda mais ao invez de só mudar o tamanho do código 
que o representa?


Quantos bits eu preciso pra representar todo meu alfabeto?

5 letras 3 bits cabem 8

000
001
010
011
100
101
110
111

20 * 3 bits = 60 bits
porém precisa de uma tabela para tradução

Tabela de tradução
5 letras * 8 bits ( seu verdadeiro significado ) = 40 bits
5 letras * 3 bits                                  15 bits
total 55 bits

60 bits + 55 bits = 115 bits

huffman propriamente dito

Que tal a gente dar um código menor para os caracteres quie aparecem mais e um código maior para os que aparecem menos?:

Mesma tabela:
letra   count/frequency     code
a           3 (3/20)
b           5 (5/20)
c           6 (6/20)
d           4 (4/20)
e           2 (2/20)

opmital marsh pattern

vamos ordenar as frequencias?

a -> b -> c -> d -> e
e -> a -> d -> b -> c

Monte nós com os valores que menos acontece para que os que mais acontece fiquem em uma maior altura da arvore.





                                                

