int ledPWM = 5;             // ledState used to set the LED
char ledDir=1;
unsigned long preMs = 0;        // will store last time LED was updated
const long interval = 30;           // interval at which to blink (milliseconds)
void setup() 
{
	pinMode(13, OUTPUT);
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
}
