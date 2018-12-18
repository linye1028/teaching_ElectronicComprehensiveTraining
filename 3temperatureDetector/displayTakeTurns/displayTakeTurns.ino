#include "TM1637.h"
#define CLK 2//pins definitions for TM1637 and can be changed to other ports
#define DIO 3
TM1637 tm1637(CLK,DIO);
int year=2018;
int temp100=2050;
int hhmm=1027;
char Flag_dis=0;
void setup() {
  // put your setup code here, to run once:
	tm1637.init();
	tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;    
}

void loop() {
  // put your main code here, to run repeatedly:
	Flag_dis=millis()%6000/2000;
	switch(Flag_dis)
	{
		case 0 : display4num(year); tm1637.point(0);break;
		case 1 : display4num(temp100); tm1637.point(1);break;
		case 2 : display4num(hhmm); tm1637.point(millis()%1000/500);break;
		default : break;
	}
}

void display4num(int num)
{
    tm1637.display(0,num/1000%10);
    tm1637.display(1,num/100%10);
    tm1637.display(2,num/10%10);
    tm1637.display(3,num/1%10);   
    
}
