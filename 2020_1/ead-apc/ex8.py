def funcao1(y):
    y = 3    
    return y

def main():
    x = 1

    print("antes da funcao x = %s"%(x))
    x = funcao1(x)
    print("depois da funcao x = %s"%(x))



if __name__ == "__main__":
    main()



