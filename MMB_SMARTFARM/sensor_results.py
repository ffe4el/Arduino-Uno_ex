import time
import serial
import serial.tools.list_ports
import threading

def send_temperature():
    sendData=f"TEMPERATURE=? \n"
    my_serial.write(sendData.encode())