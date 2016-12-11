#include <stdio.h>

#define max 3

int tot[max] = {700,299,499};
int data[max]={7,3,5};
int m = 8;
int i, j, k;
int ii, jj, kk;

int result;
int temp;
//int max = 0;
int value1,value2,value3 = 0;

int main(int argc, const char * argv[]) {

    for(i=m; i>=0; i-=data[0],ii++)
    {
        for(j=i; j>=0; j-=data[1],jj++)
        {
            if(j%data[2]==0){
                if(j==0){
                    temp = ii*tot[0] + jj*tot[1];
                }else{
                    kk++;
                    temp = ii*tot[0] + jj*tot[1] + kk*tot[2];
                }
                if(result < temp) result = temp;
            }
        }
    }
    printf("%d\n", result);
    return 0;
}
