#include "TM1637.h"
#include "TM1637New.h"
static int8_t TubeTab1[] = {0x3f,0x06,0x5b,0x4f,
                           0x66,0x6d,0x7d,0x07,
                           0x7f,0x6f,0x77,0x7c,
                           0x39,0x5e,0x79,0x71,//0~9,A,b,C,d,E,F,
                           0x38,0x50};//16:L,17:r

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
