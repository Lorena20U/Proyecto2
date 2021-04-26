from flask import Flask, redirect, url_for, request
from jinja2 import Template, Environment, FileSystemLoader
from met import data, mov_value
import tablero
import yaml
import random

file_loader = FileSystemLoader('templates')
env = Environment(loader = file_loader)

app = Flask(__name__)
with open('data.yml') as yaml_file:
    my_yaml = yaml.load(yaml_file)
    print(my_yaml)

@app.route('/')
def index():
    image_Risk = url_for('static', filename=my_yaml['fotoRisk'])
    image_B = url_for('static', filename=my_yaml['fotoBackgammon'] )
    template = env.get_template('menu.html')
    return template.render(image_Risk=image_Risk, image_B=image_B)

@app.route('/backgammon')
def backgammon():
    image_Dados = url_for('static', filename=my_yaml['fotoDados'])
    image_D = url_for('static', filename=my_yaml['fotoD'])

    stack1 = ""
    if tablero.stack1.is_empty() != True:
        s1 = tablero.stack1.peek()
        size1 = tablero.stack1.size()
        stack1 += data(s1, size1)

    stack2 = ""
    if tablero.stack2.is_empty() != True:
        s2 = tablero.stack2.peek()
        size2 = tablero.stack2.size()
        stack2 += data(s2, size2)

    stack3 = ""
    if tablero.stack3.is_empty() != True:
        s3 = tablero.stack3.peek()
        size3 = tablero.stack3.size()
        stack3 += data(s3, size3)

    stack4 = ""
    if tablero.stack4.is_empty() != True:
        s4 = tablero.stack4.peek()
        size4 = tablero.stack4.size()
        stack4 += data(s4, size4)

    stack5 = ""
    if tablero.stack5.is_empty() != True:
        s5 = tablero.stack5.peek()
        size5 = tablero.stack5.size()
        stack5 += data(s5, size5)

    stack6 = ""
    if tablero.stack6.is_empty() != True:
        s6 = tablero.stack6.peek()
        size6 = tablero.stack6.size()
        stack6 += data(s6, size6)

    stack7 = ""
    if tablero.stack7.is_empty() != True:
        s7 = tablero.stack7.peek()
        size7 = tablero.stack7.size()
        stack7 += data(s7, size7)

    stack8 = ""
    if tablero.stack8.is_empty() != True:
        s8 = tablero.stack8.peek()
        size8 = tablero.stack8.size()
        stack8 += data(s8, size8)

    stack9 = ""
    if tablero.stack9.is_empty() != True:
        s9 = tablero.stack9.peek()
        size9 = tablero.stack9.size()
        stack9 += data(s9, size9)

    stack10 = ""
    if tablero.stack10.is_empty() != True:
        s10 = tablero.stack10.peek()
        size10 = tablero.stack10.size()
        stack10 += data(s10, size10)

    stack11 = ""
    if tablero.stack11.is_empty() != True:
        s11 = tablero.stack11.peek()
        size11 = tablero.stack11.size()
        stack11 += data(s11, size11)

    stack12 = ""
    if tablero.stack12.is_empty() != True:
        s12 = tablero.stack12.peek()
        size12 = tablero.stack12.size()
        stack12 += data(s12, size12)
    
    stack13 = ""
    if tablero.stack13.is_empty() != True:
        s13 = tablero.stack13.peek()
        size13 = tablero.stack13.size()
        stack13 += data(s13, size13)

    stack14 = ""
    if tablero.stack14.is_empty() != True:
        s14 = tablero.stack14.peek()
        size14 = tablero.stack14.size()
        stack14 += data(s14, size14)

    stack15 = ""
    if tablero.stack15.is_empty() != True:
        s15 = tablero.stack15.peek()
        size15 = tablero.stack15.size()
        stack15 += data(s15, size15)

    stack16 = ""
    if tablero.stack16.is_empty() != True:
        s16 = tablero.stack16.peek()
        size16 = tablero.stack16.size()
        stack16 += data(s16, size16)

    stack17 = ""
    if tablero.stack17.is_empty() != True:
        s17 = tablero.stack17.peek()
        size17 = tablero.stack17.size()
        stack17 += data(s17, size17)

    stack18 = ""
    if tablero.stack18.is_empty() != True:
        s18 = tablero.stack18.peek()
        size18 = tablero.stack18.size()
        stack18 += data(s18, size18)
    
    stack19 = ""
    if tablero.stack19.is_empty() != True:
        s19 = tablero.stack19.peek()
        size19 = tablero.stack19.size()
        stack19 += data(s19, size19)

    stack20 = ""
    if tablero.stack20.is_empty() != True:
        s20 = tablero.stack20.peek()
        size20 = tablero.stack20.size()
        stack20 += data(s20, size20)

    stack21 = ""
    if tablero.stack21.is_empty() != True:
        s21 = tablero.stack21.peek()
        size21 = tablero.stack21.size()
        stack21 += data(s21, size21)

    stack22 = ""
    if tablero.stack22.is_empty() != True:
        s22 = tablero.stack22.peek()
        size22 = tablero.stack22.size()
        stack22 += data(s22, size22)

    stack23 = ""
    if tablero.stack23.is_empty() != True:
        s23 = tablero.stack23.peek()
        size23 = tablero.stack23.size()
        stack23 += data(s23, size23)

    stack24 = ""
    if tablero.stack24.is_empty() != True:
        s24 = tablero.stack24.peek()
        size24 = tablero.stack24.size()
        stack24 += data(s24, size24)    
        
    template = env.get_template('start.html')
    return template.render(image_Dados=image_Dados, image_D=image_D, stack1=stack1, stack2=stack2, stack3=stack3, stack4=stack4, stack5=stack5, stack6=stack6, stack7=stack7, stack8=stack8, stack9=stack9, stack10=stack10, stack11=stack11, stack12=stack12, stack13=stack13, stack14=stack14, stack15=stack15, stack16=stack16, stack17=stack17, stack18=stack18, stack19=stack19, stack20=stack20, stack21=stack21, stack22=stack22, stack23=stack23, stack24=stack24)

if __name__ == '__main__':
    app.run(host='localhost', port=5000, debug = True)