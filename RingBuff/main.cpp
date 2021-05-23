#include <iostream>
#include "ringbuff.h"
using namespace std;
int main() {
    Ringbuff MyRingbuff;
    int wdata[100],rdata[100];
    for(int i=0;i<100;i++)
    {
        wdata[i] = i;
    }
    MyRingbuff.WriteData(MyRingbuff.m_pRingBuff,wdata,100);

    MyRingbuff.ReadData(MyRingbuff.m_pRingBuff,rdata,100);

    for(int i : rdata)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<MyRingbuff.m_pRingBuff->R<<endl;
    cout<<MyRingbuff.m_pRingBuff->W<<endl;

    MyRingbuff.WriteData(MyRingbuff.m_pRingBuff,wdata,100);

    MyRingbuff.ReadData(MyRingbuff.m_pRingBuff,rdata,100);

    for(int i : rdata)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<MyRingbuff.m_pRingBuff->R<<endl;
    cout<<MyRingbuff.m_pRingBuff->W<<endl;

    uint64_t i;
    char c='d';
    i=0xfffffffffffff;
    printf("i:%x\r\n",i&0x1);
    cout<<"i:"<<i<<" c:"<<c<<endl;
    printf("c:%x",c);
    return 0;
}
