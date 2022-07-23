#define motion 4
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(motion,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(motion));
  delay(3000);
}
