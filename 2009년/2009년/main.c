#include <stdio.h>

#define M 12
#define D 7

int dday = 4;
char month[M] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dooms_days[M];
char* days[D] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int d, m;

//기준 1월 1일 : 목요일
void make_doomsday()
{
    int base = 1;
    int m;
    
    for(m=0; m<M; m++)
    {
        dooms_days[m] = base;
        
        while(base < month[m])
        {
            base += 7;
        }
        base = base - month[m];
        if(base == 0) base+=7;
    }
}

void print()
{
    int i;
    for(i=0; i<M; i++)
    {
        printf("%d : %d \n", i+1, dooms_days[i]);
    }
}

char* get_day(int d, int m)
{
    int day = dday;
    char* answer = 0;
    int pre_answer = 0;
    int dooms = dooms_days[m-1];
    //printf("dooms = %d \n", dooms);
    
    if(d == dooms){
        day = dday;
    }
    else if(d>dooms)
    {
        day=(dday+d-dooms)%7;
    }
    else if(d<dooms)
    {
        day=(dday-(dooms-d))%7;
    }
    printf("dooms = %d , day = %d \n", dooms, day);
    switch(day)
    {
        case 0:
            answer = days[0];
            break;
        case 1:
            answer = days[1];
            break;
        case 2:
            answer = days[2];
            break;
        case 3:
            answer = days[3];
            break;
        case 4:
            answer = days[4];
            break;
        case 5:
            answer = days[5];
            break;
        case 6:
            answer = days[6];
            break;
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    
    //print();
    
    scanf("%d %d", &d, &m);
    make_doomsday();
    //print();
    
    char* answer = get_day(d, m);
    
    printf("%s", answer);
    //print();
    
    return 0;
}
