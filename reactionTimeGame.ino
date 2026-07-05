// C++ code
#include <LiquidCrystal.h>
	
const int user1= 9;
const int user2 = 13;
const int startGame = 11;
LiquidCrystal lcd(7,6,5,4,3,2);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.setCursor(0,0);
  lcd.print("Hello");
  lcd.setCursor(0,1);
  lcd.print("It works");
pinMode(8,OUTPUT);
pinMode(10,OUTPUT);
pinMode(12,OUTPUT);
pinMode(user1,INPUT_PULLUP);
pinMode(user2,INPUT_PULLUP);
pinMode(startGame,INPUT_PULLUP);
lcd.clear();
};
void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(startGame) == LOW) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Game starting...");
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    delay(random(2000,5000));
    digitalWrite(10,HIGH);
    int time=0;
    while (true) {
      if (digitalRead(user1) == LOW) {
        digitalWrite(8,HIGH);
        lcd.print("User 1 won!");
        break;
      } else if (digitalRead(user2) == LOW) {
          digitalWrite(12,HIGH);
        lcd.print("User 2 won!");
          break;
        }
         delay(1);
      time += 1;
         };
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(time);
    lcd.print(" ms");
  };
};
