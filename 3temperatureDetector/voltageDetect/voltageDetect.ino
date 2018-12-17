void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.println(float(analogRead(0))/204.6);
   delay(500);
}
