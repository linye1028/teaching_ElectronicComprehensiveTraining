#include "TM1637.h"
#define CLK 2//pins definitions for TM1637 and can be changed to other ports
#define DIO 3
#define LEFT 16
#define RIGHT 17
static int8_t TubeTab1[] = {0x3f,0x06,0x5b,0x4f,
                           0x66,0x6d,0x7d,0x07,
                           0x7f,0x6f,0x77,0x7c,
                           0x39,0x5e,0x79,0x71,//0~9,A,b,C,d,E,F,
                           0x38,0x50};//16:L,17:r

class TM1637New :public TM1637{
public:
    TM1637New(uint8_t Clk, uint8_t Data):TM1637(Clk, Data){ };
    //int8_t coding(int8_t DispData);
    void display(uint8_t BitAddr,int8_t DispData);
    
};
void TM1637New::display(uint8_t BitAddr,int8_t DispData)
{
  int8_t SegData;
  uint8_t PointData;
  //SegData = coding(DispData);
  PointData=_PointFlag<<7;
  if(DispData == 0x7f) SegData = 0x00 + PointData;  
  else SegData = TubeTab1[DispData] + PointData;
  start();          //start signal sent to TM1637 from MCU
  writeByte(ADDR_FIXED);//
  stop();           //
  start();          //
  writeByte(BitAddr|0xc0);//
  writeByte(SegData);//
  stop();            //
  start();          //
  writeByte(Cmd_DispCtrl);//
  stop();           //
}

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
