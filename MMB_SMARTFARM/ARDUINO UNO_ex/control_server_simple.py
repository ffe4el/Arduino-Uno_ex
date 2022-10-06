#시리얼 통신 라이브러리
import json
import serial.tools.list_ports
import serial
import time
import threading

from flask import Flask

app = Flask(__name__)
#10번 포트에 연결된 serial을 s로 지정(채널:9600)
s = serial.Serial('COM7', 9600)

@app.route("/")
def index():
    return """
    <ul>
        <li><a href="./red-on">red <b>ON</b></a></li>
        <li><a href="./red-off">red <b>OFF</b></a></li>
        <br>
        <li><a href="./yellow-on">yellow <b>ON</b></a></li>
        <li><a href="./yellow-off">yellow <b>OFF</b></a></li>
        <br>
        <li><a href="./green-on">green <b>ON</b></a></li>
        <li><a href="./green-off">green <b>OFF</b></a></li>
        <br>
        <li><a href="./white-on">white <b>ON</b></a></li>
        <li><a href="./white-off">white <b>OFF</b></a></li>
        <br>
        <li><a href="./led-on">led <b>ON</b></a></li>
        <li><a href="./led-off">led <b>OFF</b></a></li>
    </ul>
    """


def send_signal_to_sfarm(msg):
    if (s.readable()):
        s.write("{}\n".format(msg).encode())
        time.sleep(0.2)


@app.route('/red-on')
def red_on():
    send_signal_to_sfarm("R1")
    return index()


@app.route('/red-off')
def red_off():
    send_signal_to_sfarm("R0")
    return index()


@app.route('/yellow-on')
def yellow_on():
    send_signal_to_sfarm("Y1")
    return index()


@app.route('/yellow-off')
def yellow_off():
    send_signal_to_sfarm("Y0")
    return index()

@app.route('/green-on')
def green_on():
    send_signal_to_sfarm("G1")
    return index()


@app.route('/green-off')
def green_off():
    send_signal_to_sfarm("G0")
    return index()


@app.route('/white-on')
def white_on():
    send_signal_to_sfarm("W1")
    return index()

@app.route('/white-off')
def white_off():
    send_signal_to_sfarm("W0")
    return index()

@app.route('/led-on')
def led_on():
    send_signal_to_sfarm("L1")
    return index()

@app.route('/led-off')
def led_off():
    send_signal_to_sfarm("L0")
    return index()


@app.route('/raw/<code>')
def send_rawcode(code):
    send_signal_to_sfarm(code)
    return index()





@app.route('/light-on/<level>')
def light_on(level):
    send_signal_to_sfarm("C_L-{}".format(level))
    return f"Order Light {level}"

# @app.route('/light-on')
# def light_on():
#     send_signal_to_sfarm("C_L-10")
#     return "Order Light 10"


@app.route('/light-off')
def light_off():
    send_signal_to_sfarm("C_L-0")
    return "Order Light 0"

app.run(host="0.0.0.0")
