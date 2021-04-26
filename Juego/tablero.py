class pieces:
    def __init__(self, id):
        self.id = id
    
    def __str__(self):
        return str(self.id)

class Stack:
    def __init__(self, posicion):
        self.stack = []
        self.posicion = posicion

    def __bool__(self):
        return bool(self.stack)

    def __str__(self):
        return str(self.stack)

    def push(self, data):
        #Empuja a la parte sup
        self.stack.append(data)

    def pop(self):
        #Saca un elem de la parte sup
        return self.stack.pop()

    def peek(self):
        #Observa al elemento superior de la pila
        return self.stack[-1]

    def is_empty(self):
        #Comprueba si esta vacia
        return not bool(self.stack)

    def size(self):
        #Tamanio
        return len(self.stack)

    def __contains__(self, item):
        #Comprueba si esta en la pila
        return item in self.stack


#Piezas negras = X
X1 = pieces("negro")
X2 = pieces("negro")
X3 = pieces("negro")
X4 = pieces("negro")
X5 = pieces("negro")
X6 = pieces("negro")
X7 = pieces("negro")
X8 = pieces("negro")
X9 = pieces("negro")
X10 = pieces("negro")
X11 = pieces("negro")
X12 = pieces("negro")
X13 = pieces("negro")
X14 = pieces("negro")
X15 = pieces("negro")

#Piezas blancas = O
O1 = pieces("blanco")
O2 = pieces("blanco")
O3 = pieces("blanco")
O4 = pieces("blanco")
O5 = pieces("blanco")
O6 = pieces("blanco")
O7 = pieces("blanco")
O8 = pieces("blanco")
O9 = pieces("blanco")
O10 = pieces("blanco")
O11 = pieces("blanco")
O12 = pieces("blanco")
O13 = pieces("blanco")
O14 = pieces("blanco")
O15 = pieces("blanco")

#--------------------->Formacion tablero inicial<----------------------------
#Stacks - filas
#--> Cuadrante interno
stack1 = Stack(1)
stack1.push(O1)
stack1.push(O2)

stack2 = Stack(2)
stack3 = Stack(3)
stack4 = Stack(4)
stack5 = Stack(5)
stack6 = Stack(6)
stack6.push(X11)
stack6.push(X12)
stack6.push(X13)
stack6.push(X14)
stack6.push(X15)

stack19 = Stack(19)
stack19.push(O11)
stack19.push(O12)
stack19.push(O13)
stack19.push(O14)
stack19.push(O15)

stack20 = Stack(20)
stack21 = Stack(21)
stack22 = Stack(22)
stack23 = Stack(23)
stack24 = Stack(24)
stack24.push(X1)
stack24.push(X2)

#-->Cuadrante externo
stack7 = Stack(7)
stack8 = Stack(8)
stack8.push(X8)
stack8.push(X9)
stack8.push(X10)

stack9 = Stack(9)
stack10 = Stack(10)
stack11 = Stack(11)
stack12 = Stack(12)
stack12.push(O3)
stack12.push(O4)
stack12.push(O5)
stack12.push(O6)
stack12.push(O7)

stack13 = Stack(13)
stack13.push(X3)
stack13.push(X4)
stack13.push(X5)
stack13.push(X6)
stack13.push(X7)

stack14 = Stack(14)
stack15 = Stack(15)
stack16 = Stack(16)
stack17 = Stack(17)
stack17.push(O8)
stack17.push(O9)
stack17.push(O10)

stack18 = Stack(18)

Estructura_inicial_ejemplo='''
12  [O O O O O  ] [  X X X X X] 13
11  [           ] [           ] 14
10  [           ] [           ] 15
9   [           ] [           ] 16
8   [X X X      ] [      O O O] 17
7   [           ] [           ] 18
    ---------------------------
    [           BAR           ]
    ---------------------------
6   [X X X X X  ] [  O O O O O] 19
5   [           ] [           ] 20
4   [           ] [           ] 21
3   [           ] [           ] 22
2   [           ] [           ] 23
1   [O O        ] [        X X] 24
    -------------|-------------
    [           HOME          ] '''
#print(Estructura_inicial_ejemplo)


''' p = Stack()

print(p.is_empty())
p.push(4)
p.push('perro')
print(p.peek())
p.push(True)
print(p.size())
print(p.is_empty())
p.push(8.4)
print(p.pop())
print(p.pop())
print(p.size())
print(p) '''