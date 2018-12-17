#include "TM1637.h"
#define CLK 2//pins definitions for TM1637 and can be changed to other ports
#define DIO 3
TM1637 tm1637(CLK,DIO);
void setup() {
  // put your setup code here, to run once:
  tm1637.init();
  tm1637.set(2);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}
int disNum=1234;
void loop() {
  // put your main code here, to run repeatedly:
    tm1637.display(0,disNum/1000%10);
    tm1637.display(1,disNum/100%10);
    tm1637.display(2,disNum/10%10);
    tm1637.display(3,disNum/1%10);
    tm1637.point(1);
}
