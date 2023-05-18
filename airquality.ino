#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);
int MQ2Pin = A0; //add MQ2 sensor pin
int MQ135Pin = A1; //add MQ135 sensor pin
int dustPin=A2; //add Dust sensor pin
int dustVal=0;  
int delayTime=280;
int delayTime2=40;
float offTime=9680;
int ledPower=12;

void setup() {
  lcd.init(); //initialize LCD monitor
  lcd.backlight();
  lcd.setCursor(3,0); //set cursor to line 1
  lcd.print("YCH2SS"); 
  delay(3000); //delay 3 seconds
  lcd.clear();  //clear all characters in lcd
  pinMode(ledPower,OUTPUT); 
}

void loop() {
  int data_MQ2 = analogRead(MQ2Pin);
  int data_MQ135 = analogRead(MQ135Pin);
  lcd.setCursor(3,0);  //set cursor to line 1
  lcd.print("MQ2: ");
  lcd.print(data_MQ2); //print the data of MQ2
  delay(1000);
  lcd.setCursor(3,1);  //set cursor to line 2
  lcd.print("MQ135: ");
  lcd.print(data_MQ135); //print out the data of MQ135
  delay(3000);   
  lcd.clear();
  digitalWrite(ledPower,LOW); //power on the LED of dust sensor
  delayMicroseconds(delayTime);
  dustVal=analogRead(dustPin); //read the dust value
  delayMicroseconds(delayTime2);
  digitalWrite(ledPower,HIGH); //power off the LED of dust sensor
  delayMicroseconds(offTime);
  lcd.setCursor(1,0); //set cursor to the line 1
  lcd.print("Dust Den: ");
  lcd.print(dustVal); //print the dust value
  delay(3000); //delay 3 seconds
  lcd.clear(); //clear all characters in lcd

}
