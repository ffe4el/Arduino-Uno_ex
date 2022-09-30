import time
import requests
import numpy as np
from matplotlib import pyplot as plt
from matplotlib import animation
import matplotlib

SERVER_URL = "http://192.168.0.66:5000/"

matplotlib.use('TkAgg')
plt.rcParams["figure.figsize"] = [7.50, 3.50]
plt.rcParams["figure.autolayout"] = True

temp_threshold = 28

fig = plt.figure()
ax = plt.axes(xlim=(0, 2), ylim=(18, 32))
ax.set_ylabel("Indoor temperature (degrees C)")
ax.set_xlabel("time line")
line, = ax.plot([], [], lw=2)

plt.axhline(y=temp_threshold, ls="--")
line_color = "b"
stage = -1

def send_command(command):
   try:
      requests.get(SERVER_URL + command, timeout=1)
      print(SERVER_URL + command)
   except requests.exceptions.Timeout as e:
      print(e)


def init():
   line.set_data([], [])
   return line,


def animate(i):
   global line_color
   global stage
   x = np.linspace(0, 2 * np.pi, 2000)
   y = 5 * np.sin(np.pi * (x + 0.01 * i)) + 25
   if y[0] < temp_threshold:
      # if line_color == "r":
      #    send_command("red-off")
      line_color = "b"
   else:
      # if line_color == "b":
      #    send_command("red-on")
      line_color = "r"

   current_stage = (y[0] - 20) // 2 + 1
   current_stage = min(current_stage, 5)

   if stage != current_stage:
      stage = current_stage
      if stage == 1:
         send_command("fan-on")
      elif stage == 2:
         send_command("fan-off")
      elif stage == 3:
         send_command("fan-on")
      elif stage == 4:
         send_command("fan-off")
      elif stage == 5:
         send_command("fan-on")
   line.set_data(x, y)
   line.set_color(line_color)
   return line,

anim = animation.FuncAnimation(fig, animate, init_func=init, frames=2000, interval=200, blit=True)
plt.show()