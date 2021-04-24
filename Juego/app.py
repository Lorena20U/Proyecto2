from flask import Flask, redirect, url_for, request
from jinja2 import Template, Environment, FileSystemLoader
import yaml

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

if __name__ == '__main__':
    app.run(host='localhost', port=5000, debug = True)