#include "TM1637New.h"
#define CLK 2//pins definitions for TM1637 and can be changed to other ports
#define DIO 3
#define LEFT 16
#define RIGHT 17

TM1637New tm1637(2,3);

void setup() {
	tm1637.init();
	tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop() {
    tm1637.display(0,LEFT);
    tm1637.display(1,RIGHT);
    tm1637.display(2,3);
    tm1637.display(3,4);
}
