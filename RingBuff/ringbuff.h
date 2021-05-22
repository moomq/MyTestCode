//
// Created by moomq on 2021/5/22.
//

#ifndef RINGBUFF_RINGBUFF_H
#define RINGBUFF_RINGBUFF_H

#define RINGBUFF_LEN 100
class Ringbuff {
    public:
        Ringbuff();
        ~Ringbuff();

    /*环形队列结构体*/
    typedef struct{
        int Array[RINGBUFF_LEN];
        int W;
        int R;
    }RingBuff_TypeDef;

    RingBuff_TypeDef *m_pRingBuff;

    int WriteData(RingBuff_TypeDef *pRingBuff,int *pDataIn,int len);
    int ReadData(RingBuff_TypeDef *pRingBuff,int *pDataOut,int len);

    private:
        bool isEmpty(RingBuff_TypeDef *pRingBuff);
        bool isFull(RingBuff_TypeDef *pRingBuff);
        int GetDataLen(RingBuff_TypeDef *pRingBuff);
        int Clear(RingBuff_TypeDef *pRingBuff);

};


#endif //RINGBUFF_RINGBUFF_H
