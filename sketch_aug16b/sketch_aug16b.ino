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
//  아날로그 출력을 할때는 핀모드를 output으로 설정해주지 않아도 된다.
  
}

void loop() {
//  digitalWrite(GREEN, HIGH);
  if (Serial.available() > 0) {
//    Serial.println("ready");
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
//  digitalWrite(GREEN, HIGH);
//  digitalWrite(YELLOW, LOW);
//  digitalWrite(RED, LOW) ;
//  delay(1000);
//  digitalWrite(GREEN, LOW);
//  digitalWrite(YELLOW, HIGH);
//  digitalWrite(RED, LOW) ;
//  delay(1000);
//  digitalWrite(GREEN, LOW);
//  digitalWrite(YELLOW, LOW);
//  digitalWrite(RED, HIGH) ;
//  delay(1000);
// delay 1000은 1초 대기
