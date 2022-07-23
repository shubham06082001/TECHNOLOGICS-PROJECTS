void setup() {
  // put your setup code here, to run once:
pinMode(D0,INPUT);
pinMode(D1,INPUT);
pinMode(D2,INPUT);
pinMode(D4,INPUT);
pinMode(D5,INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("D0: "+String(digitalRead(D0)));
  Serial.println("D1: "+String(digitalRead(D1)));
  Serial.println("D2: "+String(digitalRead(D2)));
  Serial.println("D3: "+String(digitalRead(D4)));
  Serial.println("D4: "+String(digitalRead(D5)));
  Serial.println("\n\n\n");
  delay(2000);
}
