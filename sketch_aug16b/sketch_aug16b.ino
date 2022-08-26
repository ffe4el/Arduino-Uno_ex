#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

//#include <virtuabotixRTC.h>
//virtuabotixRTC myRTC(6,7,5); //DIGITAL 6번:CLK, 7번:DAT, 5번:RST


#define YELLOW 12
#define GREEN 10
#define RED 8
#define WHITE 13
#define LED 11
//온습도센서 연결설정
#define DHTPIN 3 //디지털 3번핀 사용
#define DHTTYPE DHT11 // DHT 11 모델 사용

//위에꺼 실행안되면 3으로 다시 해보깅

//LCD 설정
LiquidCrystal_I2C lcd(0x27,16,2);

DHT dht(DHTPIN,DHTTYPE);



void setup() {
  lcd.init();
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT); 
  pinMode(WHITE, OUTPUT);
  //  아날로그 출력을 할때는 핀모드를 output으로 설정해주지 않아도 된다.
  
  Serial.println("DHT testing.....");
  dht.begin();
  lcd.init();
  lcd.backlight();
  
//  myRTC.setDS1302Time(00, 59, 23, 2, 4, 4, 2016); //초,분,시,요일,일,월,년
}

void loop() {
//  시계 RTC
//  myRTC.updateTime();
//  int i = myRTC.dayofweek;
//  Serial.print("Current Date / Time: ");
//  Serial.print(myRTC.dayofmonth);  // 일
//  Serial.print("/");
//  Serial.print(myRTC.month);       //월
//  Serial.print("/");
//  Serial.print(myRTC.year);        //년
//  Serial.print("  ");
//  switch (i)                        //요일 
//  {
//    case 1: Serial.print(" SUN "); break;
//    case 2: Serial.print(" MON "); break;
//    case 3: Serial.print(" TUE "); break;
//    case 4: Serial.print(" WED "); break;
//    case 5: Serial.print(" THU "); break;
//    case 6: Serial.print(" FRI "); break;
//    case 7: Serial.print(" SAT "); break;
//  }
//  Serial.print(myRTC.hours);      //시
//  Serial.print(":");
//  Serial.print(myRTC.minutes);    //분
//  Serial.print(":");
//  Serial.println(myRTC.seconds);  //초
//
//  delay(1000); // 1초간 지연
//  delay(2000);
//  float h = dht.readHumidity(); // 습도 측정
//  float t = dht.readTemperature(); // 온도 측정
//  lcd.backlight();
//  lcd.display();
//  lcd.print("TEMP:       ");
//  lcd.print(t);
//  lcd.print("HUMIDITY:   ");
//  lcd.print(h);
//  
//  Serial.print("습도: ");
//  Serial.print(h);
//  Serial.print("온도: ");
//  Serial.print(t);
//  Serial.println();
//  delay(2000);
//  lcd.clear();

  delay(2000);

  float h=dht.readHumidity();

  float t=dht.readTemperature();



  if(isnan(h)||isnan(t)){

    Serial.println("Fail to read....");

  }

  else{

    Serial.print("Hudimity ");
  
    Serial.print(h);
  
    Serial.println("%");
  
    Serial.print("Temperature ");
  
    Serial.print(t);
  
    Serial.println("C");



    lcd.setCursor(0,0);
    
    lcd.print("Humidity ");
    
    lcd.setCursor(10,0);
    
    lcd.print((int)h);
    
    lcd.setCursor(13,0);
    
    lcd.print("%");



  lcd.setCursor(0,1);
  
  lcd.print("Temp ");
  
  lcd.setCursor(10,1);
  
  lcd.print((int)t);
  
  lcd.setCursor(13,1);
  
  lcd.print("C");

  }

  
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
