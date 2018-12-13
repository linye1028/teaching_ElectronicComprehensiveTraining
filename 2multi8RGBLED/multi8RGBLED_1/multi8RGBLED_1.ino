#define pin_R 10  //伪指令
#define pin_B 11
#define pin_G 12
void setup() {
  // put your setup code here, to run once:
    for(char i=2;i<=12;i++)
	{
		pinMode(i,OUTPUT);
		digitalWrite(i,HIGH);
	}
}
unsigned char LED=0x01;
char COLOR=0x00;
void loop() {
  // put your main code here, to run repeatedly:
	char i_light=0;
	while(1)
	{
		i_light++;
		if(i_light>7)
			i_light=0;
		COLOR=i_light;
        LED=1<<i_light;
		LEDout();
		delay(2);
	}
}
void LEDout()
{
	for(char i=0;i<=7;i++)
		digitalWrite(i+2,(~LED>>i)&0x01);
	for(char i=0;i<=2;i++)
		digitalWrite(i+10,(COLOR>>i)&0x01);		
}
