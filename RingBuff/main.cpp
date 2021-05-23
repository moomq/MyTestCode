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
    return 0;
}
