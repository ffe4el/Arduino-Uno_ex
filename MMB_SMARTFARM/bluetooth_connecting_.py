"""
A simple Python script to send messages to a sever over Bluetooth
using PyBluez (with Python 2).
"""
import bluetooth
import time


serverMACAddress = '00:22:02:01:2F:00'
port = 9600
s = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
s.connect((serverMACAddress, port))
# while 1:
# 	# text = raw_input() # Note change to the old (Python 2) raw_input
# 	text = "test"
# 	if text == "quit":
# 		break
# 	s.send(text)
s.send("C_F-1\n")
time.sleep(3)
s.send("C_F-0\n")
s.close()
