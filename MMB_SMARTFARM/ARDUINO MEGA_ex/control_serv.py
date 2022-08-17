#시리얼 통신 라이브러리
import json
import serial.tools.list_ports
import serial
import time
import threading



from flask import Flask

app = Flask
#10번 포트에 연결된 serial을 s로 지정(채널:9600)
s = serial.Serial('COM3', 9600)

@app.route('/')
def index():
    return 'Index Page'


@app.route('/fan-on')
def fan_on():
    send_signal_to_sfarm("C_F-1")

    return "Order Fan On"


def send_signal_to_sfarm(msg):
    while True:
        z = s.readline()
        # print(z)
        # 내용이 비어있지 않으면 프린트

        if not z.decode().startswith("#"):
            z = z.decode()[:len(z) - 1]
            print("내용출력:", end="")
            print(z)
            if z.startswith("{ \"temp"):
                data = json.loads(z)
                temp = int(data["temp"])
        else:
            break
    if (s.readable()):
        s.write("{}\n".format(msg).encode())


@app.route('/fan-off')
def fan_off():
    send_signal_to_sfarm("C_F-0")
    return "Order Fan Off"

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
