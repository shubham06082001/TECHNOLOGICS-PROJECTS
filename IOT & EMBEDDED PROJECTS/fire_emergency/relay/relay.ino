#define relay D7
void setup() {
  // put your setup code here, to run once:
pinMode(relay,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(relay,HIGH);//on the relay
delay(1000);
digitalWrite(relay,LOW);// off the relay
delay(1000);
}
