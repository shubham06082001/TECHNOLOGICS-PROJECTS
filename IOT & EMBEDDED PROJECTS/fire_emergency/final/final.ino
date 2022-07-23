#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "ehdd6gkTx1XESNkAEB8s1r3dg1iWxwBm";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Shabazz";
char pass[] = "shabaz123";


#define buzzer D4
#define relay D6
# define gas D5
#define in1 D0
#define in2 D1
#define in3 D2
#define in4 D4
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  pinMode(gas,INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(buzzer,OUTPUT);
    Blynk.begin(auth, ssid, pass);

}
void car_forward()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);  
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void car_stop()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,HIGH);
}
void loop() {
    Blynk.run();
    car_forward();
  // put your main code here, to run repeatedly:
 if(digitalRead(gas)==0)
  {
    car_stop();
    digitalWrite(buzzer,HIGH);
    Blynk.notify("fire detected");
    digitalWrite(relay,HIGH);
    delay(2000);
    digitalWrite(relay,LOW);
    digitalWrite(buzzer,LOW);

  }
}
