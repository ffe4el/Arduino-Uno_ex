import time
import requests

SERVER_URL = "http://192.168.0.62:5000/"


def send_command(command):
    try:
        requests.get(SERVER_URL + command, timeout=1)
    except requests.exceptions.Timeout as e:
        print(e)


def main():
    i = 1
    while True:
        if i % 2 == 1:
            print("fan-on")
            send_command("fan-on")
        else:
            print("fan-off")
            send_command("fan-off")
        time.sleep(5)
        i += 1


if __name__ == "__main__":
    main()
