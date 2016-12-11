#include <stdio.h>

#define MAX 12

int base = 4;
int last_month[MAX] = {31,29,31,30,31,30,31,31,30,31,30,31};
int dooms_month[MAX]; //4
int days[7] = {0,1,2,3,4,5,6};

void make_doomsday()
{
    int base = 1;
    int months = 0;
    
    while(months < MAX)
    {
        
        dooms_month[months] = base;
        int i;
        for(i=base; i<last_month[months]; i+=7)
        {
            
        }
        base = i-last_month[months];
        months++;
    }
    
    
}

int main(int argc, const char * argv[]) {
    
    make_doomsday();
    
//    int i;
//    for(i=0; i<MAX; i++)
//    {
//        printf("%d ", dooms_month[i]);
//    }
    int t, test_case;

    scanf("%d", &test_case);
    for(t=0; t<test_case; t++)
    {
        int m, d;
        scanf("%d %d", &m, &d);
        int result_days = 0;
        int base_days = dooms_month[m-1];
        if(base_days == 0) base_days = 30;
        
        if(d == base_days)
            result_days = base;
        else{
            int a = d;
            int b = base_days;
            if(a < b){
                int tmp = a;
                a = b;
                b = tmp;
            }
            result_days = a - b;
            
            while(result_days > 6)
            {
                a = a / 7;
                result_days = a - b;
            }
        }
        
        printf("#%d %d\n", t+1, result_days);
        
    }
    return 0;
}
