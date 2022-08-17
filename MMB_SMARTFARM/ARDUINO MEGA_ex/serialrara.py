#시리얼 통신 라이브러리
import json
import serial.tools.list_ports
import serial
import time
import threading

#10번 포트에 연결된 serial을 s로 지정(채널:9600)
s=serial.Serial('COM3',9600)
#무한반복
temp = 25
light = 0
while(1):
    #시리얼 모니터에 입력된 내용을 받아 z에 저장

    while True:
        z = s.readline()
        # print(z)
        #내용이 비어있지 않으면 프린트

        if not z.decode().startswith("#"):
            z=z.decode()[:len(z)-1]
            #디코딩
            #출력
            print("내용출력:", end="")
            print(z)
            if z.startswith("{ \"temp"):
                data = json.loads(z)
                temp = int(data["temp"])
        else:
            break
    print("temp: ", temp)
    #읽을 수 있다면
    if(s.readable()):
        #파이썬에서 입력받는다.
        # val=input()+"\n"
        # val = "C_L-{:d}\n".format(light%10)
        #인코딩
        # val = val.encode('utf-8')
        # val = val.encode()
        # print(val)
        #시리얼 모니터로 전송
        # s.write(val)
        if temp >= 26:
            s.write("C_F-1\n".encode())
            s.write("C_L-5\n".encode())
        else:
            s.write("C_F-0\n".encode())
            s.write("C_L-10\n".encode())
        if temp >= 26:
            s.write("C_S-0\n".encode())
        else:
            s.write("C_S-1\n".encode())
        light += 1
        if light > 10:
            print(light)
            s.write("C_F-1\n".encode())

    time.sleep(1)
