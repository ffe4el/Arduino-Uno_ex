#include "DS3231.h"
#include <Wire.h>

DS3231 Clock;
bool Century,h12,PM;
int year, month, date, DoW, hour, minute, second,temperature;

void setup() {
	
	Wire.begin();

  //Current Time Setting 
 
   Clock.setSecond(00); //Set the second 
   Clock.setMinute(56);  //Set the minute 
   Clock.setHour(18);  //Set the hour c
   Clock.setDoW(2);    //Set the day of the week
   Clock.setDate(25);  //Set the date of the month
   Clock.setMonth(4); //Set the month of the year
   Clock.setYear(22);  //Set the year 
                    //(Last two digits of the year)
	
  
   delay(10);
    Serial.begin(9600);
}

void ReadDS3231()
{
  second=Clock.getSecond();
  minute=Clock.getMinute();
  hour=Clock.getHour(h12,PM);
  DoW=Clock.getDoW();
  date=Clock.getDate();
  month=Clock.getMonth(Century);
  year=Clock.getYear();
  
  temperature=Clock.getTemperature();
 
  Serial.print("20");
  //Serial.print(year,DEC);
  Serial.print(year);
  Serial.print('-');
  Serial.print(month,DEC);
  Serial.print('-');
  Serial.print(date,DEC);
  Serial.print('(');
  Serial.print(DoW,DEC);
  Serial.print(") ");
  Serial.print(hour,DEC);
  Serial.print(':');
  Serial.print(minute,DEC);
  Serial.print(':');
  Serial.print(second,DEC);
  Serial.print('\n');
  Serial.print("Temperature=");
  Serial.print(temperature); 
  Serial.print('\n');
}

void loop() {
  ReadDS3231();
  delay(3000);
	
 }
