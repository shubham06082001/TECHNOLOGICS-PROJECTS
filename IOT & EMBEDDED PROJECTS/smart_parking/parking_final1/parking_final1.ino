/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Lzp8uc0Zs2Hne_nUR13MT1VGbgnvwpVp";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Shabazz";
char pass[] = "shabaz123";

WidgetLED p1(V0);
WidgetLED p2(V1);
WidgetLED p3(V2);
WidgetLED p4(V3);

#define p1_pin D0
#define p2_pin D1
#define p3_pin D2
#define p4_pin D4

#define gate D5
void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(p1_pin,INPUT);
  pinMode(p2_pin,INPUT);
  pinMode(p3_pin,INPUT);
  pinMode(p4_pin,INPUT);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  
  if(digitalRead(p1_pin)==0)
  p1.on();
  else
  p1.off();

  if(digitalRead(p2_pin)==0)
  p2.on();
  else
  p2.off();

  if(digitalRead(p3_pin)==0)
  p3.on();
  else
  p3.off();

  if(digitalRead(p4_pin)==0)
  p4.on();
  else
  p4.off();
  
  
  if((digitalRead(p1_pin)==0) and ((digitalRead(p2_pin)==0)) and((digitalRead(p3_pin)==0)) and ((digitalRead(p4_pin)==0)))
  {
    Blynk.notify("parking is full");
  }
  
}
