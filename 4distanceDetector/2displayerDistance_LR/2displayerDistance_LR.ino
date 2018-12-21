#include "TM1637New.h"
#include "SR04.h"
#define CLK 2//pins definitions for TM1637 and can be changed to other ports
#define DIO 3
#define LEFT  16
#define RIGHT 17
#define TRIG_PIN_L 4
#define ECHO_PIN_L 5
#define TRIG_PIN_R 14
#define ECHO_PIN_R 15
#define LED 13
TM1637New tm1637(2,3);

SR04 sr04_L = SR04(ECHO_PIN_L,TRIG_PIN_L);
SR04 sr04_R = SR04(ECHO_PIN_R,TRIG_PIN_R);

int distance_L,distance_R;

void setup() {
	tm1637.init();
	tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
	Serial.begin(9600);
    pinMode(LED,OUTPUT);
}
bool Flag_RL=0,Flag_RL_finish=0;
bool Flag_dis=0,Flag_dis_finish=0;
int distance_min=0;
char LED_state=0;
unsigned long cutMs=0,preMs=0;
int interval=0;
void loop() {
	if((millis()%500<250) && (Flag_RL_finish==0))
	{
		if(Flag_RL==0) distance_L=sr04_L.Distance();
		else           distance_R=sr04_R.Distance();
		Flag_RL=!Flag_RL;
		Flag_RL_finish=1;
		if(Flag_dis==0) //显示L_distance
		{
			tm1637.display(0,LEFT);
			tm1637.display(1,distance_L/100%10);
			tm1637.display(2,distance_L/10%10);
			tm1637.display(3,distance_L/1%10);		
		}
		else //显示R_distance
		{
			tm1637.display(0,RIGHT);
			tm1637.display(1,distance_R/100%10);
			tm1637.display(2,distance_R/10%10);
			tm1637.display(3,distance_R/1%10);			
		}		
		
		
		
	}
	if(millis()%500>=250)
		Flag_RL_finish=0;

	

	if((millis()%5000<2500) && (Flag_dis_finish==0))
	{
		Flag_dis_finish=1;
		Flag_dis=!Flag_dis;
	}
	if(millis()%5000>=2500)
		Flag_dis_finish=0;
		
	distance_min=(distance_L>distance_R)? distance_R :distance_L;	 
		
	if(distance_min>=5 && distance_min<=100)
	{
        interval=(LED_state==1)? 100:distance_min*8+100;
		//cutMs=millis();
		if(millis()-preMs>=interval)
		{
			preMs=millis();
			LED_state=!LED_state;
			digitalWrite(LED,LED_state);
		}	
	}
	else if(distance_min<5)
		digitalWrite(LED,1);
	else if(distance_min>100)
		digitalWrite(LED,0);	
}
