#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
//#include <DHT.h>

//#include <virtuabotixRTC.h>
//virtuabotixRTC myRTC(6,7,5); //DIGITAL 6번:CLK, 7번:DAT, 5번:RST


#define YELLOW 12
#define BLUE 10
#define RED 3
#define WHITE 13
#define GREEN 11
#define LED 11

void setup() {
  Serial.begin(9600);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT); 
  pinMode(GREEN, OUTPUT);
  pinMode(WHITE, OUTPUT);
}
  //  아날로그 출력을 할때는 핀모드를 output으로 설정해주지 않아도 된다.
  

void loop() {
  if (Serial.available() > 0) {
    String strRead = Serial.readStringUntil("\n");
    if (strRead.indexOf("R3") >= 0) {
      analogWrite(RED,255);
    } else if (strRead.indexOf("R2") >= 0) {
      analogWrite(RED, 100);
    } else if (strRead.indexOf("R1") >= 0) {
      analogWrite(RED, 50);
    } else if (strRead.indexOf("R0") >= 0) {
      analogWrite(RED, 0);
    }
    if (strRead.indexOf("Y1") >= 0) {
      digitalWrite(YELLOW, HIGH);
    } else if (strRead.indexOf("Y0") >= 0) {
      digitalWrite(YELLOW, LOW);
    }
    if (strRead.indexOf("B1") >= 0) {
      digitalWrite(BLUE, HIGH);
    } else if (strRead.indexOf("B0") >= 0) {
      digitalWrite(BLUE, LOW);
    }
    if (strRead.indexOf("G1") >= 0) {
      digitalWrite(GREEN, HIGH);
    } else if (strRead.indexOf("G0") >= 0) {
      digitalWrite(GREEN, LOW);
    }
    if (strRead.indexOf("W1") >= 0) {
      digitalWrite(WHITE, HIGH);
    } else if (strRead.indexOf("W0") >= 0) {
      digitalWrite(WHITE, LOW);
    }
  }
  Serial.flush();
  delay(20);

}
