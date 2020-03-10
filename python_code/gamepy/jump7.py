for i in range(1,100):
    if(i%7==0):   #7的倍数
        continue
    if(i%10==7):  #个位数是7
        continue
    elif(i//10==7): #十位数是7 取整指令
        continue
    else:
        print(i)

