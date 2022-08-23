#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(6,7,5); //DIGITAL 6번:CLK, 7번:DAT, 5번:RST
#define YELLOW 12
#define GREEN 10
#define RED 8
#define WHITE 13
#define LED 11

void setup() {
  Serial.begin(57600);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT); 
  pinMode(WHITE, OUTPUT);
  myRTC.setDS1302Time(00, 59, 23, 2, 4, 4, 2016); //초,분,시,요일,일,월,년
//  아날로그 출력을 할때는 핀모드를 output으로 설정해주지 않아도 된다.
  
}

void loop() {
  
  myRTC.updateTime();
  int i = myRTC.dayofweek;
  Serial.print("Current Date / Time: ");
  Serial.print(myRTC.dayofmonth);  // 일
  Serial.print("/");
  Serial.print(myRTC.month);       //월
  Serial.print("/");
  Serial.print(myRTC.year);        //년
  Serial.print("  ");
  switch (i)                        //요일
  {
    case 1: Serial.print(" SUN "); break;
    case 2: Serial.print(" MON "); break;
    case 3: Serial.print(" TUE "); break;
    case 4: Serial.print(" WED "); break;
    case 5: Serial.print(" THU "); break;
    case 6: Serial.print(" FRI "); break;
    case 7: Serial.print(" SAT "); break;
  }
  Serial.print(myRTC.hours);      //시
  Serial.print(":");
  Serial.print(myRTC.minutes);    //분
  Serial.print(":");
  Serial.println(myRTC.seconds);  //초

  delay(1000); // 1초간 지연

  
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
    if (strRead.indexOf("L1") >= 0) {
      for(int i=0; i<256; i++)
      { analogWrite(LED,i);
      delay(20);
      }
    } else if (strRead.indexOf("L0") >= 0) {
      digitalWrite(LED, LOW);
//    Serial.println(strRead);
    }
  delay(200);
}
}
