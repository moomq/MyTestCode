//
// Created by moomq on 2021/5/22.
//
#include "ringbuff.h"
#include "iostream"
using namespace std;

Ringbuff::Ringbuff() {
    m_pRingBuff = new (RingBuff_TypeDef);
    m_pRingBuff->R = 0;
    m_pRingBuff->W = 0;
}

Ringbuff::~Ringbuff() {
    delete m_pRingBuff;
}

int Ringbuff::WriteData(Ringbuff::RingBuff_TypeDef *pRingBuff, int *pDataIn, int len) {
    if(RINGBUFF_LEN-GetDataLen(pRingBuff)<len)
    {
        printf("Free BuffDataLen:%d is less than WriteLen:%d",RINGBUFF_LEN-GetDataLen(pRingBuff),len);
        return -1;
    }
    for(int i=0;i<len;i++)
    {
        pRingBuff->Array[pRingBuff->W%RINGBUFF_LEN]=pDataIn[i];
        pRingBuff->W++;
    }
    return 0;
}

int Ringbuff::ReadData(Ringbuff::RingBuff_TypeDef *pRingBuff, int *pDataOut, int len) {
    if(GetDataLen(pRingBuff)<len)
    {
        printf("BuffDataLen:%d is less than ReadLen:%d",GetDataLen(pRingBuff),len);
        return -1;
    }
    for(int i=0;i<len;i++)
    {
        pDataOut[i] = pRingBuff->Array[pRingBuff->R%RINGBUFF_LEN];
        pRingBuff->R++;
    }
    return 0;
}

bool Ringbuff::isEmpty(Ringbuff::RingBuff_TypeDef *pRingBuff) {
    if(pRingBuff->R == pRingBuff->W)
    {
        return true;
    }
    return false;
}

bool Ringbuff::isFull(Ringbuff::RingBuff_TypeDef *pRingBuff) {
    if(pRingBuff->R == pRingBuff->W-RINGBUFF_LEN)
    {
        return true;
    }
    return false;
}

int Ringbuff::GetDataLen(Ringbuff::RingBuff_TypeDef *pRingBuff) {
    return pRingBuff->W-pRingBuff->R;
}

int Ringbuff::Clear(Ringbuff::RingBuff_TypeDef *pRingBuff) {
    pRingBuff->W = 0;
    pRingBuff->R = 0;
    return 0;
}
