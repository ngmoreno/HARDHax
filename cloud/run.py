from flask import Flask, request, make_response, jsonify, redirect, url_for, render_template
from . import getState

app = Flask("HACKATHON YEAHHH", template_folder='templates')

html_headers = {'Content-Type': 'text/html'}
json_headers = {'Content-Type': 'application/json'}

@app.route('/home')
@app.route('/')
def home():
    return make_response(render_template('index.html'), 200, html_headers)

@app.route('/update')
def update():
    return make_response(jsonify(state=getState()), 200, json_headers)

host = '0.0.0.0'
port = 5000
debug = True
app.config['HOST'] = host + ":" + str(port)

app.run(host=host, port=port, debug=debug, threaded=True)


