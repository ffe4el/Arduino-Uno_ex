#include <Wire.h>
#include <Servo.h>
//#include <virtuabotixRTC.h>
//virtuabotixRTC myRTC(6,7,5); //DIGITAL 6번:CLK, 7번:DAT, 5번:RST


#define YELLOW 12
#define BLUE 10
#define RED 8
#define WHITE 13
#define GREEN 11
#define LED 11
//온습도센서 연결설정
//#define DHTPIN 3 //디지털 3번핀 사용
//#define DHTTYPE DHT11 // DHT 11 모델 사용
#define FAN_PIN 7
#define LIGHTPIN 6
#define SERVOPIN 9

Servo servo; 
int motorval =0;
void setup() {
//  lcd.init();
  Serial.begin(9600);
  pinMode(LIGHTPIN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT); 
  pinMode(GREEN, OUTPUT);
  pinMode(WHITE, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(SERVOPIN, OUTPUT);
  //  아날로그 출력을 할때는 핀모드를 output으로 설정해주지 않아도 된다.
  analogWrite(LIGHTPIN, 255);

}
void loop() { 
  if (Serial.available() > 0) {
    String strRead = Serial.readStringUntil("\n");
    if (strRead.indexOf("R1") >= 0) {
      digitalWrite(RED, HIGH);
    } else if (strRead.indexOf("R0") >= 0) {
      digitalWrite(RED, LOW);
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
    if (strRead.indexOf("C_F-1") >= 0) {
      digitalWrite(FAN_PIN, 1);
    } else if (strRead.indexOf("C_F-0") >= 0) {
      digitalWrite(FAN_PIN, 0);
    }
//    if (strRead.indexOf("C_L-0") >= 0) {
//      analogWrite(LIGHTPIN,0);
//    }else if (strRead.indexOf("C_L-1") >= 0) {
//      analogWrite(LIGHTPIN,25);
//    }else if (strRead.indexOf("C_L-2") >= 0) {
//      analogWrite(LIGHTPIN,50);
//    }else if (strRead.indexOf("C_L-3") >= 0) {
//      analogWrite(LIGHTPIN,75);
//    }else if (strRead.indexOf("C_L-4") >= 0) {
//      analogWrite(LIGHTPIN,100);
//    }else if (strRead.indexOf("C_L-5") >= 0) {
//      analogWrite(LIGHTPIN,125);
//    }else if (strRead.indexOf("C_L-6") >= 0) {
//      analogWrite(LIGHTPIN,150);
//    }else if (strRead.indexOf("C_L-7") >= 0) {
//      analogWrite(LIGHTPIN,175);
//    }else if (strRead.indexOf("C_L-8") >= 0) {
//      analogWrite(LIGHTPIN,200);
//    }else if (strRead.indexOf("C_L-9") >= 0) {
//      analogWrite(LIGHTPIN,225);
//    }else if (strRead.indexOf("C_L-10") >= 0) {
//      analogWrite(LIGHTPIN,250);
//    }
        if (strRead.indexOf("C_L-") >= 0) {
          int light = strRead.substring(strRead.indexOf("C_L-")+4, strRead.indexOf("C_L-")+5).toInt();
          Serial.println(light);
          Serial.println((int)(25 * light));
          analogWrite(LIGHTPIN, (int)(25 * light));
          digitalWrite(GREEN,HIGH);
        }
        
        if (strRead.indexOf("C_S-") >= 0) {
          if(strRead[strRead.indexOf("C_S-")+4] == '0') motorval = 10;
          else motorval = 80;
          servo.attach(SERVOPIN);
          servo.write(motorval); 
          delay(500);
          servo.detach();
        }


//if (strRead.indexOf("L1") >= 0) {
//      for(int i=0; i<256; i++)
//      { analogWrite(LED,i);
//      delay(20);
//      }
//    } else if (strRead.indexOf("L0") >= 0) {
//      digitalWrite(LED, LOW);
     
//    Serial.println(strRead);
    
    
  delay(200);
  }
}
