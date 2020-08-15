/*

Tendo como base o comportamento da estrutura de uma tabela verdade.
Preencha os valores abaixo:


a)  A=V, B=V, C=F, D=F
    ((A ou B) e (A ou C)) e (D e F)
                x      e     F       = f OU 0

b)  A=V, B=F, C=V, D=V, E=F
((A ou B) e (B ou C))        ou            ((C ou D) e (D ou E))
    v     e     v
            v                 ou ? = v           v      e     v
                                                        v

c)  A = (B e C), D = (E ou J), G = (H e I),B=V,C=F,E=V,J=F,H=V,I=F
        F             V            F
(A OU B) E (D OU G) 
    V     e     V  = v

    x = []