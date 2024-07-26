import sys
from jinja2 import Environment, FileSystemLoader, select_autoescape
import os

if len(sys.argv) < 3:
    print()
    sys.exit(1)

with open(sys.argv[1], 'w+') as file:
    print(os.getcwd())

    templateLoader = FileSystemLoader(searchpath="../gen/templates/")
    templateEnv = Environment(loader=templateLoader)
    TEMPLATE_FILE = "lexer_template.txt"
    template = templateEnv.get_template(TEMPLATE_FILE)
    file.write(template.render(value = 5))
