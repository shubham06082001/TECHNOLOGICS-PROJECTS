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
#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = "ehdd6gkTx1XESNkAEB8s1r3dg1iWxwBm";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Shabazz";
char pass[] = "shabaz123";

// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

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
#define buzzer 3
void setup(){
pinMode(sol,OUTPUT);
pinMode(motion,INPUT);
pinMode(buzzer,OUTPUT);
lcd.begin(16, 2);
delay(10);
  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  
  Blynk.begin(auth, wifi, ssid, pass);
}
String password="123ABC",s="";
void loop(){
  Blynk.run();
  char customKey = customKeypad.getKey();
  if (customKey!='#') 
  {
  if(customKey!=0){
    Serial.println(customKey);
    s=s+String(customKey);
    lcd.clear();
    lcd.print(s);
  }
  }
  else
  {
    //s=s+String('\0');
    if(s==password)
    {
      lcd.clear();
      lcd.print("valid password");
      digitalWrite(sol,HIGH);
      delay(2000);
      digitalWrite(sol,LOW);
      Blynk.notify("valid password entered");
    }
    else
    {
      lcd.clear();
      lcd.print("invalid password");
      Blynk.notify("invalid password entered");
      digitalWrite(buzzer,HIGH);
      delay(2000);
      digitalWrite(buzzer,LOW);
    }
    s="";
    lcd.clear();
    }
    if(digitalRead(motion)==1)
    {
            digitalWrite(buzzer,HIGH);
      delay(2000);
      digitalWrite(buzzer,LOW);
      delay(1000);
      Blynk.notify("motion detected");

      
    }
  }
