#include "TM1637.h"
class TM1637New :public TM1637{
public:
    TM1637New(uint8_t Clk, uint8_t Data):TM1637(Clk, Data){ };
    //int8_t coding(int8_t DispData);
    void display(uint8_t BitAddr,int8_t DispData);
    
};
