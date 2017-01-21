from flask import Flask, request, make_response, jsonify, redirect, url_for, render_template

app = Flask("HACKATHON YEAHHH", template_folder='templates')

html_headers = {'Content-Type': 'text/html'}
json_headers = {'Content-Type': 'application/json'}

left_exit  = 0
left_enter = 0
right_exit = 0
right_enter = 0

@app.route('/home')
@app.route('/')
def home():
    return make_response(render_template('index.html'), 200, html_headers)

@app.route('/update')
def update():
    return make_response(jsonify(left_exit=left_exit,
                                 left_enter=left_enter,
                                 right_exit=right_exit,
                                 right_enter=right_enter), 200, json_headers)


host = '0.0.0.0'
port = 80
debug = True
app.config['HOST'] = host + ":" + str(port)

app.run(host=host, port=port, debug=debug, threaded=True)


