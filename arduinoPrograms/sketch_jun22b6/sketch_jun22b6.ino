#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(6,OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  
  lcd.setCursor(0, 1);
  
  if((millis() / 1000)%2 == 0)
  {
    lcd.print(" ONN ");
  lcd.print(millis() / 1000);
  digitalWrite(6,LOW);
  delay(500);
  }
  else
  {
    lcd.print(" OFF ");
  lcd.print(millis() / 1000);
  digitalWrite(6,HIGH);
  delay(500);
  }
}

