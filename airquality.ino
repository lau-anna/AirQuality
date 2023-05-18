#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);
int MQ2Pin = A0; // add MQ2 sensor pin
int MQ135Pin = A1; // add MQ135 sensor pin
int dustPin=A2; // add Dust sensor pin
int dustVal=0;
int delayTime=280;
int delayTime2=40;
float offTime=9680;
int ledPower=12;

void setup() {
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("YCH2SS");
  delay(3000); 
  lcd.clear(); 
  pinMode(ledPower,OUTPUT);
}

void loop() {
  int data_MQ2 = analogRead(MQ2Pin);
  int data_MQ135 = analogRead(MQ135Pin);
  lcd.setCursor(3,0); 
  lcd.print("MQ2: ");
  lcd.print(data_MQ2);
  delay(1000);  
  lcd.setCursor(3,1);
  lcd.print("MQ135: ");
  lcd.print(data_MQ135);
  delay(3000);   
  lcd.clear();
  digitalWrite(ledPower,LOW);
  delayMicroseconds(delayTime);
  dustVal=analogRead(dustPin);
  delayMicroseconds(delayTime2);
  digitalWrite(ledPower,HIGH);
  delayMicroseconds(offTime);
  lcd.setCursor(1,0);
  lcd.print("Dust Den: ");
  lcd.print(dustVal);
  delay(3000);
  lcd.clear();

}
