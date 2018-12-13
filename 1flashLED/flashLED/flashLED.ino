void setup() {
  // put your setup code here, to run once:
	pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 
	for(int i=5;i<=50;i++)
	{
		analogWrite(13,i);
		delay(20);
	}	

	for(int i=50;i>=5;i--)
	{
		analogWrite(13,i);
		delay(20);
	}	

}
