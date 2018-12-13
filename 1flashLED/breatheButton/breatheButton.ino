int ledPWM = 5;             // ledState used to set the LED
char ledDir=1;
unsigned long preMs = 0;        // will store last time LED was updated
const long interval = 30;           // interval at which to blink (milliseconds)
char Flag_bt1=0;
char LED2_state=LOW;
void setup() 
{
	pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	digitalWrite(2,HIGH);
	digitalWrite(3,HIGH);
	
}

void loop() {
	unsigned long cutMs = millis();
	if (cutMs - preMs >= interval) 
	{
		preMs = cutMs;
        if(ledDir==1)
        {
            ledPWM++;
			if(ledPWM>=40)
				ledDir=0;
        }
		if(ledDir==0)
		{
			ledPWM--;
			if(ledPWM<=1)
				ledDir=1;
		}
 		analogWrite(13, ledPWM);
	}
	
	if( (digitalRead(2)==LOW) && (Flag_bt1==0) )
	{
		delay(5);
		if( (digitalRead(2)==LOW) && (Flag_bt1==0) )
		{
			LED2_state=1-LED2_state;
			digitalWrite(12,LED2_state);
			Flag_bt1=1;		
		}

	}
	if(digitalRead(2)==HIGH)
	{
		Flag_bt1=0;
	}
}
