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
	pinMode(14,INPUT_PULLUP);
	pinMode(15,INPUT_PULLUP);
	Serial.begin(9600);
}
unsigned char LED=0x01;
char COLOR=0x01;
unsigned long preMillis=0;
int interval=500;
void loop() {
  // put your main code here, to run repeatedly:
	char i_light=0;
	char dir=1;
	char Flag_bt1=0,Flag_bt2=0;
	unsigned char RD[6];
	char RD_i=0;
	while(1)
	{	
		if(millis()-preMillis>=interval)
		{
			preMillis=millis();
			if(dir==1)
			{
				i_light++;
				if(i_light==7)
				{
					dir=0;
					COLOR++;
					if(COLOR>6)
						COLOR=0;			
				}
			}
			else if(dir==0)
			{
				i_light--;
				if(i_light==0)
				{
					dir=1;	
					COLOR++;
					if(COLOR>6)
						COLOR=0;
				}
							
			}
			LED=1<<i_light;
			LEDout();			
		}
		//up
		if( (digitalRead(14)==LOW) && (Flag_bt1==0) )
		{
			delay(5);
			if( (digitalRead(14)==LOW) && (Flag_bt1==0) )
			{
				interval=interval+100;
				if(interval>1000)
					interval=1000;
				Flag_bt1=1;		
			}

		}
		if(digitalRead(14)==HIGH)
		{
			Flag_bt1=0;
		}
		//down
		if( (digitalRead(15)==LOW) && (Flag_bt2==0) )
		{
			delay(5);
			if( (digitalRead(15)==LOW) && (Flag_bt2==0) )
			{
				interval=interval-100;
				if(interval<100)
					interval=100;
				Flag_bt2=1;		
			}

		}
		if(digitalRead(15)==HIGH)
		{
			Flag_bt2=0;
		}

		//Serial receive
		if(Serial.available()>0)
		{
			RD_temp=Serial.read();
			if(RD_temp=='m')
			{
				//数据接收完毕，处理数据，更新interval
				
				
			}
			else
			{
				RD[RD_i]=RD_temp;
				RD_i=RD_i+1;
			
			}
			
		
		}
		
		
	}
}

void LEDout()
{
	for(char i=0;i<=7;i++)
		digitalWrite(i+2,(~LED>>i)&0x01);
	for(char i=0;i<=2;i++)
		digitalWrite(i+10,(COLOR>>i)&0x01);		
}
