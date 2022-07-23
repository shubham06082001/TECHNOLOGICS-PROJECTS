# define gas D2
void setup() {
  // put your setup code here, to run once:
pinMode(gas,INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(gas)==0)
  {
    Serial.println("gas detected");
    delay(5000); 
  }
}
