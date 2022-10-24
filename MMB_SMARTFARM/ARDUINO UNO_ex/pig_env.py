#시리얼 통신 라이브러리
import json
import serial.tools.list_ports
import serial
import time
import threading
from flask import Flask
import pandas as pd
import schedule
import keyboard

# app = Flask(__name__)
#10번 포트에 연결된 serial을 s로 지정(채널:9600)
s = serial.Serial('COM9', 9600)

df = pd.read_csv('scenario_data.csv')

# print(df.columns)
print(df["난방기"][0])


def send_signal_to_sfarm(msg):
    if (s.readable()):
        s.write("{}\n".format(msg).encode())
        # time.sleep(0.2)


# @app.route('/red-on')
def red_3():
    send_signal_to_sfarm("R3")
    send_signal_to_sfarm("Y1")

# @app.route('/red-off')
def red_2():
    send_signal_to_sfarm("R2")
    send_signal_to_sfarm("Y0")

def red_1():
    send_signal_to_sfarm("R1")
    send_signal_to_sfarm("B1")

def red_0():
    send_signal_to_sfarm("R0")
    send_signal_to_sfarm("B0")



# @app.route('/yellow-on')
def yellow_on():
    send_signal_to_sfarm("Y1")



# @app.route('/yellow-off')
def yellow_off():
    send_signal_to_sfarm("Y0")


# @app.route('/green-on')
def green_on():
    send_signal_to_sfarm("G1")



# @app.route('/green-off')
def green_off():
    send_signal_to_sfarm("G0")



# @app.route('/white-on')
def white_on():
    send_signal_to_sfarm("W1")


# @app.route('/white-off')
def white_off():
    send_signal_to_sfarm("W0")


# @app.route('/blue-on')
def blue_on():
    send_signal_to_sfarm("B1")


# @app.route('/blue-off')
def blue_off():
    send_signal_to_sfarm("B0")


def go_go():
    for i in range(0,289):
        # print(df["난방기"][i])
        time.sleep(1)
        if df["난방기"][i] == 3:
            print(df["난방기"][i])
            send_signal_to_sfarm("R3")
            # return send_signal_to_sfarm("R3")
        elif df["난방기"][i] == 2:
            print(df["난방기"][i])
            send_signal_to_sfarm("R2")
            # return send_signal_to_sfarm("R2")
        elif df["난방기"][i] == 1:
            send_signal_to_sfarm("R1")
            # return send_signal_to_sfarm("R1")
        elif df["난방기"][i] == 0:
            send_signal_to_sfarm("R0")
            # return send_signal_to_sfarm("R0")

go_go()

# def main():
#     # a = go_go()
#     while True:
#         # schedule 실행
#         schedule.run_pending()
#
#         schedule.every(2).seconds.do(yellow_on)
#         schedule.every(2).seconds.do(yellow_off)
#         # schedule.every(2).seconds.do(red_1)
#         # schedule.every(2).seconds.do(red_0)
#         # schedule.every(1).seconds.do(winter_first)
#         # schedule.every(1).seconds.do(rain_first)
#         # schedule.every(10).seconds.do(summer_second)
#         # schedule.every(10).seconds.do(winter_second)
#         # schedule.every(10).seconds.do(rain_second)
#         # schedule.every(10).seconds.do(summer_third1)
#         # schedule.every(10).seconds.do(winter_third1)
#         # schedule.every(10).seconds.do(rain_third1)
#
#         if keyboard.is_pressed("q"):
#             break
#
#
# if __name__ == '__main__':
#     main()

# app.run(host="0.0.0.0", threaded=True)