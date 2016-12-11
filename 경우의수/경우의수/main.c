#include <stdio.h>

int bills[6] = {1,2,5,10,20,50}; //100만원을 만들 수 있는 모든 조합은?
int money = 100;
int count = 0;

int main(int argc, const char * argv[]) {

    int i1,i2,i3,i4,i5,i6;
    
    for(i1=money; i1>=0; i1-=bills[0])
    {
        for(i2=i1; i2>=0; i2-=bills[1])
        {
            for(i3=i2; i3>=0; i3-=bills[2])
            {
                for(i4=i3; i4>=0; i4-=bills[3])
                {
                    for(i5=i4; i5>=0; i5-=bills[4])
                    {
                        if(i5%bills[5] == 0) count++;
                    }
                }
            }
        }
    }
    printf("count = %d\n", count);
    
    return 0;
}
