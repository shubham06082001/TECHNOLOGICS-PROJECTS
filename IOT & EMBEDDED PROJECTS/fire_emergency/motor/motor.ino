#define in1 D0
#define in2 D1
#define in3 D2
#define in4 D3
void setup() {
  // put your setup code here, to run once:
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
