#  entre 0 e 5 = reprovado
#  >= 5 < 7 = mm
#  >= 7 < 9 = ms
#    >= 9 <= 10 = ss

nota = 9.5

if nota < 5:
    print("Reprovado")
else:
    if (nota >=5 and nota <7):
        print("MM")
    else:
        if (nota >=9):
            print("SS")
        else:
            if (nota>=7 and nota <9):
                print("MS")


if nota < 5:
    print("Reprovado")
elif (nota >=5 and nota <7):
    print("MM")
elif (nota >=9):
    print("SS")
elif (nota>=7 and nota <9):
    print("MS")



    

    