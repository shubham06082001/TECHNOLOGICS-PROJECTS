/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>
#include <LiquidCrystal.h>
const byte ROWS = 4; /* four rows */
const byte COLS = 4; /* four columns */
/* define the symbols on the buttons of the keypads */
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {10, 11, 12, 13}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {6, 7, 8, 9}; /* connect to the column pinouts of the keypad */

/* initialize an instance of class NewKeypad */
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
# define sol 5
# define motion 4
void setup(){
Serial.begin(9600);
pinMode(sol,OUTPUT);
pinMode(motion,INPUT);
lcd.begin(16, 2);
}
String password="123ABC",s="";
void loop(){
  char customKey = customKeypad.getKey();
  if (customKey!='#') 
  {
  if(customKey!=0){
    Serial.println(customKey);
    s=s+String(customKey);
    Serial.println("entered password:"+s);
    lcd.clear();
    lcd.print(s);
  }
  }
  else
  {
    //s=s+String('\0');
    Serial.println("entered password is "+s);
    if(s==password)
    {
      lcd.clear();
      lcd.print("valid password");
      Serial.println("valid password");
      digitalWrite(sol,HIGH);
      delay(2000);
      digitalWrite(sol,LOW);
    }
    else
    {
      lcd.clear();
      lcd.print("invalid password");
      Serial.println("invalid password");
      delay(2000);
    }
    s="";
    lcd.clear();
    }
    if(digitalRead(motion)==1)
    {
      Serial.println("motion is detected");
      delay(1000);
    }
  }
