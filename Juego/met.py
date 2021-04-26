import random
import tablero

def mov_value():
    value = random.randint(1, 6)
    return value

def data(p_element, size):
    fichas = ""
    if str(p_element) != "negro":
        for i in range(0, size):
            fichas += "O"
            if i != size:
                fichas += " "
    else:
        for j in range(0, size):
            fichas += "X"
            if j != size:
                fichas += " "        
    return fichas

def mov(d1: int, d2: int):
    opcion = [[0,0], [0,0]]
    if d1 == d2:
        opcion =[[0,0], [0,0], [0,0],[0,0]]
    
    if int(len(opcion)) == 2:
        opcion = [[d1, d2], [(d1+d2),0]]
    else:
        opcion = [[1, d2], [2, (d1+d2)], [(d1+d2+d1), d2], [(d1+d1+d2+d2), 0]]
    
    return opcion

#print(mov(mov_value(), mov_value()))
    