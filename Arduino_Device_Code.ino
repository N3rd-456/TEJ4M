#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

#define analogPin  A0 
#define beta 3950 
#define resistance 10 
#define rotation 250

const int motor1 = 9;
const int motor2 = 3; 

void setup()
{
  
  lcd.begin(16, 2);   
  lcd.clear();

  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  
  long thermistorValue = analogRead(analogPin);
  float celsius = beta / (log((1025.0 * 10 / thermistorValue - 10) / 10) + beta / 298.0) - 273.0;
  float fahrenheit = 1.8 * celsius + 32.0;
  
  lcd.setCursor(0, 0); 
  lcd.print("Temp: ");
  lcd.print(celsius);
  lcd.print(char(223));
  lcd.print("C");
  
  lcd.setCursor(0, 1); 
  lcd.print("Fahr: ");
  lcd.print(fahrenheit);
  lcd.print(" F"); 
  delay(100); 

  if (celsius > 30.0)
  {
    fanSpin(rotation);
  }

  else
  {
    fanSpin(0);
  }

}

void fanSpin(int rotationSpeed)
{
  
  analogWrite(motor1,0);
  analogWrite(motor2,rotationSpeed);
  
}
